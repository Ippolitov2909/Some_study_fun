#include <iostream>
#include <vector>
#include <string>
class OnlyChar {
public:
    std::vector<char> str = {};
    int count = 0;
    OnlyChar (const char oldstr[]) {
        const char *ptr = oldstr;
        while (*ptr != '\0') {
            str.push_back(*ptr);
            ptr++;
        }
        count = 1;
    }
    OnlyChar (std::vector<char> &old) {
        for (auto z:old) {
            str.push_back(z);
        }
        count = 1;
    }
    ~OnlyChar () = default;
};


class String {
public:
    OnlyChar *instance;
    String () {
        instance = 0;
    };
    String(const char oldstr[]) {
        instance = new OnlyChar(oldstr);
    }
    String (const String &old) {
        instance = old.instance;
        instance->count += 1;
    }
    String &operator=(const String &old) {
        if (instance != nullptr) {
            instance->count -= 1;
            if (instance->count == 0) {
                delete instance;
            }
        }
        instance = old.instance;
        instance->count += 1;
        return *this;
    }
    String &operator=(const char old[]) {
        if (instance != nullptr) {
            instance->count -= 1;
            if (instance->count == 0) {
                delete instance;
            }
        }
        instance = new OnlyChar(old);
        return *this;
    }
    String &operator+=(const char add[]) {
        std::vector<char> newstr = instance->str;
        const char *ptr = add;
        while (*ptr != '\0') {
            newstr.push_back(*ptr);
            ptr++;
        }
        instance->count -= 1;
        if (instance->count == 0) {
            delete instance;
        }
        instance = new OnlyChar(newstr);
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const String str) {
        for (auto z:str.instance->str) {
            out<<z;
        }
        return out;
    }
    operator std::string () const {
        int size = instance->str.size();
        char *str = new char[size + 1];
        int i = 0;
        for (auto z:instance->str) {
            str[i] = z;
            i++;
        }
        str[i] = '\0';
        std::string res(str);
        delete[] str;
        return res;
    }
    class ProxyStr {
    public:
        size_t num = 0;
        OnlyChar **instance_ptr = 0;
        OnlyChar * const* c_instance_ptr = 0;
        ProxyStr(String &str, int i) {
            instance_ptr = &(str.instance);
            num = i;
        }
        ProxyStr(const String &str, int i) {
            c_instance_ptr = &(str.instance);
            num = i;
        }
        operator char() const{
            if (instance_ptr) {
                return (*instance_ptr)->str[num];
            } else {
                return (*c_instance_ptr)->str[num];
            }
        }
        char &operator=(const char newchar){
            std::vector<char> newstr = (*instance_ptr)->str;
            newstr[num] = newchar;
            (*instance_ptr)->count -= 1;
            if (((*instance_ptr)->count) == 0) {
                delete *instance_ptr;
            }
            *instance_ptr = new OnlyChar(newstr);
            return newstr[num];
        }
    };
    ProxyStr operator[] (int i) const {
        return ProxyStr(*this, i);
    }
    ProxyStr operator[] (int i) {
        return ProxyStr(*this, i);
    }
    ~String() {
        if (instance != 0) {
            instance->count -= 1;
            if (instance->count == 0) {
                delete instance;
            }
        }
    }
};
