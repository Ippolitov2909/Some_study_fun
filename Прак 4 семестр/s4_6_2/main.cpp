#include <iostream>
#include <math.h>
constexpr int SIZE = 9;
template <typename value_type>
value_type mymax (value_type a, value_type b)
{
    if (abs(a) >= abs(b)) {
        return abs(a);
    }
    return abs(b);
}
template <typename value_type>
class Coord {
public:
    explicit Coord(value_type row = 0, value_type col = 0) : row(row), col(col) {};
    value_type row, col;
};

template <typename value_type>
value_type dist (Coord<value_type> sizes, Coord<value_type> first, Coord<value_type> second)
{
    value_type arr[SIZE];
    arr[0] = mymax(first.row - second.row, first.col - second.col);
    arr[1] = mymax(first.row - second.row + sizes.row, first.col - second.col);
    arr[2] = mymax(first.row - second.row - sizes.row, first.col - second.col);
    arr[3] = mymax(first.row - second.row, first.col - second.col + sizes.col);
    arr[4] = mymax(first.row - second.row + sizes.row, first.col - second.col + sizes.col);
    arr[5] = mymax (first.row - second.row - sizes.row, first.col - second.col + sizes.col);
    arr[6] = mymax(first.row - second.row, first.col - second.col - sizes.col);
    arr[7] = mymax(first.row - second.row + sizes.row, first.col - second.col - sizes.col);
    arr[8] = mymax(first.row - second.row - sizes.row, first.col - second.col - sizes.col);
    value_type res = arr[0];
    for (int i = 1; i < SIZE; i++) {
        if (res > arr[i]) {
            res = arr[i];
        }
    }
    return res;
}


