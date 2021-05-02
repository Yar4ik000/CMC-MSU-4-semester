#include <iostream>
#include <vector>
#include <array>
#include <complex>
#include <cmath>


namespace Equations {

    template <class T>
    std::pair<bool, std::vector<std::complex<T>>> quadratic(std::array<std::complex<T>, 3> args) {
        if (std::norm(args[0]) == 0 && std::norm(args[1]) == 0 && std::norm(args[2]) == 0) {
            return std::make_pair(false, std::vector<std::complex<T>>{});
        }
        if (std::norm(args[2]) == 0) {
            if (std::norm(args[1]) == 0) {
                return std::make_pair(true, std::vector<std::complex<T>>{});
            }

            return std::make_pair(true, std::vector<std::complex<T>>{-args[0] / args[1]});
        }
        auto d = args[1] * args[1] - args[0] * args[2] * static_cast<T>(4);
        auto sqr = std::sqrt(d);
        std::vector<std::complex<T>> ans = {(-args[1] + sqr) / (args[2] * static_cast<T>(2)), 
        (-args[1] - sqr) / (args[2] * static_cast<T>(2))};
        return std::make_pair(true, ans);
    }
}
