#include <iostream>
#include <cmc_complex.h>
#include <cmc_complex_stack.h>
#include <cmc_complex_eval.h>
#include <cmath>
#include <vector>
#include <string>
#include <functional>
#include <map>
/*enum
{
    LEN = 64
};
namespace numbers {

    class complex{
    public:
        double re_, im_;
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
//        friend complex operator=(complex &v1, const complex &v2);
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


    class complex_stack {
        complex *start;
        unsigned int cursize, sizemax;
    public:
        complex_stack(unsigned int newsize = 1) {
            start = new complex[newsize];
            sizemax = newsize;
            cursize = 0;
        }
        unsigned int size() const{
            return cursize;
        }

        complex operator[] (unsigned int i) const {
            return start[i];
        }


        complex_stack &operator=(const complex_stack &s) {
            if (this == &s) {
                return *this;
            }
            for (size_t i = 0; i < cursize; i++) {
                start[i].~complex();
            }
            delete[] start;
            start = new complex[s.sizemax];
            cursize = s.cursize;
            for (size_t i = 0; i < cursize; i++) {
                new(start + i) complex(s.start[i]);
            }
            sizemax = s.sizemax;
            return *this;
        }

        friend complex_stack operator<<(const complex_stack &oldstack, const complex num) {
            unsigned int sz = oldstack.sizemax;
            if (oldstack.sizemax == oldstack.cursize + 1) {
                sz *= 2;
            }
            complex_stack res(sz);
            for (size_t i = 0; i < oldstack.cursize; i++) {
                new (res.start + i) complex(oldstack.start[i]);
            }
            new(res.start + oldstack.cursize) complex(num);
            res.cursize = oldstack.cursize + 1;
            return res;
        }

        complex operator+() const {
            return start[cursize - 1];
        }

        friend complex_stack operator~(const complex_stack &s) {
            complex_stack res(s.sizemax);
            res.cursize = s.cursize - 1;
            for (size_t i = 0; i < res.cursize; i++) {
                new(res.start + i) complex(s.start[i]);
            }
            return res;
        }

        ~complex_stack() {
            for (size_t i = 0; i < cursize; i++) {
                start[i].~complex();
            }
            delete[] start;
        }
    };

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
        }
        complex res = +st;
        return res;
    }
};*/

int main(int argc, char **argv)
{
    std::string str(argv[1]);
    numbers::complex c(str);
    double r;
    int n;
    sscanf(argv[2], "%lf", &r);
    sscanf(argv[3], "%d", &n);
    std::vector<std::string> v = {};
    v.reserve(argc);
    for (int i = 4; i < argc; i++) {
        std::string tmp(argv[i]);
        v.push_back(tmp);
    }
    double phi_delta = 2*acos(-1.0)/n;
    numbers::complex delta(cos(phi_delta), sin(phi_delta));
    numbers::complex deltahalf(cos(phi_delta/2), sin(phi_delta/2));
    numbers::complex z(r, 0);
    numbers::complex z_next = z*delta;
    numbers::complex integral(0, 0);
    for (int i = 0; i < n; i++) {
        integral += numbers::eval(v, c + z * deltahalf)*(z_next - z);
        z = z_next;
        z_next *= delta;
    }
    std::cout<<integral.to_string()<<std::endl;
    return 0;
}
