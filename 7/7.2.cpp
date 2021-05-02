#include <sstream>
#include <string>
#include <cmath>
#define _USE_MATH_DEFINES


class Rectangle : Figure{
public:
    Rectangle(double a = 0, double b = 0) : a{a}, b{b} {}
    static Rectangle* make(std::string str) {
        std::istringstream s_str(str);
        double a_, b_;
        s_str >> a_ >> b_;
        return new Rectangle(a_, b_);
    }
    
    double get_square() const noexcept override { return a * b; }
private:
    double a{}, b{};
};


class Square : Figure{
public:
    Square(double a = 0) : a{a} {}
    static Square* make(std::string str) {
        std::istringstream s_str(str);
        double a_;
        s_str >> a_;
        return new Square(a_);
    }

    double get_square() const noexcept override { return a * a; }
private:
    double a{};
};


class Circle : Figure{
public:
    Circle(double r = 0) : r{r} {}
    static Circle* make(std::string str) {
        std::istringstream s_str(str);
        double r_;
        s_str >> r_;
        return new Circle(r_);
    }

    double get_square() const noexcept override { return M_PI * r * r; }
private:
    double r{};
};