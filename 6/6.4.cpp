#include <iterator>
#include <functional>


template <typename T>
using value_type = typename std::iterator_traits<T>::value_type;


template<class It1, class It2, 
    class Mul = std::function<value_type<It1>(value_type<It1>, value_type<It2>)>, 
    class Add = std::function<value_type<It1>(value_type<It1>, value_type<It2>)>>
auto scalar_mul(It1 Ibeg, It1 Iend, It2 I2, value_type<It1> Init = value_type<It1>{}, 
    Mul MulF = [](value_type<It1> a, value_type<It2> b) 
        {
            return a * b;
        }, 
    Add AddF = [](value_type<It1> a, value_type<It2> b)
        {
            return a + b;
        }
    ) 
{   
    value_type<It1> res = Init;
    for (auto iter = Ibeg ; iter != Iend; ++iter) {
        res = AddF(MulF(*iter, *I2), res);
        ++I2;
    }
    return res;
}
