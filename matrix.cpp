#include "matrix.hpp"
#include <iostream>
#include <cstring>

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
