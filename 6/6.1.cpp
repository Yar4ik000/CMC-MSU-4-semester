#include <iostream>
#include <vector>
#include <iomanip>


int main(){
    unsigned w1, w2, voices;
    std::cin >> w1 >> w2;
    int likes = 0;
    unsigned people = 0;
    while (std::cin >> voices) {
        for (unsigned i = 0; i < 32; ++i) {
            if (voices & (1u << i)) {
                likes++;
            }
        }
        people += 32;
    }
    double min_, max_;
    max_ = likes + w1 >= people ? 1 : -1 + 2 * static_cast<double>(likes + w1) / people;
    min_ = likes - static_cast<int>(w2) <= 0 ? -1 : -1 + 2 * static_cast<double>(likes - w2) / people;   
    std::cout << std::setprecision(10) <<  min_ << ' ' << max_ << std::endl;
}
