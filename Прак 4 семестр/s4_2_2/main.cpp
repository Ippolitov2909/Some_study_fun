#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*enum
{
    LEN = 64
};*/
namespace numbers {
    /*class complex{
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
            im_ = re_ * a.im_ - im_ * a.re_;
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
    }*/


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
};

/*int main (void) {
    numbers::complex v1(0, 1), v2(2, -2), v3(-3, -4), v4(0, 2);
    numbers::complex_stack s1, s3;
    numbers::complex_stack s2, s4, s5;
    s2 = s1<<v1;
    s3 = s2<<v2;
    std::cout<<s1.cursize<<std::endl;
    std::cout<<s2.cursize<<' '<<s2.sizemax<<' '<<s2.start[0].to_string()<<std::endl;
    std::cout<<s3.cursize<<' '<<s3.sizemax<<' '<<s3.start[0].to_string()<<' '<<s3.start[1].to_string()<<std::endl;
    std::cout<<(+s3).to_string()<<std::endl;
    s5 = ~s3;
    std::cout<<(+s5).to_string()<<std::endl;
    s4 = s5<<v3;
    std::cout<<s4[0].to_string()<<' '<<s4[1].to_string()<<std::endl;
    return 0;
}*/





