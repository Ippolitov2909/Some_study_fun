#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
int main()
{
    std::map<std::string, std::string> rules = {};
    while (std::cin) {
        std::string left_rule, right_rule;
        std::cin>>left_rule;
        if (left_rule[0] == EOF) {
            break;
        }
        std::cin>>right_rule;
        if (right_rule[right_rule.size() - 1] == EOF) {
            right_rule.pop_back();
            right_rule += " " + rules[left_rule];
            rules[left_rule] = right_rule;
            break;
        } else {
            right_rule += " " + rules[left_rule];
            rules[left_rule] = right_rule;
        }
    }
    std::set<std::string> elems_old = {};
    std::set<std::string> elems_new = {"S"};
    while (elems_new != elems_old) {
        elems_old = elems_new;
        for (auto z:elems_old) {
            auto res_of_rule = rules[z];
            for (auto symbol:res_of_rule) {
                if (symbol != ' ') {
                    elems_new.insert(std::string(1, symbol));
                }
            }
        }
    }
    for (auto rule: rules) {
        if (elems_old.count(rule.first) == 0) {
            continue;
        }
        if (rules[rule.first].size() == 0) {
            continue;
        }
        std::string tmp_right_rule;
        std::istringstream stream(rule.second);
        while (stream>>tmp_right_rule) {
            std::cout<<rule.first<<' '<<tmp_right_rule<<std::endl;
        }
    }
    return 0;
}
