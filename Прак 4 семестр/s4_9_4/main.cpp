#include <iostream>
#include <string>

//S -> aPd
//P -> aPd | Q
//Q -> bQc | bc
/*
void Q(int k, int n) {
    if (k == 2) {
        std::cout<<std::string(n%1000, 'a')<<std::string(n/1000,'b')<<std::string(n/1000,'c')<<std::string(n%1000,'d');
        std::cout<<std::endl;
    } else {
        Q(k - 2, n + 1000);
    }
}
void P(int k, int n) {
    if (k == 2) {
        Q(k, n + 1000);
    } else {
        P(k - 2, n + 1);
        Q(k, n + 1000);
    }
}
void S(int k) {
    P(k - 2, 1);
}*/

void Q(int m) {
    std::cout<<'b';
    if (m > 1) {
        Q(m - 1);
    }
    std::cout<<'c';
}
void P(int n, int m) {
    std::cout<<'a';
    if (n > 1) {
        P(n - 1, m);
    } else {
        Q(m);
    }
    std::cout<<'d';
}
void S(int n, int m) {
    if (n > 1) {
        P(n - 1, m + 1);
        std::cout<<std::endl;
        S(n - 1, m + 1);
    }
}
int main()
{
    int k;
    std::cin>>k;
    if (k >= 4 && k % 2 == 0) {
        S(k/2, 0);
    }
    return 0;
}
