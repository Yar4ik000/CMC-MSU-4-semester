#include <iostream>


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    char sym;
    char prev = 'a';
    while (std::cin >> std::noskipws >> sym) {
        if (sym != '0' || isdigit(prev)){
            std::cout << sym;
        } else {
            while (std::cin >> std::noskipws >> sym && sym == '0') {}
            if (!isdigit((unsigned) sym)) {
                std::cout << '0';
            }
            std::cout << sym;
        }
        prev = sym;
    }
}
