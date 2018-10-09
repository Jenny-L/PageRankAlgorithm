//
// Created by Jenny Ly on 2018-10-05.
//

#include "Matrix.hpp"
#include <cmath>
#include <iostream>

using namespace std;

void Matrix::printMatrix() {
    for(int i = 0; i < matrixSize; i++) {
        cout << matrix[i];
    }
}

void Matrix::set_value(int x, int y, int value) {
    matrix[x * sideLength + y] = value;
}

int Matrix::get_value(int x, int y) {
    return matrix[x * sideLength + y];
}

void Matrix::clear() {
    for(int i = 0; i < matrixSize; i++) {
        matrix[i] = 0;
    }
}

Matrix* Matrix::identity(Matrix m) {
    return new Matrix(m);
}
