#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <map>
#include <functional>
#include <vector>


namespace numbers {


    class complex {
    private:
        double re_;
        double im_;
    public:
        complex(double re = 0, double im = 0) : re_{re}, im_{im} {}
        explicit complex(std::string str) {
            sscanf(str.c_str(), "(%lf,%lf)", &re_, &im_);
        }

        double re() const {
            return re_;
        }

        double im() const {
            return im_;
        }

        double abs2() const {
            return re_ * re_ + im_ * im_;
        }

        double abs() const {
            return sqrt(this->abs2());
        }

        complex& operator+= (complex other) {
            im_ += other.im_;
            re_ += other.re_;
            return *this;
        }

        complex& operator-= (complex other) {
            im_ -= other.im_;
            re_ -= other.re_;
            return *this;
        }

        complex& operator*= (complex other) {
            double help = re_ * other.im_ + other.re_ * im_;
            re_ = re_ * other.re_ - im_ * other.im_;
            im_ = help;
            return *this;
        }

        complex& operator/= (complex other) {
            double help = (re_ * other.re_ + im_ * other.im_) / (other.im_ * other.im_ + other.re_ * other.re_);
            im_ = (im_ * other.re_ - re_ * other.im_) / (other.im_ * other.im_ + other.re_ * other.re_);
            re_ = help;
            return *this;
        }

        friend complex operator-(complex x) noexcept {
            return complex(-x.re_, -x.im_);
        }

        friend complex operator~ (complex x) noexcept {
            return complex(x.re_, -x.im_);
        }

        std::string to_string() const {
            std::stringstream stream;
            stream << std::setprecision(10) << '(' << re_ << ',' << im_ << ')';
            return stream.str();
        }

    };

    inline complex operator+ (complex x, complex y) {
        x += y;
        return x;
    }

    inline complex operator- (complex x, complex y) {
        x -= y;
        return x;
    }

    inline complex operator* (complex x, complex y) {
        x *= y;
        return x;
    }

    inline complex operator/ (complex x, complex y) {
        x /= y;
        return x;
    }


    class complex_stack {
    private:
        size_t count;
        complex *head;
        size_t len;

    public:
        complex_stack() : count{0}, len{10} {
            head = new complex[10];
        }

        complex_stack(const complex_stack& copy) : count{copy.get_count()}, len{copy.get_len()} {
            head = new complex[len];
            for (size_t i = 0; i < count; ++i) {
                head[i] += copy[i];
            }
        }

        ~complex_stack() {
            delete[] head;
        }

        size_t size() const {
            return count;
        }

        complex operator[] (size_t index) const {
            return head[index];
        }

        size_t get_count() const {
            return count;
        }

        size_t get_len() const {
            return len;
        }

        void inc_count() {
            ++count;
        }

        void dec_count() {
            --count;
        }

        complex *get_head() const {
            return head;
        }

        void increase_len() {
            complex *new_head = new complex[len * 2];
            for (size_t i = 0; i < count; ++i) {
                new_head[i] += head[i];
            }
            delete[] head;
            head = new_head;
            len *= 2;
        }

        complex_stack& operator= (complex_stack other) {
            delete[] head;
            head = new complex[other.get_len()];
            len = other.get_len();
            count = other.get_count();
            for (size_t i = 0; i < count; ++i) {
                head[i] += other[i];
            }
            return *this;
        } 
    

        friend complex operator+ (const complex_stack& stack){
            return stack[stack.get_count() - 1];
        }

        friend complex_stack operator~ (const complex_stack& stack){
            complex_stack new_stack = stack;
            new_stack.dec_count();
            return new_stack;
        }
    };

    inline complex_stack operator<< (complex_stack stack, complex number) {
        if (stack.get_count() == stack.get_len()) {
            stack.increase_len();
        }
        stack.get_head()[stack.get_count()] = number;
        stack.inc_count();
        return stack;
    }

    void print_st(complex_stack st)
    {
        for (size_t i = 0; i < st.size(); ++i) {
            std::cout << st[i].to_string() << std::endl;
        }
    }

    static std::map<std::string, std::function<void(complex_stack&)>> op_to_func
    {
        {"!", [](complex_stack& stack) 
                {
                    stack = stack << stack[stack.size() - 1];
                }
        },
        {";", [](complex_stack& stack)
                {
                    stack = ~stack;
                }
        },
        {"~", [](complex_stack& stack)
                {
                    complex help = stack[stack.size() - 1];
                    stack = ~stack << ~help;
                }
        },
        {"#", [](complex_stack& stack)
                {
                    complex help = stack[stack.size() - 1];
                    stack = ~stack << -help;
                }
        },
        {"+", [](complex_stack& stack) 
                {
                    complex second = stack[stack.size() - 1];
                    stack = ~stack;
                    complex first = stack[stack.size() - 1];
                    stack = ~stack << (first + second);

                }
        },
        {"-", [](complex_stack& stack)
                {
                    complex second = stack[stack.size() - 1];
                    stack = ~stack;
                    complex first = stack[stack.size() - 1];
                    stack = ~stack << (first - second);
                }
        },
        {"/", [](complex_stack& stack)
                {
                    complex second = stack[stack.size() - 1];
                    stack = ~stack;
                    complex first = stack[stack.size() - 1];
                    stack = ~stack << (first / second);
                }
        },
        {"*", [](complex_stack& stack)
                {
                    complex second = stack[stack.size() - 1];
                    stack = ~stack;
                    complex first = stack[stack.size() - 1];
                    stack = ~stack << (first * second);
                }
        }
    };

    

    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        complex_stack stack;
        for (const auto& arg : args) {
            if (arg[0] == '(') {
                complex number(arg);
                stack = stack << number;
            } else if (arg == "z") {
                stack = stack << z;
            } else {
                op_to_func[arg](stack);
            }
        }
        return stack[stack.size() - 1];
    }

    
}

 
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
        numbers::complex z0(r * cos(angle), r * sin(angle));
        numbers::complex z1(r * cos(angle + grad_measure * 2), r * sin(angle + grad_measure * 2));
        numbers::complex z(r * cos(angle + grad_measure), r * sin(angle + grad_measure));
        integral += numbers::eval(func, z) * (z1 - z0);
        angle += grad_measure * 2;
    }
    std::cout << integral.to_string() << std::endl;
}