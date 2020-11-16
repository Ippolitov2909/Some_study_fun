#include <iostream>

namespace Game {
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
    value_type dist (Coord<value_type> shape, Coord<value_type> first, Coord<value_type> second)
    {
        if (first.col > second.col) {
            std::swap (first, second);
        }
        value_type res = abs(first.row - second.row) + abs(first.col - second.col);
        value_type mmin = mymax(first.row - second.row, first.col - second.col);
        for (value_type i = first.col; i < second.col && res > mmin; i++) {
            if (first.row < second.row && i % 2 == 0) {
                res--;
            } else if (first.row > second.row && i % 2 == 1) {
                res--;
            }
        }
        return res;
    }
}
