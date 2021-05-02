#include <vector>
#include <iostream>
#include <algorithm>


void process(const std::vector<int>& v1, std::vector<int>& v2) {
    if (v1.empty() || v2.empty())
        return;
    std::vector<int> v = v1;
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
    int size = v2.size();
    v2.reserve(2 * size);
    auto it2 = v.begin();
    while (it2 != v.end() && *it2 < 0) {
        ++it2;
    }
    for (auto it = v2.begin(); it != v2.begin() + size; ++it) {
        if (it2 == v.end() || it - v2.begin() != *it2) {
            v2.emplace_back(*it);
        } else if (it2 != v.end()) {
            ++it2;
        }
    }
    v2.erase(v2.begin(), v2.begin() + size);
}

