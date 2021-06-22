#include <iostream>
#include <cctype>


int main() {    
    char c;
    bool normal_read;
    while (std::cin >> std::skipws >> c) {
        if (c != '0') {
            while ((normal_read = static_cast<bool>(std::cin >> std::noskipws >> c)) && !isspace(c)) {}
            std::cout << 0 << std::endl;
            if (normal_read) {
                continue;
            } else {
                return 0;
            }
        }
        int len0 = 1, len1 = 1;
        while (std::cin >> std::noskipws >> c && c == '0') {
            len0++;
        }
        if (isspace(c)) {
            std::cout << 0 << std::endl;
            continue;
        }
        if (c != '1') {
            while ((normal_read = static_cast<bool>(std::cin >> std::noskipws >> c)) && !isspace(c)) {}
            std::cout << 0 << std::endl;
            if (normal_read) {
                continue;
            } else {
                return 0;
            }
        }
        while ((normal_read = static_cast<bool>(std::cin >> std::noskipws >> c)) && c == '1') {
            len1++;
        }
        if (!normal_read) {
            std::cout << 1 << std::endl;
            return 0;
        }
        if (isspace(c)) {
            std::cout << 1 << std::endl;
            continue;
        }
        if (c != '0') {
            while ((normal_read = static_cast<bool>(std::cin >> std::noskipws >> c)) && !isspace(c)) {}
            std::cout << 0 << std::endl;
            if (normal_read) {
                continue;
            } else {
                return 0;
            }
        }
        bool check = true;
        while (true) {
            int now0 = 1, now1 = 1;
            while ((normal_read = static_cast<bool>(std::cin >> std::noskipws >> c)) && c == '0') {
                now0++;
            }
            if (!normal_read) {
                std::cout << 0 << std::endl;
                return 0;
            }
            if (len0 != now0) {
                while ((normal_read = static_cast<bool>(std::cin >> std::noskipws >> c)) && !isspace(c)) {}
                std::cout << 0 << std::endl;
                if (normal_read) {
                    check = false;
                    break;
                } else {
                    return 0;
                }
            }
            while ((normal_read = static_cast<bool>(std::cin >> std::noskipws >> c)) && c == '1') {
                now1++;
            }
            if (!normal_read) {
                std::cout << (len1 == now1 ? 1 : 0) << std::endl;
                return 0;
            }
            if (len1 != now1) {
                while ((normal_read = static_cast<bool>(std::cin >> std::noskipws >> c)) && !isspace(c)) {}
                std::cout << 0 << std::endl;
                if (normal_read) {
                    check = false;
                    break;
                } else {
                    return 0;
                };
            }
            if (isspace(c)) {
                break;
            }
        }
        if (check) {
            std::cout << 1 << std::endl;
        }
    }
}