#include <iostream>


int main()
{
    unsigned shift; 
    while (std::cin >> std::hex >> shift) {
        for (int j = 0; j < 4; ++j) {
            unsigned num;
            unsigned number = 0;
            for (int i = 0; i < 4; ++i) {
                if(!(std::cin >> std::hex >> num)) {
                    return 0;
                } 
                number |= (num << (3 - i) * 8);
            }
            std::cout << number << std::endl;
        }
    } 
    
}