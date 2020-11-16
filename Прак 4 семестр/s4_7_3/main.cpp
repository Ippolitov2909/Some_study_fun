#include <iostream>

class S
{
public:
    int a = 0;
    bool id = false;
    bool id2 = false;
    S() {
        if (std::cin>>a) {
            id = true;
            id2 = true;
        } else {
            id = false;
            id2 = false;
        }
    }
    /*S (S &s) {
        id = s.id;
        a = s.a;
        id2 = s.id2;
    }*/
    S(S &&s) {
        if (std::cin>>a) {
            id = true;
        } else {
            id = false;
        }
        a += s.a;
        id2 = true;
    }
    ~S() {
        if (!id && id2) {
            std::cout<<a<<std::endl;
        }
    }
    operator bool () {
        return id;
    }
};
