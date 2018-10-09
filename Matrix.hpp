//
// Created by Jenny Ly on 2018-10-05.
//
#include <cmath>
#include <ostream>

using namespace std;

class Matrix {
private:
    int sideLength;
    int matrixSize;
    int *matrix;
public:
    Matrix(int input = 1) : sideLength(input), matrixSize(pow(sideLength, sideLength)), matrix(new int[matrixSize]){};
    Matrix(const Matrix& m): sideLength(m.sideLength), matrixSize(m.sideLength), matrix(new int[matrixSize]){};
    ~Matrix();
    void printMatrix();
    void set_value(int x, int y, int value);
    int get_value(int x, int y);
    void clear();
    void identity(Matrix m);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& obj);
    friend bool operator==(const Matrix& m1, const Matrix& m2);
    friend bool operator!=(const Matrix& m1, const Matrix& m2);
    friend bool operator<(const Matrix& m1, const Matrix& m2);
    friend bool operator>(const Matrix& m1, const Matrix& m2);
    Matrix& operator<=(const Matrix& m);
    Matrix& operator>=(const Matrix& m);
    Matrix& operator+=(const Matrix& m);
    friend Matrix operator+(Matrix mNew, const Matrix& m);
};

