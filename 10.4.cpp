#include <iostream>


void X(int n, int m);
void Y(int m);
void S(int n, int m);


void S(int n, int m) {
    std::cout << 'a';
    X(n - 1, m);
    std::cout << 'd';
}


void X(int n, int m) {
    if (n) {
        std::cout << 'a';
        X(n - 1, m);
        std::cout << 'd';
    } else {
        std::cout << 'b';
        Y(m - 1);
        std::cout << 'c';
    }
}


void Y(int m) {
    if (m) {
        std::cout << 'b';
        Y(m - 1);
        std::cout << 'c';
    }
}


int main() {
    int k;
    std::cin >> k;
    if (k % 2 || k < 4) {
        return 0;
    }
    for (int i = k / 2 - 1; i >= 1; --i) {
        S(i, k / 2 - i);
        std::cout << std::endl;
    }
}