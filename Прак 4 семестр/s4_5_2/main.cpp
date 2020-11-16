#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <string.h>
class Figure
{
public:
    virtual double get_square() const = 0;

    virtual ~Figure() = default;
};

class Square: public Figure
{
private:
    double a = 0;
public:
    Square() = default;
    Square (std::string side) : Figure () {
        sscanf(side.c_str(), "%lf", &a);
    }
    static Square *make (std::string side) {
        Square *res = new Square(side);
        return res;
    }
    double get_square() const{
        return a*a;
    }
};

class Circle: public Figure {
private:
    double r = 0;
public:
    Circle() = default;
    Circle(std::string rad) : Figure () {
        sscanf(rad.c_str(), "%lf", &r);
    }
    static Circle *make(std::string rad) {
        Circle *res = new Circle(rad);
        return res;
    }
    double get_square () const {
        return r * r * acos(-1);
    }
};

template <class Fig>
class Common{
    Fig *figure;
    common(Fig *figure_) {
        figure = figure_;
    }
};
class Rectangle: public Figure {
private:
    double a = 0, b = 0;
public:
    Rectangle() = default;
    Rectangle(std::string sides): Figure() {
        sscanf(sides.c_str(), "%lf %lf", &a, &b);
    }
    static Rectangle *make (std::string sides) {
        Rectangle *res = new Rectangle(sides);
        return res;
    }
    double get_square () const {
        return a * b;
    }
};

int main()
{
    //std::vector<Common> figures;
    st
    std::string current;
    std::getline(std::cin, current);
    while (strcmp(current.c_str(), "")) {

        std::getline(std::cin, current);
    }
    return 0;
}
