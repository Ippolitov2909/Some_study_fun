#include <iostream>
#include <algorithm>


template <typename ItNums, typename ItElems>
ItElems myremove (ItNums first, ItNums last, ItElems begin, ItElems end) {
    if (first == last) {
        return end;
    }
    int k = 0;
    std::vector<ssize_t> nums;
    while (first != last) {
        nums.push_back(*first);
        first++;
    }
    std::sort(nums.begin(), nums.end());
    auto newend = std::unique(nums.begin(), nums.end());
    auto currentnum = nums.begin();
    while (*currentnum < 0 && currentnum < newend) {
        currentnum++;
        if (currentnum == newend) {
            return end;
        }
    }

    auto currentelem = begin + *currentnum + 1;
    auto trashhead = currentelem - 1;
    currentnum++;

    while (currentelem < end) {
        if (currentelem - begin == *currentnum) {
            currentnum++;
            currentelem++;
        } else {
            std::swap(*trashhead, *currentelem);
            trashhead++;
            currentelem++;
        }
    }
    k = end - trashhead;
    return end - k;
}
