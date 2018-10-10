//
// Created by Jenny Ly on 2018-10-05.
//

#include "matrix.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

const double TOLERENCE = 0.01;

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


void matrix::clear() {
    for(int i = 0; i < matrixSize; i++) {
        matrixArray[i] = 0.0;
    }
}

std::ostream& operator<<(std::ostream& os, const matrix& obj){
    for(int i = 0; i < obj.matrixSize; i++) {
        if (i % obj.sideRow == 0) {
            os << endl;
        }
        os << fixed << setprecision(3) << obj.matrixArray[i] << " ";
    }
}

bool operator==(const matrix& m1, const matrix& m2) {
    if(m1.matrixSize != m2.matrixSize) {
        return false;
    }
    for (int i = 0; i < m1.matrixSize; i++) {
        if (!(m1.matrixArray[i] < m2.matrixArray[i] + TOLERENCE && m1.matrixArray[i] > m2.matrixArray[i] - TOLERENCE)){
            return false;
        }
    }
    return true;
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
matrix& matrix::operator++(){
    for (int i = 0; i < this->matrixSize; i++) {
        this->matrixArray[i] = this->matrixArray[i] + 1.0;
    }
    return *this;
}

//Postfix
matrix matrix::operator++(int) {
    matrix temp(*this);
    operator++();
    return temp;
}

//Prefix
matrix& matrix::operator--(){
    for (int i = 0; i < this->matrixSize; i++) {
        this->matrixArray[i] = this->matrixArray[i] - 1.0;
    }
    return *this;
}

//Postfix
matrix matrix::operator--(int) {
    matrix temp(*this);
    operator--();
    return temp;
}



matrix& matrix::operator+=(const matrix& m1) {
    if (this->matrixSize != m1.matrixSize) {
        throw invalid_argument("Cannot add matrices because their size are different");
    }
    for (int i = 0; i < m1.matrixSize; i++) {
        this->matrixArray[i] = this->matrixArray[i] + m1.matrixArray[i];
    }
    return *this;
}

matrix operator+(matrix m1, const matrix& m2) {
    m1 += m2;
    return m1;
}

matrix& matrix::operator-=(const matrix& m1) {
    if (this->matrixSize != m1.matrixSize) {
        throw invalid_argument("Cannot subtract matrices because their size are different");
    }
    for (int i = 0; i < m1.matrixSize; i++) {
        this->matrixArray[i] = this->matrixArray[i] - m1.matrixArray[i];
    }
    return *this;
}

matrix operator-(matrix m1, const matrix& m2) {
    m1 += m2;
    return m1;
}

//swap and assign
matrix& matrix::operator=(matrix &m) {
    swap(*this, m);
    return *this;
}

void swap(matrix &m1, matrix &m2) {
    matrix temp;
    temp = m1;
    m1 = m2;
    m2 = temp;
}

matrix& matrix::operator*=(matrix &m1) {
    int nRows = this->sideRow;
    int nColumn = m1.sideColumn;
    int commonSize = this->sideRow;
    if (this->sideColumn != m1.sideRow ) {
        throw invalid_argument("column length of matrix 1 does != row length of matrix 2");
    }
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nColumn; j++) {
            int product = 0;
            for(int k = 0; k < commonSize; k++) {
                product += this->get_value(i, k) * m1.get_value(k, j);
            }
            this->set_value(i, j, product);
        }
    }
    return *this;
}

matrix operator*(matrix result, matrix &m) {
    result *= m;
    return result;
}








