#include "rect.hpp"
#include <iostream>

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


Bochka::Bochka() {
    volume = 0;
    p_water = 0;
    p_alch = 0;
    water = 0;
    alch = 0;
}

Bochka::Bochka(double vol, double p_a) {
    volume = vol;
    p_water = 100 - p_a;
    p_alch = p_a;
    water = volume * p_water / 100;
    alch = volume - water;
}

double Bochka::get_palch() {
    return p_alch;
}

double Bochka::get_alch() {
    return alch;
}

double Bochka::get_pwater() {
    return p_water;
}

double Bochka::get_water() {
    return water;
}

double Bochka::get_volume() {
    return volume;
}

void Bochka::set_volume(double v) {
    volume = v;
}

void Bochka::set_p_water(double p_w) {
    p_water = p_w;
}

void Bochka::set_p_alch(double p_a) {
    p_alch = p_a;
}

void Bochka::set_alch(double a) {
    alch = a;
}

void Bochka::set_water(double w) {
    water = w;
}

void Bochka::transfer(double vl, Bochka& b) {
    double p_w2 = b.get_pwater();
    double p_a2 = b.get_palch();
    double w_2 = vl * p_w2 / 100.0;
    double a_2 = vl * p_a2 / 100.0;
    water += w_2;
    alch += a_2;
    volume += vl;
    p_alch = alch * 100 / volume;
    p_water = 100 - p_alch;
    double v = b.get_volume() - vl;
    double a2 = b.get_alch() - a_2;
    double w2 = b.get_water() - w_2;
    b.set_volume(v);
    b.set_alch(a2);
    b.set_water(w2);
}

//2.2 ---------------------------------------------------------
Matrix::Matrix(int n) : rows(n), cols(n) {
    matrix = new double*[rows];
    for (int i=0; i<rows; i+=1) {
        matrix[i] = new double[cols];
}

    for (int i=0; i<rows; i+=1) {
        for (int j=0; j<cols; j+=1){
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
}

Matrix::Matrix(int m, int n, double fill_value) : rows(m), cols(n) {
    matrix = new double*[n];
    for (int i=0; i<rows; i+=1) {
        matrix[i] = new double[m];
}

    for (int i=0; i<rows; i+=1) {
        for (int j=0; j<cols; j+=1){
            matrix[i][j] = fill_value;
        }
    }
}

Matrix::Matrix(const Matrix &p) : rows(p.rows), cols(p.cols) {
    matrix = new double*[rows];
    for (int i=0; i<rows; i+=1) {
        matrix[i] = new double[cols];    
    }
    for (int i=0; i<rows; i+=1) {
        for (int j=0; j<cols; j+=1) {
            matrix[i][j] = p.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i=0; i<rows; i+=1) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double Matrix::get(int i, int j) {
    return matrix[i][j];
}

void Matrix::set(int i, int j, double value) {
    matrix[i][j] = value;
}

int Matrix::get_height() {
    return rows;
}

int Matrix::get_width() {
    return cols;
}

void Matrix::negate() {
    Matrix p(*this);
    for (int i=0; i<rows; i+=1) {
        for (int j=0; j<cols; j+=1) {
            matrix[i][j] = p.matrix[i][j];
        }
    }
}

void Matrix::add_in_place(Matrix &other) {
    if (rows != other.rows || cols != other.cols) {
        std::cout << "The sizes of matrixes do not match!" << std::endl;
        throw "Error:: not correct size!";
    }
    
    for (int i=0; i<rows; i+=1) {
        for (int j=0; j<cols; j+=1) {
            matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
}


Matrix Matrix::multiply(Matrix &other) {
    if ( cols != other.rows) {
        std::cout << "The sizes of matrixes do not match!" << std::endl;
        throw "Error: not correct size!";
    }
    Matrix mult(rows, other.cols);
    for (int i=0; i<mult.rows; i+=1) {
        for (int l=0; l<mult.cols; l+=1) {
            for (int j=0; j<cols; j+=1) {
                mult.matrix[i][l] += matrix[i][j] * other.matrix[j][l];
            }
        }
    }
    return mult;
}

Matrix& Matrix::operator=(const Matrix &p) {
    if (this != &p) {
        for (int i=0; i<rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        
        rows = p.rows;
        cols = p.cols;
        matrix = new double*[rows];
        for (int i=0; i<rows; i++) {
            matrix[i] = new double[cols];
            for (int j=0; j<cols; j++) {
                matrix[i][j] = p.matrix[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::power(int n) {
    Matrix p(*this);
    for (int i=1; i<n; i+=1) {
        p = p.multiply(*this);
    }
    return p;
}

int fib(int n) {
    Matrix q(2, 2, 1);
    q.set(1, 1, 0);
    q = q.power(n);
    return q.get(0, 1);
}
