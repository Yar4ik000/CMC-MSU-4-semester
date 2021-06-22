#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


int main() {
    std::string left, right;
    if (!(std::cin >> left >> right)) {
        std::cout << -1 << std::endl;
        return 0;
    }
    bool cs_short = left.size() == 1 && isupper(left[0]);
    bool has_S_left = left == "S";
    bool has_S_right = std::find(right.begin(), right.end(), 'S') != right.end();
    bool has_S_eps = left == "S" && right == "_";
    bool has_eps = left != "S" && right == "_";
    bool cs_no_short = !has_eps;
    while (true) {
        bool all_terminals = true;
        for (auto c : left) {
            if (!isdigit(c) && isupper(c)) {
                all_terminals = false;
                break;
            }
        }
        if (all_terminals) {
            std::cout << -1 << std::endl;
            return 0;
        }
        if (left == "S") {
            has_S_left = true;
            if (right == "_") {
                has_S_eps = true;
            }
        }
        if (std::find(right.begin(), right.end(), 'S') != right.end()) {
            has_S_right = true;
        }
        if (left != "S" && right == "_") {
            has_eps = true;
            cs_no_short = false;
        }
        if (left.size() > right.size()) {
            cs_no_short = false;
        }
        if (left.size() != 1 || islower(left[0]) || isdigit(left[0])){
            cs_short = false;
            cs_no_short = false;
        }
        if (has_S_right && has_S_eps) {
            cs_no_short = false;
        }
        if (!(std::cin >> left >> right)) {
            break;
        }
    } 
    if (!has_S_left) {
        std::cout << -1 << std::endl;
    } else if (cs_no_short) {
        std::cout << 23 << std::endl;
    } else if (cs_short) {
        std::cout << 2 << std::endl;
    } else { 
        std::cout << 10 << std::endl;
    }
}