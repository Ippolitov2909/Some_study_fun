#include <iostream>
#include <vector>
void process (std::vector<long long int> &v, long long int limit) {
    if (v.end() == v.begin()) {
        return;
    }
    int count = 0;
    for (auto z:v) {
        if (z < limit) {
            ++count;
        }
    }
    v.reserve(v.size() + count);
    std::vector<long long int>::iterator iter = v.end();
    --iter;
    while (iter != v.begin()) {
        if (*iter >= limit) {
            v.push_back(*iter);
        }
        iter--;
    }
}
