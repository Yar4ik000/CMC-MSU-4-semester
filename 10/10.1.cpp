#include <iostream>
#include <string>


int main() {
    std::string str;
    while (std::cin >> str) {
        bool one_tow = false;
        bool check = true;
        for (const auto& ch : str) {
            if (one_tow) {
                if (ch != '1' && ch != '2') {
                    std::cout << 0 << std::endl;
                    check = false;
                    break;
                }
            } else {
                if (ch != '3' && ch != '4') {
                    if (ch == '1' || ch == '2') {
                        one_tow = true;
                    } else {
                        std::cout << 0 << std::endl;
                        check = false;
                        break;
                    }
                }
            }
        }
        if (check) {
            std::cout << 1 << std::endl;
        }
    }
}
