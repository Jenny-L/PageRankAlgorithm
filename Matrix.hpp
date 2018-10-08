//
// Created by Jenny Ly on 2018-10-05.
//
#include <cmath>
using namespace std;

class Matrix {
private:
    int sideLength;
    int matrixSize;
    int *matrix;
public:
    Matrix(int input = 1) : sideLength(input), matrixSize(pow(sideLength, sideLength)), matrix(new int[matrixSize]){};
    void printMatrix();
    void set_value(int x, int y, int value);
    int get_value(int x, int y);
};

