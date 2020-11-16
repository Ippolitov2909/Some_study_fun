#include <iostream>
#include <vector>
#include <algorithm>
bool cmp (const int &a, const int&b) {
    if (a < b) {
        return true;
    }
    return false;
}
void process(const std::vector<int> &v1, std::vector<int> &v2) {
    if (v1.begin() == v1.end()) {
        return;
    }
    std::vector<int> vcopy = v1;
    std::sort (vcopy.begin(), vcopy.end(), cmp);
    auto it_end = std::unique(vcopy.begin(), vcopy.end());
    auto iter1 = vcopy.begin();
    while (*iter1 < 0 && iter1 != it_end) {
        iter1++;
    }
    if (iter1 == it_end) {
        return;
    }

    int offset = 0;
    int id = 0;
    std::vector<int>::iterator trashhead;
    for (auto iter2 = v2.begin(); iter2 < v2.end(); iter2++) {
        if (id == 0) {
            if (iter2 - v2.begin() == *iter1) {
                id = 1;
                offset++;
                iter1++;
                trashhead = iter2;
            }
        } else {
            if (iter2 - v2.begin() != *iter1) {
                std::swap(*trashhead, *iter2);
                trashhead++;
            } else {
                offset++;
                iter1++;
            }
        }
    }
    v2.erase(v2.end() - offset, v2.end());
    v2.shrink_to_fit();
}
