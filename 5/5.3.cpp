#include <functional>
#include <vector>
#include <iostream>


template<class FwdIt, class F>
void myapply(FwdIt start, FwdIt finish, F func) {
    for (auto it = start; it != finish; ++it) {
        func(*it);
    }
}


template<class FwdIt, class P>
std::vector<std::reference_wrapper<typename FwdIt::value_type>> myfilter2(FwdIt start, FwdIt finish, P predicat) {
    std::vector<std::reference_wrapper<typename FwdIt::value_type>> res;
    for (auto it = start; it != finish; ++it) {
        if (predicat(*it)) {
            res.push_back(std::reference_wrapper(*it));
        }
    }
    return res;
}

template<class T, class P>
std::vector<std::reference_wrapper<T>> myfilter2(T *start, T *finish, P predicat) {
    std::vector<std::reference_wrapper<T>> res;
    for (auto it = start; it != finish; ++it) {
        if (predicat(*it)) {
            res.push_back(std::reference_wrapper(*it));
        }
    }
    return res;
}
