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

