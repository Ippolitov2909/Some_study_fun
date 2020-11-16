#include <iostream>
#include <string>
#include <map>
#include <set>
int main()
{
    std::string cur, new_, str_for_machine;
    char c;
    bool id_good = true;
    int count_ = 0;
    std::cin>>cur;
    std::map<std::pair<std::string, char>, std::string> machine = {};
    while (cur != "END") {
        std::cin>>c>>new_;
        machine[std::make_pair(cur, c)] = new_;
        std::cin>>cur;
    }
    std::set<std::string> finals = {};
    std::cin>>cur;
    while (cur != "END") {
        finals.insert(cur);
        std::cin>>cur;
    }
    std::cin>>cur;
    std::cin>>str_for_machine;
    for (auto z:str_for_machine) {
        std::string old_cur = cur;
        cur = machine[std::make_pair(cur, z)];
        if (cur.size() == 0) {
            id_good = false;
            cur = old_cur;
            break;
        }
        ++count_;
    }
    if (id_good && finals.count(cur)) {
        std::cout<<'1'<<std::endl;
    } else {
        std::cout<<'0'<<std::endl;
    }
    std::cout<<count_<<std::endl;
    std::cout<<cur<<std::endl;
    return 0;
}
