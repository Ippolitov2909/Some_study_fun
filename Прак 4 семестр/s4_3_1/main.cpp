#include <iostream>
#include <vector>
void process (const std::vector<unsigned long long> &v1,
                std::vector<unsigned long long> &v2, unsigned int step) {
    std::vector<unsigned long long>::const_iterator iter = v1.begin();
    std::vector<unsigned long long>::iterator iter2 = v2.end();
    if (v2.end() == v2.begin() || v1.end() == v1.begin()) {
        return;
    }
    --iter2;
    size_t n = (v1.size() - 1)/step;
    for (size_t i = 0; i <= n; i++) {
        *iter2 += *iter;
        iter  = iter + step;
        if (iter2 == v2.begin()) {
            break;
        }
        --iter2;
    }
}
