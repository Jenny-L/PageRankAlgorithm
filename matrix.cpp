//
// Created by Jenny Ly on 2018-10-05.
//

#include "matrix.hpp"
#include <cmath>
#include <iostream>

using namespace std;


void matrix::set_value(int x, int y, double value) {
    if (x >= sideRow || x < 0) {
        throw invalid_argument("input x contains an invalid value");
    }
    if (y >= sideColumn || y < 0) {
        throw invalid_argument("input y contains an invalid value");
    }
    matrixArray[x * sideRow + y] = value;
}

int matrix::get_value(int x, int y) {
    if (x >= sideRow || x < 0) {
        throw invalid_argument("input x contains an invalid value");
    }
    if (y >= sideColumn || y < 0) {
        throw invalid_argument("input y contains an invalid value");
    }
    return matrixArray[x * sideRow + y];
}

void matrix::printmatrix() {
    for(int i = 0; i < matrixSize; i++) {
        cout << matrixArray[i];
    }
}



void matrix::clear() {
    for(int i = 0; i < matrixSize; i++) {
        matrixArray[i] = 0.0;
    }
}

matrix* matrix::identity(matrix m) {
    return new matrixArray(m);
}

std::ostream& operator<<(std::ostream& os, const matrix& obj){
    for(int i = 0; i < obj.matrixSize; i++) {
        if (obj.matrixSize % obj.sideLength == 0) {
            os << endl;
        }
        os << obj.matrixArray[i] << " ";
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
        m3.matrix[i] = m1.matrixArray[i] + m2.matrixArray[i];
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
        m3.matrix[i] = m1.matrixArray[i] + m2.matrixArray[i];
    }
    return m3;
}




