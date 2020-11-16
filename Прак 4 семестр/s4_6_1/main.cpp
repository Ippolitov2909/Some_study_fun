#include <iostream>
#include <stdlib.h>
int abs(int a, int b) {
    if (a - b >= 0) {
        return a - b;
    } else {
        return b - a;
    }
}

int main()
{
    int m, n, r1, c1, r2, c2;
    std::cin>>m>>n;
    while (std::cin>>r1>>c1>>r2>>c2) {
        int a[9];
        a[0] = abs(r2 - r1) + abs(c2 - c1);
        a[1] = abs(r2 - r1) + abs(c2 + n - c1);
        a[2] = abs(r2 - r1) + abs(c2 - n - c1);
        a[3] = abs(r2 + m - r1) + abs(c2 - c1);
        a[4] = abs(r2 + m - r1) + abs(c2 + n - c1);
        a[5] = abs(r2 + m - r1) + abs(c2 - n - c1);
        a[6] = abs(r2 - m - r1) + abs(c2 - c1);
        a[7] = abs(r2 - m - r1) + abs(c2 + n - c1);
        a[8] = abs(r2 - m - r1) + abs(c2 - n - c1);
        int res = a[0];
        for (int i = 1; i < 9; i++) {
            if (res > a[i]) {
                res = a[i];
            }
        }
        std::cout<<res<<std::endl;
    }
    return 0;
}
