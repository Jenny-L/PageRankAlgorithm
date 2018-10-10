//
// Created by Jenny Ly on 2018-10-05.
//
#include <cmath>
#include <ostream>

using namespace std;

class matrix {
//private:
public:
    int sideLength;
    int matrixSize;
    int *matrix;
//public:
    matrix(int input = 1) : sideLength(input), matrixSize(pow(sideLength, sideLength)), matrix(new int[matrixSize]){};
    matrix(const matrix& m): sideLength(m.sideLength), matrixSize(m.sideLength), matrix(new int[matrixSize]){};
    ~matrix();
    void printmatrix();
    void set_value(int x, int y, int value);
    int get_value(int x, int y);
    void clear();
    matrix* identity(matrix m);
    friend std::ostream& operator<<(std::ostream& os, const matrix& obj);
    friend bool operator==(const matrix& m1, const matrix& m2);
    friend bool operator!=(const matrix& m1, const matrix& m2);
    friend bool operator<(const matrix& m1, const matrix& m2);
    friend bool operator>(const matrix& m1, const matrix& m2);
    friend bool operator<=(const matrix& m1, const matrix& m2);
    friend bool operator>=(const matrix& m1, const matrix& m2);
    friend matrix& operator++();
    friend matrix operator++(int);
    matrix& operator+=(const matrix& m1);
    matrix operator+(const matrix& m);
    friend matrix& operator-=(const matrix& m1,const matrix& m2);
    friend matrix operator-(const matrix& m, const matrix& m1);
};

