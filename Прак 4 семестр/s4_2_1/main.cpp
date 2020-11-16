#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
namespace numbers {
    constexpr int LEN = 64;
    class complex{
        double re_, im_;
    public:
        complex (double real = 0, double imag = 0) {
            re_ = real;
            im_ = imag;
        }
        explicit complex (std::string str) {
            const char *newstr = str.c_str();
            sscanf(newstr, "(%lf,%lf)", &this->re_, &this->im_);
        }
        double re() const {
            return this->re_;
        }
        double im () const {
            return this->im_;
        }
        double abs2 () const{
            return (this->re_) * (this->re_) + (this->im_) * (this->im_);
        }
        double abs () const{
            return sqrt(this->abs2());
        }
        std::string to_string () const{
            char str[LEN];
            snprintf(str, LEN - 4, "(%.10g,%.10g)", re_, im_);
            std::string s(str);
            return s;
        }
        const complex &operator+=(const complex &a) {
            re_ += a.re_;
            im_ += a.im_;
            return *this;
        }
        const complex &operator-=(const complex &a) {
            re_ -= a.re_;
            im_ -= a.im_;
            return *this;
        }
        const complex &operator*= (const complex &a){
            double tmp = re_ * a.re_ - im_ * a.im_;
            im_ = re_ * a.im_ + im_ * a.re_;
            re_ = tmp;
            return *this;
        }
        const complex &operator/= (const complex &a) {
            double tmp = a.re_ * a.re_ + a.im_ * a.im_;
            *this *= ~a;
            re_ /= tmp;
            im_ /= tmp;
            return *this;
        }
        complex operator~() const{
            return complex(re_, -im_);
        }
        complex operator-() const {
            return complex(-re_, -im_);
        }
        friend complex operator+(complex v1, const complex &v2);
        friend complex operator-(complex v1, const complex &v2);
        friend complex operator*(complex v1, const complex &v2);
        friend complex operator/(complex v1, const complex &v2);

    };
    complex operator+(complex v1, const complex &v2) {
        return v1 += v2;
    };
    complex operator-(complex v1, const complex &v2) {
        return v1 -= v2;
    }
    complex operator*(complex v1, const complex &v2) {
        return v1 *= v2;
    }
    complex operator/(complex v1, const complex &v2) {
        return v1 /= v2;
    }
};






