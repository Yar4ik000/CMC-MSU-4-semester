#include <iostream>


class Stack {
    std::string str;
public:
    Stack() {
        if(!(std::cin >> str)) {
            throw 1;
        }
    }
    ~Stack() {
        std::cout << str << std::endl;
    }
    
private:
    
};


void scan() {
    Stack help;
    scan();
}


int main() {
    try {
        scan();
    } catch(int x) {}
}
