#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>
constexpr int H = 0, A = 1, AB = 2, AC = 3, ABC = 4, AS = 5, ABS = 6, ACS = 7, ABCS = 8, S_ = 9;

int main()
{
    std::string current;
    bool game_over = false;
    std::map<std::pair<int, char>, int> machine = {};
    machine.insert(std::make_pair(std::make_pair(H, '0'), A));
    machine.insert(std::make_pair(std::make_pair(H, '1'), AB));
    machine.insert(std::make_pair(std::make_pair(A, '0'), A));
    machine.insert(std::make_pair(std::make_pair(A, '1'), AB));
    machine.insert(std::make_pair(std::make_pair(AB, '0'), AC));
    machine.insert(std::make_pair(std::make_pair(AB, '1'), ABC));
    machine.insert(std::make_pair(std::make_pair(AC, '0'), AS));
    machine.insert(std::make_pair(std::make_pair(AC, '1'), ABS));
    machine.insert(std::make_pair(std::make_pair(ABC, '0'), ACS));
    machine.insert(std::make_pair(std::make_pair(ABC, '1'), ABCS));
    machine.insert(std::make_pair(std::make_pair(AS, '0'), A));
    machine.insert(std::make_pair(std::make_pair(AS, '1'), AB));
    machine.insert(std::make_pair(std::make_pair(AS, '\0'), S_));
    machine.insert(std::make_pair(std::make_pair(ABS, '0'), AC));
    machine.insert(std::make_pair(std::make_pair(ABS, '1'), ABC));
    machine.insert(std::make_pair(std::make_pair(ABS, '\0'), S_));
    machine.insert(std::make_pair(std::make_pair(ACS, '0'), AS));
    machine.insert(std::make_pair(std::make_pair(ACS, '1'), ABS));
    machine.insert(std::make_pair(std::make_pair(ACS, '\0'), S_));
    machine.insert(std::make_pair(std::make_pair(ABCS, '0'), ACS));
    machine.insert(std::make_pair(std::make_pair(ABCS, '1'), ABCS));
    machine.insert(std::make_pair(std::make_pair(ABCS, '\0'), S_));

    while (!game_over && std::cin>>current) {
        bool id_good = true, id_anything_met = false;
        int current_state = H;
        current += '\0';
        std::istringstream stream(current);
        char c;
        while (stream>>c) {
            if (c == '0' || c == '1') {
                id_anything_met = true;
                current_state = machine[std::make_pair(current_state, c)];
            } else if (c == '\0') {
                if (current_state >= AS && current_state <= ABCS) {
                    current_state = S_;
                }
            } else if (c == EOF) {
                game_over = true;
                if (current_state >= AS && current_state <= ABCS) {
                    current_state = S_;
                } else {
                    id_good = false;
                }
            } else {
                id_anything_met = true;
                id_good = false;
            }
        }
        if (id_good && current_state == S_ && id_anything_met) {
            std::cout<<"1"<<std::endl;
        } else if (id_anything_met) {
            std::cout<<"0"<<std::endl;
        }
    }
    return 0;
}
