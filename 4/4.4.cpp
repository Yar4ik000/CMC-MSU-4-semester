#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Normalise
{
    void operator() (double n) {
        sum += n;
        count++;
    }
    double sum{0};
    int count{0};
};


int main(){
    std::vector<double> choose;
    double num;
    while (std::cin >> num) {
        choose.push_back(num);
    }
    int del1 = static_cast<int> (choose.size() * 0.1);
    std::sort(choose.begin() + del1, choose.end() - del1);
    int del2 = static_cast<int> ((choose.size() - 2 * del1) * 0.1);
    Normalise norm = std::for_each(choose.begin() + del1 + del2, choose.end() - del1 - del2, Normalise());
    std::cout << std::setprecision(10) << std::fixed << norm.sum / norm.count << std::endl;
}
