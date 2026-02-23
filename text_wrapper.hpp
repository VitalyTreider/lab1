#ifndef TEXT_WRAPPER_HPP
#define TEXT_WRAPPER_HPP

#include "my_string.hpp"

class TextWrapper {
private:
    MyString str;
    int ln_wth;
public:
    TextWrapper();
    TextWrapper(MyString &s, int ln);
    ~TextWrapper();
    void print_wrapped();
};

#endif

