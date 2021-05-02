#include <iostream>
#include <iomanip>
#include <cmath>


int main(){
    int n = 0;
    double average_sum = 0;
    double average_sqrt_sum = 0;
    double value;
    while (std::cin >> value) {
        n++;
        average_sum += value;
        average_sqrt_sum = average_sqrt_sum + value * value;
    }
    double average = average_sum / n;
    double average_sqrt = sqrt((average_sqrt_sum - 2 * average * average_sum + n * average * average) / n);
    std::cout << std::setprecision(10) << average << std::endl << std::setprecision(10) <<
    average_sqrt << std::endl;
}