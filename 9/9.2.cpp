#include <iostream>

// Используется рекурсивный конструктор, который вычисляет 
// результат функции по правилам из условия
// Собственно этот класс и ловится потом в main, 
// там же уже выводится его поле res.
class Result {
public:
    Result(long long a, long long b, unsigned k) {
        if (k == 0) {
            res = a + b;
        } else if (k > 0 && b == 1) {
            res = a;
        } else if (k > 0 && b > 1) {
            res = Result(a, Result(a, b - 1, k).res, k - 1).res;
        }
    }
    long long res;
};


void func(long long a, long long b, unsigned k) {
    throw Result(a, b, k);
}


int main() {
    long long a, b;
    unsigned k;
    while(std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result d) {
            std::cout << d.res << std::endl;
        }
    }
}