#include <map>
#include <iostream>


enum {modul = 4294967161};


int main() {
    std::map<unsigned, std::map<unsigned, unsigned long long>> matrix1, matrix2;
    unsigned x, y;
    unsigned long long num;
    bool next_matrix = false;
    while (std::cin >> x >> y >> num) {
        if (next_matrix) {
            matrix2[y][x] = num;
        } else {
            if (x == 0 && y == 0 && num == modul) {
                next_matrix = true;
                continue;
            }
            matrix1[x][y] = num;
        }
    }
    for (auto& [i, map_i] : matrix1) {
        for (auto& [j, map_j] : matrix2) {
            unsigned long long sum = 0;
            auto iter1 = map_i.begin();
            auto iter2 = map_j.begin();
            while (iter1 != map_i.end() && iter2 != map_j.end()) {
                if ((*iter1).first > (*iter2).first) {
                    while (iter2 != map_j.end() && (*iter1).first > (*iter2).first) {
                        iter2++;
                    }
                    if (iter2 == map_j.end()) {
                        break;
                    }
                } else if ((*iter1).first < (*iter2).first) {
                    while (iter1 != map_i.end() && (*iter1).first < (*iter2).first) {
                        iter1++;
                    }
                    if (iter1 == map_i.end()) {
                        break;
                    }
                } else {
                    sum = (sum + ((*iter1).second * (*iter2).second) % modul) % modul;
                    ++iter1, ++iter2;
                }
            }
            if (sum) {
                std::cout << i << ' ' << j << ' ' << sum << std::endl;
            }
        }
    }
}