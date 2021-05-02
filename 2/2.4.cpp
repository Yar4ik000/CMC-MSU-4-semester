#include <iostream>


int main()
{
    char sym_prev, sym_now;
    int count = 1;
    if (!(std::cin >> std::noskipws >> sym_prev)) {
        return 0;
    }
    while (std::cin >> std::noskipws >> sym_now) {
        if (sym_now == sym_prev) {
            count++;
        } else if (sym_prev == '#') {
            std::cout << "##" << std::hex << count << '#';
            count = 1;
            sym_prev = sym_now;
        } else if (count <= 4) {
            std::cout << std::string(count, sym_prev);
            count = 1;
            sym_prev = sym_now;
        } else {
            std::cout << '#' << sym_prev << std::hex << count << '#';
            count = 1;
            sym_prev = sym_now;
        }
    }
    if (sym_prev == '#') {
        std::cout << "##" << std::hex << count << '#';
    } else if (count <= 4) {
        std::cout << std::string(count, sym_prev);
    } else {
        std::cout << '#' << sym_prev << std::hex << count << '#';
    }
}