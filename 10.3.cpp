// (a^n 0^k b^n 1^k, k,n > 0)


#include <iostream>
#include <string>
#include <array>
#include <algorithm>


int main() {
    std::string str;
    std::array<char, 4> lang = {'a', '0', 'b', '1'};
    while (std::cin >> str) {
        int n = 0, k = 0;
        size_t i = 0;
        while (i < str.size() && str[i] == 'a') {
            n++;
            i++;
        }
        if (n == 0) {
            std::cout << 0 << std::endl;
            continue;
        }
        if (i == str.size() || std::find(lang.begin(), lang.end(), str[i]) == lang.end()) {
            std::cout << 0 << std::endl;
            continue;
        }
        while (i < str.size() && str[i] == '0') {
            k++;
            i++;
        }
        if (k == 0) {
            std::cout << 0 << std::endl;
            continue;
        }
        if (i == str.size() || std::find(lang.begin(), lang.end(), str[i]) == lang.end()) {
            std::cout << 0 << std::endl;
            continue;
        }
        while (i < str.size() && str[i] == 'b') {
            n--;
            i++;
        }
        if (i == str.size() || std::find(lang.begin(), lang.end(), str[i]) == lang.end() || n) {
            std::cout << 0 << std::endl;
            continue;
        }
        while (i < str.size() && str[i] == '1') {
            k--;
            i++;
        }
        if (i != str.size() || k) {
            std::cout << 0 << std::endl;
            continue;
        }
        std::cout << 1 << std::endl;
    }
}