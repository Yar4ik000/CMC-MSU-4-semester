#include <cmath>


namespace Game 
{
    template <class T>
    class Coord{
    public:
        typedef T value_type;
        T row;
        T col;
        Coord(T row = T{}, T col = T{}) : row{row}, col{col} {}
    };

    template<class T>
    typename T::value_type dist(T field, T xy_0, T xy_1) {
        auto z0 = xy_0.col;
        auto x0 = xy_0.row - (xy_0.col + xy_0.col % 2) / 2;
        auto y0 = -x0 - z0; 
        auto z1 = xy_1.col;
        auto x1 = xy_1.row - (xy_1.col + xy_1.col % 2) / 2;
        auto y1 = -x1 - z1;
        return (abs(x0 - x1) + abs(y0 - y1) + abs(z0 - z1)) / 2;
    }
}
