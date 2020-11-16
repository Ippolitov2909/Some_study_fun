#include <iostream>
#include <cctype>

int main()
{
    int current = 0;
    bool id_quit = false;
    while(current != EOF && current != 4 && !id_quit) {
        //std::cout<<current<<std::endl;
        current = getchar();
        while (isspace(current)) {
            //std::cout<<"space"<<std::endl;
            current = getchar();
            if (current == EOF || current == 4) {
                id_quit = true;
                break;
            }
        }
        if(current == EOF || current == 4) {
            break;
        }
        long long p = 0, q = 0;
        bool id_good = true;
        bool zero_been = false;
        while(!isspace(current) && current != EOF && current != 4) {
            //std::cout<<"not a space"<<std::endl;
            while(current == '0' && !isspace(current)) {
                //std::cout<<"first_zero "<<isspace(current)<<std::endl;
                zero_been = true;
                ++p;
                current = getchar();
                if (isspace(current)) {
                    id_good = false;
                    break;
                }
                if (current == EOF || current == 4) {
                    id_good = false;
                    id_quit = true;
                    break;
                }
            }
            if (isspace(current)) {
                break;
            }
            /*if(!p) {
                while(!isspace(current)) {
                    current = getchar();
                }
                id_good = false;
                break;
            }*/
            while (current == '1' && !isspace(current) && zero_been) {
                //std::cout<<"first_one"<<std::endl;
                ++q;
                current = getchar();
                if(!(current != EOF && current != 4) || isspace(current)) {
                    break;
                }
            }
            if (!q || !p) {
                while(!isspace(current)) {
                    current = getchar();
                    if (current == EOF || current == 4) {
                    //std::cout<<current<<std::endl;
                        id_quit = true;
                    }
                }
                id_good = false;
                break;
            }
            long long i, j = 0;
            while (current != EOF && current != 4 && !isspace(current)) {
                //std::cout<<"! "<<isspace(current)<<' '<<current<<std::endl;
                i = 0, j = 0;
                while (current == '0' && i < p && current != EOF && current != 4) {
                    //std::cout<<"zero"<<std::endl;
                    ++i;
                    current = getchar();
                }
                /*if (i < p) {
                    id_good = false;
                }*/
                while (current == '1' && j < q && current != EOF && current != 4) {
                    //std::cout<<"one"<<std::endl;
                    ++j;
                    current = getchar();
                }
                if (j < q || i < p) {
                    while(!isspace(current)) {

                        if (current == EOF || current == 4) {
                    //std::cout<<current<<std::endl;
                            id_quit = true;
                        }
                        current = getchar();
                    }
                    id_good = false;
                    break;
                }
            }
        }
        if (id_good) {
            std::cout<<'1'<<std::endl;
        } else {
            std::cout<<'0'<<std::endl;
        }
    }
    return 0;
}
