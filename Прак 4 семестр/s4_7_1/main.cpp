#include <iostream>
#include <exception>
#include <string>
class my_string
{
public:
    std::string output;
    my_string(std::string input) {
        output = input;
    }
    ~my_string() {
        std::cout<<output<<std::endl;
    }
};

void my_sequence(my_string &current_string) {
    std::string next_string;
    try {
        if (std::cin>>next_string && next_string[0] != 4) throw my_string(next_string);
        else throw 1;
    } catch (int z) {
    } catch (my_string &next_string) {
        my_sequence (next_string);
    }
    throw 2;
}

int main()
{
    std::string output;
    std::cin>>output;
    my_string first_string(output);
    try {
        my_sequence(first_string);
    } catch (int z) {
    }
    return 0;
}
