#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
    double a;
    double sum = 0, sumsqr = 0, n = 0;
    while (std::cin >> a) {
        sum += a;
        sumsqr += a * a;
        ++n;
    }
    sum /= n;
    sumsqr /= n;
    std::cout << std::setprecision(10) << sum << '\n' ;
    std::cout << std::setprecision(10) << sqrt(sumsqr - sum * sum) << std::endl;
    return 0;
}
