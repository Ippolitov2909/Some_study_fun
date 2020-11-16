#include <iostream>
#include <set>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <cctype>
int main()
{
    std::string current;
    std::set<std::string> elems = {};
    std::map<std::string, std::set<std::string>> paths = {};
    while (std::getline(std::cin, current)) {
        //if (current[0] == 4 || current[0] == EOF) {
        //    break;
        //}
        std::istringstream stream(current);
        std::string mybegin, myend, mybegin_first;
        stream>>myend;
        if (myend[myend.size() - 1] == ':') {
            myend.pop_back();
        }
        int pos = myend.find(':');
        if (pos != -1) {
            auto tmp_pos = pos + 1;
            while (isspace(myend[tmp_pos])) {
                ++tmp_pos;
            }
            mybegin_first = myend.substr(tmp_pos, myend.size() - tmp_pos);
            myend = myend.substr(0, pos);
        }
        elems.insert(myend);
        std::set<std::string> path_begins = paths[myend];
        if (mybegin_first.size() > 0) {
            path_begins.insert(mybegin_first);
            elems.insert(mybegin_first);
        }
        while (stream>>mybegin) {
            if (mybegin != ":") {
                if (mybegin[0] == ':') {
                    mybegin.erase(0, 1);
                }
                path_begins.insert(mybegin);
                elems.insert(mybegin);
            }
        }
        paths[myend] = path_begins;
    }
    size_t n = elems.size();
    std::vector<std::string> res = {};
    while(res.size() < n) {
        bool something_happened = false;
        for (auto elem:elems) {
            if (paths[elem].size() == 0) {
                something_happened = true;
                res.push_back(elem);
                elems.erase(elem);
                for (auto elem_1:elems) {
                    paths[elem_1].erase(elem);
                }
                break;
            }
        }
        if (!something_happened) {
            return 1;
        }
    }
    for (auto elem:res) {
        std::cout<<elem<<' ';
    }
    std::cout<<std::endl;
    return 0;
}
