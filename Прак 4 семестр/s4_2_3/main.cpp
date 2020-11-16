#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <functional>
namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z){
        complex_stack st;
        std::function<void()> pluss, minuss, div, mul, push, pop, tilda, neg;
        pluss = [&st] () {
            complex v1 = +st;
            st = ~st;
            complex v2 = +st;
            st = (~st);
            st = st<<(v1 + v2);
        };
        minuss = [&st] () {
            complex v1 = +st;
            st = ~st;
            complex v2 = +st;
            st = (~st);
            st = st<<(v2 - v1);
        };
        mul = [&st] () {
            complex v1 = +st;
            st = ~st;
            complex v2 = +st;
            st = ~st;
            st = st;
            st = st<<(v1 * v2);
        };
        div = [&st] () {
            complex v1 = +st;
            st = ~st;
            complex v2 = +st;
            st = (~st);
            st = st<<(v2/v1);
        };
        push = [&st] () {
            complex v1 = +st;
            st = st<<v1;
        };
        pop = [&st] () {
            st = ~st;
        };
        tilda = [&st] () {
            complex v1 = +st;
            v1 = ~v1;
            st = ~st;
            st = st<<v1;
        };
        neg = [&st] () {
            complex v1 = +st;
            v1 = -v1;
            st = ~st;
            st = st<<v1;

        };
        std::map<char, std::function<void()>> mapping = {{'+', pluss}, {'-', minuss}, {'*', mul}, {'/', div}};
        mapping.insert({'!', push});
        mapping.insert({';', pop});
        mapping.insert({'#', neg});
        mapping.insert({'~', tilda});
        std::vector<std::string>::const_iterator iter = args.begin();
        while (iter != args.end()) {
            if ((*iter).c_str()[0] == 'z') {
                st = st<<z;
            } else if ((*iter).c_str()[0] == '(') {
                complex n(*iter);
                st = st<<n;
            } else {
                const char *str = (*iter).c_str();
                mapping[str[0]]();

            }
            ++iter;

        complex res = +st;
        return res;
    }
};
