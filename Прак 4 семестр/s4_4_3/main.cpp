#include <iostream>
#include <functional>
#include <vector>

template <typename T>
void myapply ( T::iterator &first, T::iterator last, std::function<void(typename T::value_type)> f) {
    for (auto i = first; i != last; i++) {
        f(*i);
    }
    return;
}

template <typename T>
myfilter2 (T::iterator &first, T::iterator &last, std::function<bool(typename T::value_type)> pred) {
    T notres;
    for (auto i = first; i != last; i++) {
        if (pred(*i)) {
            notres.insert(notres.end(), *i);
        }
    }
    T <std::reference_wrapper<typename T::value_type>> res (notres.begin(), notres.end());
    return res;
}
int main()
{
    std::vector<int> v = {1, 2, 3, 7, 6, 5, 4};
    std::function<void(int &)> f = [] (int &a) {
        a *= 2;
    }
    return 0;
}
