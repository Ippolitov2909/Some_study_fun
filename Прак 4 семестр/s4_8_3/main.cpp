#include <iostream>
#include <cctype>

int main()
{
    bool id_context = true;
    bool id_not_compressive = true;
    bool id_rule_S_to_any = false;
    bool id_rule_any_to_S = false;
    bool id_rule_S_to_empty = false;
    bool id_is_grammar = true;
    bool id_started = false;
    std::string L_rule, R_rule;
    while(std::cin>>L_rule) {
        if (L_rule[0] == EOF) {
            break;
        }
        std::cin>>R_rule;
        if (L_rule.size() == 1 &&  L_rule[0] == 'S') {
            id_rule_S_to_any = true;
        }
        if (L_rule[0] == EOF) {
            break;
        }
        id_started = true;
        if (L_rule.size() > R_rule.size() ) {
            id_not_compressive = false;
        }
        if (R_rule == std::string("_")) {
            if (L_rule != std::string("S")) {
                id_not_compressive = false;
            } else {
                if (id_rule_any_to_S) {
                    id_not_compressive = false;
                }
                id_rule_S_to_empty = true;
            }
        }
        if (L_rule.size() > 1 || (L_rule.size() == 1 && !isupper(L_rule[0]))) {
            id_context = false;
        }
        bool id_all_lower = true;
        for (size_t i = 0; i < L_rule.size(); i++) {
            if (isupper(L_rule[i])) {
                id_all_lower = false;
            }
        }
        for (size_t i = 0; i < R_rule.size(); i++) {
            if (R_rule[i] == 'S') {
                id_rule_any_to_S = true;
                if (id_rule_S_to_empty) {
                    id_not_compressive = false;
                }
            }
        }
        if (id_all_lower) {
            id_is_grammar = false;
        }
        if (R_rule[R_rule.size() - 1] == EOF) {
            break;
        }
    }
    if (id_is_grammar && id_started && id_rule_S_to_any) {
        if (id_context && id_not_compressive) {
            std::cout<<"23"<<std::endl;
        } else if (id_context && !id_not_compressive) {
            std::cout<<"2"<<std::endl;
        } else {
            std::cout<<"10"<<std::endl;
        }
    } else {
        std::cout<<"-1"<<std::endl;
    }
    return 0;
}
