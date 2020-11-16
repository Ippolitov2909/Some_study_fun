#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
enum
{
    EOT = 4
};


class FigureFactory {
public:
    static FigureFactory *factory_instance() {
        if (instance == 0) {
            instance = new FigureFactory;
        }
        return instance;
    };

    Figure *make (std::string params) {
        std::istringstream stream(params);
        char c;
        std::string newparams;
        stream>>c;
        stream>>newparams;
        if (c == 'R') {
            std::string add;
            stream>>add;
            newparams += ' ' + add;
            return Rectangle::make(newparams);
        } else if (c == 'C') {
            return Circle::make(newparams);
        } else {
            return Square::make(newparams);
        }
    }
protected:
    FigureFactory () = default;
private:
    static FigureFactory *instance;
};

FigureFactory* FigureFactory::instance = 0;


int main()
{
    std::string current;
    auto factory = FigureFactory::factory_instance();
    std::vector<Figure *> v;
    while (std::getline(std::cin, current)) {
        if (current[0] == EOT || current[0] == EOF) {
            break;
        }
        auto fig = factory->make(current);
        v.push_back(fig);
    }
    std::stable_sort(v.begin(), v.end(), [] (Figure *fig1, Figure *fig2) {
        if (fig1->get_square() < fig2->get_square()) {
            return 1;
        }
        return 0;
    });
    for (auto z: v) {
        std::cout<<z->to_string()<<std::endl;
        delete z;
    }
    return 0;
}
