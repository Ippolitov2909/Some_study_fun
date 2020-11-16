#include <iostream>
#include <cctype>

int main()
{
    int current;
    bool game_over = false;
    bool id_good = true;
    bool word_started = false;
    bool p_completed = false;
    bool q_completed = false;
    long long p_zero = 0;
    long long q_ones = 0;
    long long i = 0, j = 0;
    while (!game_over) {
        current = getchar();
        switch(current) {
        case '0':
            if (q_ones) {
                q_completed = true;
            }
            if (id_good) {
                if (p_completed) {
                    ++i;
                    if (i > p_zero) {
                        id_good = false;
                    }
                } else {
                    word_started = true;
                    ++p_zero;
                }
            }
            break;
        case '1':
            if (id_good) {
                if (q_completed) {
                    ++j;
                    if (i < p_zero) {
                        id_good = false;
                    }
                    if (j > q_ones) {
                        id_good = false;
                    }
                    if (i == p_zero && j == q_ones) {
                        i = 0;
                        j = 0;
                    }
                } else {
                    if (p_zero) {
                        p_completed = true;
                        ++q_ones;
                    } else {
                        word_started = true;
                        id_good = false;
                    }
                }
            }
            break;
        case EOF:
            if (word_started) {
                if (id_good && p_completed && !i && !j) {
                    std::cout<<'1'<<std::endl;
                } else {
                    std::cout<<'0'<<std::endl;
                }
            }
            game_over = true;
            break;
        default:
            if (isspace(current)) {
                if (word_started) {
                    if (id_good && p_completed && !i && !j) {
                        std::cout<<'1'<<std::endl;
                    } else {
                        std::cout<<'0'<<std::endl;
                    }
                    word_started = false;
                    id_good = true;
                    i = 0;
                    j = 0;
                    p_zero = 0;
                    q_ones = 0;
                    p_completed = false;
                    q_completed = false;
                }
            } else {
                if (id_good) {
                    word_started = true;
                    id_good = false;
                }
            }
        }
    }

    return 0;
}
