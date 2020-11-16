#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string current;
    while (std::cin>>current) {
        std::istringstream stream(current);
        int p = 0, q = 0;
        char cur;
        bool id_good = true;
        stream>>cur;
        while (cur == '0') {
            ++p;
            if (!(stream>>cur)) {
                break;
            }
        }
        while (cur == '1') {
            ++q;
            if (!(stream>>cur)) {
                break;
            }
        }
        //std::cout<<"p "<<p<<" q "<<q<<" char "<<cur<<std::endl;
        while(stream && id_good) {
            for (int i = 0; i < p; i++) {
                if (cur != '0' || !(stream>>cur)) {
                    //std::cout<<"1 i "<<i<<" char "<<cur<<std::endl;
                    std::cout<<'0'<<std::endl;
                    id_good = false;
                    break;
                }
            }
            if (!id_good) break;
            for (int i = 0; i < q; i++) {
                if (cur != '1') {
                    //std::cout<<"2 i "<<i<<" char "<<cur<<std::endl;
                    std::cout<<'0'<<std::endl;
                    id_good = false;
                    break;
                }
                if (!(stream>>cur)) {
                    if (i != q - 1 || cur != '1') {
                    //std::cout<<"3 i "<<i<<" char "<<cur<<std::endl;
                    std::cout<<'0'<<std::endl;
                    id_good = false;
                    break;
                    }
                }
            }
        }
        if (cur != '1' && id_good) {
            if (cur == '0' && q == 0) {
                std::cout<<'1'<<std::endl;
                id_good = false;
            } else {
                //std::cout<<"last"<<std::endl;
                std::cout<<'0'<<std::endl;
                id_good = false;
            }
        }
        if (id_good) {
            std::cout<<'1'<<std::endl;
        }
    }
    return 0;
}
