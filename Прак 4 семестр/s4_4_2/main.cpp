#include <iostream>
#include <functional>
#include <vector>
template <typename T>
T myfilter(T arr, std::function<bool(typename T::value_type)> pred) {
    T res;
    for (auto z:arr) {
        if (pred(z)== true){
            res.insert(res.end(), z);
        }
    }
    return res;
}
/*
int main()
{
    std::vector<int> v= {1, 2, -4, 5, -2};
    std::function<bool(int)> f= [] (int a){
        if(a >= 0) {
            return true;
        } else {
            return false;
        }
    };
    auto z = myfilter(v, f);
    for (auto w:z) {
        std::cout<<w<<std::endl;
    }
    return 0;
}*/
