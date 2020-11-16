#include <iostream>
#include <complex>
#include <array>
#include <vector>
#include <utility>
namespace Equations {
    template <typename value_type>
    std::pair<bool, std::vector<std::complex<value_type>>> quadratic(std::array<std::complex<value_type>, 3> coeffs) {
        std::complex<value_type> a = coeffs[2];
        std::complex<value_type> b = coeffs[1];
        std::complex<value_type> c = coeffs[0];
        std::complex<value_type> null (0, 0);
        std::vector<std::complex<value_type>> res = {};
        if (a == null) {
            if (b == null) {
                if (c == null) {
                    return std::pair<bool, std::vector<std::complex<value_type>>>(false, res);
                }
                return std::pair<bool, std::vector<std::complex<value_type>>>(true, res);
            }
            res.push_back(-c/b);
            return std::pair<bool, std::vector<std::complex<value_type>>>(true, res);
        } else {
            std::complex<value_type> sq_diskr = std::sqrt(b * b - std::complex<value_type>(4, 0) * a * c);
            res.push_back((-b + sq_diskr) / (std::complex<value_type>(2, 0) * a));
            res.push_back((-b - sq_diskr) / (std::complex<value_type>(2, 0) * a));
            return std::pair<bool, std::vector<std::complex<value_type>>>(true, res);
        }
    }
}
