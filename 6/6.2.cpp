#include <vector>
#include <iostream>


enum {modul = 4294967161};

int main() {
    std::vector<std::vector<unsigned long long>> matrix;
    unsigned x, y;
    unsigned long long num;
    while (std::cin >> x >> y >> num) {
        if (x == 0 && y == 0 && num == 4294967161) continue;
        if (x >= matrix.size()) {
            while (matrix.size() <= x) {
                std::vector<unsigned long long> help;
                matrix.push_back(help);
            }
        }
        if (y >= matrix[x].size()) {
            while (matrix[x].size() <= y) {
                matrix[x].push_back(0);
            }
        }
        matrix[x][y] = (matrix[x][y] + num) % modul;
    }
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j]) std::cout << i << ' ' << j << ' ' << matrix[i][j] << std::endl;
        }
    }
}