#include <iostream>
#include <vector>
#include <functional>
template <typename It, typename Func>
void myapply (It begin, It end, Func f) {
    while (begin < end) {
        f(*begin);
        begin++;
    }
}


template <typename It, typename Func>
std::vector<std::reference_wrapper<typename std::iterator_traits<It>::value_type>>
myfilter2 (It begin, It end, Func f) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<It>::value_type>> v2;
    while (begin < end) {
        if (f(*begin)) {
            v2.insert(v2.end(), *begin);
        }
        begin++;
    }
    return v2;
}
