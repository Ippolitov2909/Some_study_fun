#include <iostream>
#include <vector>
template <typename T>
typename T::value_type process (T arr) {
    if (arr.begin() ==arr.end()) {
        typename T::value_type res1 = 0;
        return res1;
    } else {
        auto iter = arr.end();
        auto res = *(--iter);
        int id = -1;
        --iter;
        for (int i = 0;i < 4;i++) {
            if (id > 0) {
                res += *iter;
            }
            id *= -1;
            if (iter == arr.begin()) {
                break;
            }
            --iter;
        }
        return res;
    }
}
