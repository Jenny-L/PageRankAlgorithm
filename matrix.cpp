//
// Created by Jenny Ly on 2018-10-05.
//

#include "matrix.hpp"
#include <cmath>
#include <iostream>

using namespace std;

~matrix() {
    delete matrix;
}

void matrix::printmatrix() {
    for(int i = 0; i < matrixSize; i++) {
        cout << matrix[i];
    }
}

void matrix::set_value(int x, int y, int value) {
    matrix[x * sideLength + y] = value;
}

int matrix::get_value(int x, int y) {
    return matrix[x * sideLength + y];
}

void matrix::clear() {
    for(int i = 0; i < matrixSize; i++) {
        matrix[i] = 0;
    }
}

matrix* matrix::identity(matrix m) {
    return new matrix(m);
}

std::ostream& operator<<(std::ostream& os, const matrix& obj){
    for(int i = 0; i < obj.matrixSize; i++) {
        if (obj.matrixSize % obj.sideLength == 0) {
            os << endl;
        }
        os << obj.matrix[i] << " ";
    }
}

bool operator==(const matrix& m1, const matrix& m2) {
    return (m1.matrixSize == m2.matrixSize)
}

bool operator!=(const matrix& m1, const matrix& m2) {
    return !operator==(m1,m2);
}

bool operator<(const matrix& m1, const matrix& m2) {
   return (m1.matrixSize < m2.matrixSize);
}

bool operator >(const matrix& m1, const matrix& m2) {
    return  (m2.matrixSize < m1.matrixSize);
}

bool operator<=(const matrix& m1, const matrix& m2) {
    return !operator>(m1.matrixSize, m2.matrixSize);
}

bool operator>=(const matrix&m1, const matrix& m2) {
    return !operator<(m1.matrixSize, m2.matrixSize);
}

//Prefix
matrix& operator++(matrix& m){
    for (int i = 0; i < m.matrixSize; i++) {
        m.matrix[i] = m.matrix[i] + 1;
    }
    return m;
}

//Postfix
matrix operator++(matrix& m, int value) {
    matrix temp(m);
    operator++(m);
    return temp;
}

matrix& operator+=(matrix& m1, const matrix& m2) {
    for (int i = 0; i < m1.matrixSize; i++) {
        m1.matrix[i] = m1.matrix[i] + m2.matrix[i];
    }
    return m1;
}

matrix operator+(const matrix& m1, const matrix& m2) {
    matrix m3;
    for (int i = 0; i < m1.matrixSize; i++) {
        m3.matrix[i] = m1.matrix[i] + m2.matrix[i];
    }
    return m3;
}

matrix& operator-=(matrix& m1, const matrix& m2) {
    for (int i = 0; i < m1.matrixSize; i++) {
        m1.matrix[i] = m1.matrix[i] + m2.matrix[i];
    }
    return m1;
}

matrix operator-(const matrix& m1) {
    matrix m3;
    for (int i = 0; i < this.matrixSize; i++) {
        m3.matrix[i] = m1.matrix[i] + m2.matrix[i];
    }
    return m3;
}




