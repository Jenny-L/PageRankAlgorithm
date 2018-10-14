//
// Created by Jenny Ly on 2018-10-05.
//

#include "matrix.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

const double TOLERENCE = 0.0001;

using namespace std;

matrix::matrix() : sideRow(DEFAULTSIZE), sideColumn(DEFAULTSIZE), matrixSize(DEFAULTSIZE * DEFAULTSIZE), matrixArray(new double[matrixSize]) {
    this->matrixArray[0] = 0.0;
}

matrix::matrix(int input) : sideRow(input), sideColumn(input), matrixSize(input * input)  {
    if (input <= 0) {
        throw invalid_argument("input side length is a negative integer");
    } else {
        matrixArray = new double[matrixSize];
    }
    for(int i = 0; i < matrixSize; i++) {
        this->matrixArray[i] = 0.0;
    }
}

matrix::matrix(int r, int c) : sideRow(r), sideColumn(c), matrixSize(r * c)  {
    if (r <= 0 || c <= 0) {
        throw invalid_argument("input r or c  is a negative integer");
    } else {
        matrixArray = new double[matrixSize];
    }
    for(int i = 0; i < matrixSize; i++) {
        this->matrixArray[i] = 0.0;
    }
}

matrix::matrix(vector<double> arrayValues) {
    int arraySize = arrayValues.size();
    int sqrtArraySize = sqrt(arraySize);
    sideRow = sqrtArraySize;
    sideColumn = sqrtArraySize;
    matrixSize = sideRow * sideColumn;
    if (sqrtArraySize * sqrtArraySize != arraySize) {
    throw invalid_argument("input array is not a perfect square");
    } else {
    matrixArray = new double[matrixSize];
    }
    for(int i = 0; i < arraySize; i++) {
    this->matrixArray[i] = arrayValues[i];
    }
}

matrix::matrix(const matrix& m): sideColumn(m.sideColumn), sideRow(m.sideRow), matrixSize(m.sideColumn * m.sideRow), matrixArray(new double[matrixSize]){
    for (int i = 0; i < m.matrixSize; i++) {
        this->matrixArray[i] = m.matrixArray[i];
    }
}

matrix::~matrix() {delete[] matrixArray;}

void matrix::set_value(int x, int y, double value) {
    if (x >= sideRow || x < 0) {
        throw invalid_argument("input x contains an invalid value");
    }
    if (y >= sideColumn || y < 0) {
        throw invalid_argument("input y contains an invalid value");
    }
    matrixArray[x * sideRow + y] = value;
}

const double matrix::get_value(int x, int y) {
    if (x >= sideRow || x < 0) {
        throw invalid_argument("input x contains an invalid value");
    }
    if (y >= sideColumn || y < 0) {
        throw invalid_argument("input y contains an invalid value");
    }
    double value = matrixArray[x * sideRow + y];
    return value;
}


void matrix::clear() {
    for(int i = 0; i < matrixSize; i++) {
        matrixArray[i] = 0.0;
    }
}

std::ostream& operator<<(std::ostream& os, matrix& obj){
    double objValue;
    int rowSize = obj.get_row_size();
    int columnSize = obj.get_column_size();
    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < columnSize; j++) {



            objValue = obj.get_value(i, j);
            os << fixed << setprecision(4) << objValue << " ";
            if ((j + 1) % rowSize == 0) {
                os << endl;
            }
        }
    }
    return os;
}

bool operator==(const matrix& m1, const matrix& m2) {
    if(m1.matrixSize != m2.matrixSize) {
        return false;
    }
    for (int i = 0; i < m1.matrixSize; i++) {
        if ((abs(m1.matrixArray[i] - m2.matrixArray[i])) > TOLERENCE){
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

bool operator>(const matrix& m1, const matrix& m2) {
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
    using std::swap;
    swap(m1.sideColumn, m2.sideColumn);
    swap(m1.sideRow, m2.sideRow);
    swap(m1.matrixArray, m2.matrixArray);
    swap(m1.matrixSize, m2.matrixSize);
}

matrix& matrix::operator*=(matrix &m1) {
    int nRows = this->sideRow;
    int nColumn = m1.sideColumn;
    int commonSize = m1.sideColumn;
    matrix* result_matrix = new matrix(nRows, nColumn);
    if (this->sideColumn != m1.sideRow ) {
        throw invalid_argument("column length of matrix 1 does != row length of matrix 2");
    }
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nColumn; j++) {
            double product = 0.0;
            for(int k = 0; k < commonSize; k++) {
                product = product + (this->get_value(i, k) * m1.get_value(j, k));
            }
            product = product + 0.0;
            result_matrix->set_value(i, j, product);
        }
    }
    *this = *result_matrix;
    return *this;
}

matrix operator*(double probability, matrix &m) {
    for(int x = 0; x < m.get_row_size(); x++) {
        for(int y = 0; y < m.get_column_size(); y++) {
            double newResult = m.get_value(x, y) * probability;
            m.set_value(x, y, newResult);
        }
    }
    return m;
}

matrix operator*(matrix &result, matrix &m) {
    result *= m;
    return result;
}

double* matrix::get_matrix() {
    return matrixArray;
}

int matrix::get_row_size() const {
    return sideRow;
}

int matrix::get_column_size() const {
    return sideColumn;
}

vector<double> matrix::row_sum_vector() {
    vector<double> sum_container;
    for (int x = 0; x < this->get_row_size(); x++) {

        int sum = 0;
        for(int y = 0; y < this->get_column_size(); y++) {
            sum += get_value(x, y);
            //cout << "x = " << x << "y = " << y << endl;
        }
        sum_container.push_back(sum);
        //cout << "column sum " << sum << endl;
    }
    return sum_container;
}

matrix& matrix::set_all_values_to(double value) {
    for(int x = 0; x < this->get_row_size(); x++) {
        for(int y = 0; y < this->get_column_size(); y++) {
            this->set_value(x , y, value);
        }
    }
}







