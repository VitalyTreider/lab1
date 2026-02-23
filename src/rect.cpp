#include "rect.hpp"
#include <iostream>
#include <cstring>

Rect::Rect() {
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    std::cout << "Constructor init ZEROs" << std::endl;
}

Rect::Rect(int c11, int c22, int c33, int c44) {
    c1 = c11;
    c2 = c22;
    c3 = c33;
    c4 = c44;
    std::cout << "Constructor init clearly, adress: " << this << std::endl;
}

Rect::Rect(const Rect& r) {
    c1 = r.c1;
    c2 = r.c2;
    c3 = r.c3;
    c4 = r.c4;
    std::cout << "Constructor copy, adress: " << this << std::endl;
}

int Rect::get_left() {
    return c1;
}

int Rect::get_right() {
    return c2;
}

int Rect::get_top() {
    return c3;
}

int Rect::get_bottom() {
    return c4;
}

void Rect::set_all(int left, int right, int top, int bottom) {
    c1 = left;
    c2 = right;
    c3 = top;
    c4 = bottom;
}

void Rect::inflate(int amount) {
    c1 = c1 - amount;
    c2 = c2 + amount;
    c3 = c3 + amount;
    c4 = c4 - amount;
}

void Rect::inflate(int dw, int dh) {
    c1 = c1 - dw;
    c2 = c2 + dw;
    c3 = c3 + dh;
    c4 = c4 - dh;
}

void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom) {
    c1 = c1 - d_left;
    c2 = c2 + d_right;
    c3 = c3 + d_top;
    c4 = c4 - d_bottom;
}

void Rect::move(int x) {
    c1 = c1 + x;
    c2 = c2 + x;
}

void Rect::move(int x, int y) {
    c1 = c1 + x;
    c2 = c2 + x;
    c3 = c3 + y;
    c4 = c4 + y;
}

Rect bounding_rect(Rect r1, Rect r2) {
    int lt, rt, tp, bt;
    if (r1.get_left() > r2.get_left()) {
        lt = r2.get_left();
    } else { lt = r1.get_left(); }

    if (r1.get_right() < r2.get_right()) {
        rt = r2.get_right();
    } else { rt = r1.get_right(); }

    if (r1.get_top() < r2.get_top()) {
        tp = r2.get_top();
    } else { tp = r1.get_top(); }

    if (r1.get_bottom() > r2.get_bottom()) {
        bt = r2.get_bottom();
    } else { bt = r1.get_bottom(); }

    Rect r3(lt, rt, tp, bt);
    return r3;
}

void print_rect(Rect& r) {
    std::cout << "Left: " << r.get_left() << "; Right: " << r.get_right() << std::endl;
    std::cout << "Top: " << r.get_top() << "; Bottom: " << r.get_bottom() << std::endl;
}

int Rect::get_width() {
    int width = c2 - c1;
    return width;
}

int Rect::get_height() {
    int height = c3 - c4;
    return height;
}

int Rect::get_square() {
    int h = get_height();
    int w = get_width();
    int squar = w * h;
    return squar;
}

void Rect::set_width(int wd) {
    c2 = c1 + wd;
}

void Rect::set_height(int hg) {
    c3 = c4 + hg;
}

Rect::~Rect() {
    std::cout << "Object Rect deleted! Destructor applied, adress: " << this << std::endl;
}

