#include <iostream>

class Result
{
public:
    long long int res;
    Result(long long a, long long b) {
        res = a + b;
    }
};

void
func (long long a, long long b, int k)
{
    if (k == 0) throw Result(a, b);
    else if (b == 1) throw Result(a, 0);
    long long new_b;
    try {
        func(a, b - 1, k);
    } catch(Result &tmp) {
        new_b = tmp.res;
    }
    func(a, new_b, k - 1);
}
int main()
{
    long long a, b;
    int k;
    while(std::cin>>a>>b>>k) {
        try {
            func(a, b, k);
        } catch (Result &res) {
            std::cout<<res.res<<std::endl;
        }
    }
    return 0;
}
