#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <thread>

class Longint {
public:
    std::vector<int> number;
    int start_fractional;
    Longint () {
        number = {};
        start_fractional = 0;
    };
    Longint(int num) {
        while (num) {
            number.push_back(num % 10);
            num /= 10;
        }
        start_fractional = 0;
    };
    size_t size () {
        return number.size();
    };
    void push_back(int digit) {
        number.push_back(digit);
    };
    Longint operator+(Longint other) { //works only with numbers with fractional part = 0
        Longint res;
        int remainder = 0;
        size_t size_min = std::min(other.size(), this->size());
        size_t size_max = std::max(other.size(), this->size());
        for (size_t i = 0; i < size_min; i++) {
            int tmp = other.number[i] + number[i] + remainder;
            remainder = tmp / 10;
            res.push_back(tmp % 10);
        }
        if (size_max == size_min) {
            if (remainder) {
                res.push_back(remainder);
            }
        } else if (this->size() > other.size()) {
            for (size_t i = size_min; i < size_max; i++) {
                int tmp = number[i] + remainder;
                remainder = tmp / 10;
                res.push_back(tmp % 10);
            }
            if (remainder) {
                res.push_back(remainder);
            }
        } else {
            for (size_t i = size_min; i < size_max; i++) {
                int tmp = other.number[i] + remainder;
                remainder = tmp / 10;
                res.push_back(tmp % 10);
            }
            if (remainder) {
                res.push_back(remainder);
            }
        }
        return res;
    };
    Longint operator*(Longint other) {
        Longint res(0);
        size_t size1 = other.size();
        size_t size2 = this->size();
        for (size_t i = 0; i < size1; i++) {
            Longint tmp;
            for (int j = 0; j < i; j++) {
                tmp.push_back(0);
            }
            int remainder = 0;
            int mul = other.number[i];
            for (size_t j = 0; j < size2; j++) {
                int temp = number[j] * mul + remainder;
                remainder = temp / 10;
                tmp.push_back(temp % 10);
            }
            if (remainder) {
                tmp.push_back(remainder);
            }
            res = res + tmp;
        }
        return res;
    };
    static Longint Longint_from_hex (std::vector<int> hex) {
        Longint res(0);
        for (auto it = hex.begin(); it < hex.end(); it++) {
            Longint tmp (*it);
            for (int j = 0; j < hex.end() - 1 - it; j++) {
                tmp = tmp * Longint(16);
            }
            res = res + tmp;
        }
        return res;
    }
    Longint div_by_16 () {
        Longint res;
        int current = 0;
        for (auto it = number.end() - 1; it >= number.begin(); it--) {
            current += *it;
            res.number.insert(res.number.begin(), current / 16);
            current %= 16;
            current *= 10;
        }
        current *= 625;
        while (current % 10 == 0) {
            current /= 10;
        }
        int k = 0;
        while (current) {
            res.number.insert(res.number.begin() + k, current % 10);
            current /= 10;
            k++;
        }
        auto it = res.number.end() - 1;
        while (*it == 0) {
            it--;
            res.number.pop_back();
        }
        start_fractional += k;
        return res;
    }
};
long long
pow_and_mod (int degree, int num) {
    long long res = 1;
    for (int i = 1; i <= degree; i++) {
        res *= 16;
        res %= num;
    }
    return res;
}
double
S_i (int d, int j) {
    double sum = 0;
    double mul = 1;
    for (int k = 0; k < d; k++) {
        sum += double(pow_and_mod(d - k, 8 * k + j))/(8 * k + j);
    }
    for (int k = d; k < 10 + d; k++) {
        sum += mul / (8 * k + j);
        mul /= 16;
    }
    return sum;
}

void
new_digit (int i, std::vector<int> *pi_hex) {
    double x;
    double s1 = std::modf(S_i(i, 1), &x);
    double s4 = std::modf(S_i(i, 4), &x);
    double s5 = std::modf(S_i(i, 5), &x);
    double s6 = std::modf(S_i(i, 6), &x);
    double res = std::modf(4 * s1 - 2 * s4 - s5 - s6, &x);
    if (res < 0) {
        res += 1;
    }
    std::modf(res * 16, &res);
    (*pi_hex)[i] = int(res);

}
int main()
{
    int num_of_digits;
    std::vector<int> pi_hex = {};
    std::vector<std::thread> threads = {};
    std::cin>>num_of_digits;
    for (int i = 0; i < num_of_digits; i++) {
        pi_hex.push_back(0);
        threads.push_back(std::thread(new_digit, i, &pi_hex));
    }
    for (auto &thread:threads) {
        thread.join();
    }

    std::cout<<"hex ";
    pi_hex.insert(pi_hex.begin(), 3);
    for (auto digit:pi_hex) {
        if (digit < 10) {
            std::cout<<digit;
        } else {
            std::cout<<char('A' + digit - 10);
        }
    }
    std::cout<<std::endl;

    Longint res = Longint::Longint_from_hex(pi_hex);

    for (int i = 0; i < pi_hex.size() - 1; i++) {
        res = res.div_by_16();
    }
    std::cout<<"dec 3.";
    for (auto it = res.number.end() - 2; it >= res.number.begin(); it--) {
        std::cout<<*it;
    }
    std::cout<<std::endl;

    return 0;
}
