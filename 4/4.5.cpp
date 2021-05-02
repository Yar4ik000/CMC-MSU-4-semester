#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>


int main(){
    std::string line;
    std::vector<std::vector<unsigned>> constitution;
    std::map<unsigned, std::set<std::string>> maximum;
    for (int i = 0; ; ++i){
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        std::vector<unsigned> new_line;
        unsigned num;
        std::stringstream ints_from_str(line);
        int j = 0;
        while (ints_from_str >> num) {
            new_line.emplace_back(num);
            std::stringstream key;
            key << i << ' ' << j;
            ++j;
            maximum[num].insert(key.str());
        }
        constitution.emplace_back(new_line);
    }
    std::vector<unsigned> amends;
    unsigned num;
    while(std::cin >> num) {
        amends.emplace_back(num);
    }
    std::sort(amends.begin(), amends.end(), [](unsigned a, unsigned b) {
        return a > b;
    });
    for (const auto amend : amends) {
        auto it = maximum.rbegin();
        int x, y;
        std::stringstream(*((*it).second.begin())) >> x >> y;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (i < 0 || i >= static_cast<int>(constitution.size()) || j < 0 || 
                j >= static_cast<int>(constitution[i].size())) {
                    continue;
                }
                unsigned value = constitution[i][j];
                if (i == x && j == y) {
                    constitution[i][j] -= constitution[i][j] <= amend ? constitution[i][j] : amend;
                } else if ((i + j) % 2 == (x + y) % 2) {
                    constitution[i][j] -= constitution[i][j] <= amend / 4 ? constitution[i][j] : amend / 4;
                } else {
                    constitution[i][j] -= constitution[i][j] <= amend / 2 ? constitution[i][j] : amend / 2;
                }
                if (value != constitution[i][j]) {
                    std::stringstream to_delete;
                    to_delete << i << ' ' << j;
                    maximum[value].erase(to_delete.str());
                    maximum[constitution[i][j]].insert(to_delete.str());
                    if (maximum[value].size() == 0) {
                        maximum.erase(value);
                    }
                }
            }
        }


    }
    for (const auto& vec : constitution) {
        int j = 0;
        for (const auto& i : vec) {
            std::cout << i;
            if (j != (int)vec.size() - 1) {
                std::cout << ' ';
            }
            j++;
        }
        std::cout << std::endl;
    }
}