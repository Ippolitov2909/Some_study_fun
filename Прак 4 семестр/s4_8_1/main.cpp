#include <iostream>
#include <string>
#include <sstream>
int main()
{
    std::string str;
    while(std::cin>>str) {
        char c;
        bool id_alpha = false;
        bool id_beta = false;
        bool id_good = true;
        bool id_whatever = false;
        std::istringstream stream(str);
        while (stream>>c && id_good) {
            if (c == '3' || c == '4') {
                id_whatever = true;
                if (id_beta) {
                    id_good = false;
                    break;
                }
                id_alpha = true;
            } else if (c == '1' || c == '2') {
                if (!id_alpha && id_whatever) {
                    id_good = false;
                }
                id_beta = true;
            } else {
                id_good = false;
                break;
            }
        }
        if(id_good) {
            std::cout<<'1'<<std::endl;
        } else {
            std::cout<<'0'<<std::endl;
        }
    }
    return 0;
}
