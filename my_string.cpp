#include "my_string.hpp"
#include <iostream>
#include <cstring>

MyString::MyString() {
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char *s) {
    str = new char[strlen(s)+1];
    strcpy(str, s);
}

MyString::MyString(const MyString &s) {
    str = new char[strlen(s.str)+1];
    strcpy(str, s.str);
}

MyString& MyString::operator=(const MyString &s) {
    if (this != &s) {
        delete[] str;

        str = new char[strlen(s.str)+1];
        strcpy(str, s.str);
    }
    return *this;
}

MyString::~MyString() {
    delete[] str;
}

char MyString::get(int i) {
    return str[i];
};

void MyString::set(int i, char c) {
    str[i] = c;
}

void MyString::set_new_string(const char *s) {
    delete[] str;
    str = new char[strlen(s)+1];
    strcpy(str, s);
}

void MyString::print() {
    std::cout << "String: " << str<< std::endl;
}

void MyString::read_line() {
    delete[] str;

    char k;
    while (std::cin.get(k) && k != '\n') { }

    int cap = 10;
    str = new char[cap];
    int ln = 0;

    char c;
    while (std::cin.get(c) && c != '\n') {
        if (ln+1>cap) {
            cap=cap*2;
            char *str_new = new char[cap];
            for (int i=0; i<ln; i++) {
                str_new[i]=str[i];
            }
            delete[] str;
            str = str_new;
        }
        str[ln++]=c;
    }
    str[ln]='\0';
}
