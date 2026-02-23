#include "text_wrapper.hpp"
#include "my_string.hpp"
#include <iostream>
#include <cstring>

TextWrapper::TextWrapper() {
    ln_wth = 0;
}

TextWrapper::TextWrapper(MyString &s, int ln) {
    str = s;
    ln_wth = ln;
}

TextWrapper::~TextWrapper() {
    std::cout << "Object TextWrapper deleted!" << std::endl;
}

void TextWrapper::print_wrapped() {
    int j=0;
    int n = str.lns();
    while (j < n) { 
        int limit = j + ln_wth;

        if (limit >= n) {
            for (int i=j; i<n; i++) std::cout << str.get(i);
            std::cout << std::endl;
            break;
        }
        
        int k=-1;
        for (int i=j; i<limit; i++) {
            if (str.get(i) == ' ') k=i;
        }

        if (k != -1) {
            for (int i=j; i<k; i++) std::cout << str.get(i);
            std::cout << std::endl;
            j=k+1;
        } else {
            for (int i=j; i<limit; i++) std::cout <<str.get(i);
            std::cout << std::endl;
            j=limit;
        }
    }
}
