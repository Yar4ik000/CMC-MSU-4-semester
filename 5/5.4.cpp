#include <vector>
#include <algorithm>


template<class It1, class It2>
It2 myremove(It1 it1_beg, It1 it1_end, It2 it2_beg, It2 it2_end) {
    std::vector<int> index;
    for (auto it = it1_beg; it != it1_end; ++it) {
        index.push_back(*it);
    }
    std::sort(index.begin(), index.end());
    auto last = std::unique(index.begin(), index.end());
    index.erase(last, index.end());
    auto it = index.begin();
    while (it != index.end() && *it < 0) {
        ++it;
    }
    if (it == index.end()) {
        return it2_end;
    }
    auto iter = it2_beg;
    auto iter_end = it2_beg;
    int size2 = 0;
    while (iter != it2_end) {
        ++iter, ++size2;
    }
    iter = it2_beg;
    int len = 0;
    int iter_num = 0;
    while (iter_num + len < size2) {
        if (it != index.end() && *it == iter_num + len) {
            do {
                ++it, ++len, ++iter_end;
            } while (it != index.end() && *it == iter_num + len);
            std::swap(*iter, *(iter_end));
        } else {
            std::swap(*iter, *(iter_end));
        }
        ++iter, ++iter_end, ++iter_num;
    }           
    return iter;
}