#include <iostream>


class S{
public:
    int num{0};
    S() {
        int x;
        std::cin >> x;
        num += x;
    }
    ~S() {
        std::cout << num;
    }
    
    explicit operator bool () const noexcept { 
        return num == 0; 
    }
};


void func(S v)
{
    if (v) {
        func(std::move(v));
    }
}

int main()
{
    func(S());
}