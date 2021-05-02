#define _USE_MATH_DEFINES
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <map>
#include <functional>
#include <vector>


int main(int argc, char *argv[])
{
    numbers::complex c(argv[1]);
    int n;
    double r;
    std::stringstream(argv[2]) >> r;
    std::stringstream(argv[3]) >> n;
    std::vector<std::string> func;
    for (int i = 4; i < argc; ++i) {
        func.push_back(argv[i]);
    }
    double grad_measure = M_PI / n;
    double angle = 0;
    numbers::complex integral;
    for (int i = 0; i < n; ++i) {
        numbers::complex z0(r * cos(angle) + c.re(), r * sin(angle) + c.im());
        numbers::complex z1(r * cos(angle + grad_measure * 2) + c.re(), r * sin(angle + grad_measure * 2) + c.im());
        numbers::complex z(r * cos(angle + grad_measure) + c.re(), r * sin(angle + grad_measure) + c.im());
        integral += numbers::eval(func, z) * (z1 - z0);
        angle += grad_measure * 2;
    }
    std::cout << integral.to_string() << std::endl;
}
