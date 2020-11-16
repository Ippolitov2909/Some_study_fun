#include <iostream>
#include <string>
#include <sstream>
//Context-sensitive grammar
//S -> aXPQ | aXP | aXQ
//P -> YXP | YX
//Q -> UVQ | UV
//aY -> aa
//aU -> a0
//0U -> 00
//0X -> 0b
//bX -> bb
//bV -> b1
//1V -> 11
//XY -> XC
//XC -> YC
//YC -> YX
//XU -> XD
//XD -> UD
//UD -> UX

int main()
{
    std::string current;
    bool game_over = false;
    while (!game_over && std::cin>>current) {
        char c;
        long long m = 0, n =  0, i = 0, j = 0;
        bool id_good = true;
        bool m_assigned = false, n_assigned = false;
        bool b_met = false, one_met = false;
        bool anything = false;
        std::istringstream stream(current);
        while (!game_over && stream>>c) {
            switch(c) {
            case 'a':
                anything = true;
                if (m_assigned) {
                    id_good = false;
                } else {
                    ++m;
                }
                break;
            case '0':
                anything = true;
                if (n_assigned) {
                    id_good = false;
                } else {
                    if (!n) {
                        if (!m) {
                            id_good = false;
                        }
                        m_assigned = true;
                    }
                    ++n;
                }
                break;
            case 'b':
                anything = true;
                if (n_assigned && !one_met) {
                    ++i;
                } else if (n >= 1 && !one_met) {
                    b_met = true;
                    n_assigned =  true;
                    ++i;
                } else {
                    id_good = false;
                }
                break;
            case '1':
                anything = true;
                one_met = true;
                if (b_met) {
                    ++j;
                } else {
                    id_good = false;
                }
                break;
            case EOF:
            case 4:
                game_over = true;
                break;
            default:
                anything = true;
                id_good = false;
                break;
            }
        }
        if (id_good && i == m && j == n && m_assigned) {
            std::cout<<'1'<<std::endl;
        } else if (anything) {
            std::cout<<'0'<<std::endl;
        }
    }
    return 0;
}
