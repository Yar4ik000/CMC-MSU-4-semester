#include <vector>
#include <iostream>


void process(std::vector<long long>& vec, long long ceiling) {
    if (vec.empty())
        return;
    vec.reserve(2 * vec.size());
    for (auto it = vec.end() - 1; it >= vec.begin(); --it) {
        if (*it >= ceiling) {
            vec.push_back(*it);
        }
    }
}
