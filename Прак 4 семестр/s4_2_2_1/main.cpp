#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
enum
{
    LEN = 64
};
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
    }
*/

    class complex_stack {
    public:
        complex *start;
        size_t cursize, sizemax;
        complex_stack(size_t newsize = 2) {
            start = new complex[newsize];
            sizemax = newsize;
            cursize = 0;
        }
        size_t size() const{
            return cursize;
        }

        complex operator[] (size_t i) const{
            return start[i];
        }

        complex operator+() const {
            return start[cursize - 1];
        }

        complex_stack &operator=(const complex_stack &st2) noexcept{
            if (this == &st2) {
                return *this;
            }
            delete[] start;
            start = new complex[st2.sizemax];
            for (size_t i = 0; i < st2.cursize; i++) {
                start[i] = st2.start[i];
            }
            cursize = st2.cursize;
            sizemax = st2.sizemax;
            return *this;
        }

        friend complex_stack operator<<(const complex_stack &st, const complex &num) {
            int sz = st.sizemax;
            if (st.sizemax == st.cursize) {
                sz *= 2;
            }
            complex_stack newstack(sz);
            for (size_t i = 0; i < st.cursize; i++) {
                newstack.start[i] = st.start[i];
            }
            newstack.start[st.cursize] = num;
            newstack.cursize = st.cursize + 1;
            return newstack;
        }


        complex_stack operator~() const{
            complex_stack newstack(sizemax);
            for (size_t i = 0; i < cursize - 1; i++) {
                newstack.start[i] = start[i];
            }
            newstack.cursize = cursize - 1;
            return newstack;
        }


        ~complex_stack() {
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
    std::cout<<s3.sizemax<<std::endl;
    std::cout<<s2[0].to_string()<<' '<<s3[0].to_string()<<' '<<s3[1].to_string()<<std::endl;
    s1 = s1<<v1<<v2<<v3<<v4;
    std::cout<<s1[0].to_string()<<' '<<(+s1).to_string()<<std::endl;
    s2 = ~s1;
    std::cout<<(+s2).to_string()<<' '<<(+s1).to_string()<<std::endl;
    s1 = ~s1;
    std::cout<<(+s1).to_string()<<std::endl;

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
