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


    static std::map<std::string, std::function<void(complex_stack&)>> op_to_func
    {
        {"!", [](complex_stack& stack) 
            { 
                stack = stack << stack[stack.size() - 1];}
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
