#include <vector>
#include <cmath>

template <class T>
class Coord{
public:
    typedef T value_type;
    T row;
    T col;
    /*Сoord() : row{T{}}, col{T{}} {}
    Coord(T row) : row{row}, col{row}*/
    Coord(T row = T{}, T col = T{}) : row{row}, col{col} {}
};


template<class R>
R func(R a, R b, R c, R d) {
    return std::max(std::abs(b - a), std::abs(d - c));
}


template <class T>
typename T::value_type dist(T field, T xy_0, T xy_1) {
    xy_0.row += field.col;
    xy_1.row += field.col;
    xy_0.col += field.row;
    xy_1.col += field.row;
    std::vector<typename T::value_type> ans(5);
    ans[0] = std::min(func(xy_0.row, xy_1.row + field.row, xy_0.col, xy_1.col), 
    func(xy_0.row, xy_1.row + field.row, xy_0.col, xy_1.col + field.col));
    ans[1] = std::min(func(xy_0.row, xy_1.row, xy_0.col, xy_1.col + field.col), 
    func(xy_0.row, xy_1.row - field.row, xy_0.col, xy_1.col + field.col));
    ans[2] = std::min(func(xy_0.row, xy_1.row - field.row, xy_0.col, xy_1.col), 
    func(xy_0.row, xy_1.row - field.row, xy_0.col, xy_1.col - field.col));
    ans[3] = std::min(func(xy_0.row, xy_1.row, xy_0.col, xy_1.col - field.col), 
    func(xy_0.row, xy_1.row + field.row, xy_0.col, xy_1.col - field.col));
    ans[4] = std::min(ans[0], ans[1]);
    ans[4] = std::min(ans[2], ans[4]);
    ans[4] = std::min(ans[3], ans[4]);
    ans[4] = std::min(ans[4], func(xy_0.row, xy_1.row, xy_0.col, xy_1.col));
    return ans[4];
}