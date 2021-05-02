#include <vector>
#include <iostream>


void process(const std::vector<unsigned long long>& first, std::vector<unsigned long long>& second, int param) {
    if (first.empty() || second.empty())
        return;
    auto it2 = second.end() - 1;
    for (auto it = first.begin(); it < first.end() && it2 >= second.begin(); it += param, --it2) {
        *it2 += *it;
    }
}

int main(){
    std::vector<unsigned long long> a = {1, 2, 3, 4, 5};
    std::vector<unsigned long long> b = {0, 0, 0, 0, 0};
    process(a, b, 10);
    for (const auto & q : b) {
        std::cout << q << " ";
    }
}
