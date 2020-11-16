#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
struct Sum {
    double s = 0;
    size_t n_nums;
    size_t cur_n = 0;
    void operator()(double &num) {
        s += num;
        ++cur_n;
        if (cur_n == n_nums) {
            std::cout<<s/n_nums<<std::endl;
        }
    }
};
int main()
{
    std::vector<double> v;
    double num;
    while (std::cin>>num) {
        v.insert(v.end(), num);
    }
    size_t size = v.size();
    v.erase(v.begin(), v.begin() + size/10);
    v.erase(v.end() - size/10, v.end());
    if (v.size()/10) {
        std::vector<double> cpy = v;
        std::sort(cpy.begin(), cpy.end());
        size_t size = v.size();
        for (size_t i = 0; i < size/10; i++) {
            std::vector<double>::iterator itmin = std::find(v.begin(), v.end(), *(cpy.begin() + i));
            v.erase(itmin);
            std::vector<double>::iterator itmax = std::find(v.begin(), v.end(), *(cpy.end() - i - 1));
            v.erase(itmax);
        }
    }
    Sum s;
    s.n_nums = v.size();
    std::for_each(v.begin(), v.end(), s);
    return 0;
}
