//
// Created by Jenny Ly on 2018-10-05.
//
#include <cmath>
#include <ostream>

using namespace std;

class matrix {

private:
    int sideLength;
    int matrixSize;
    int *matrixArray;
public:
    //constructor with default parameter
    matrix(int input = 1) : sideLength(input), matrixSize(pow(sideLength, sideLength)), matrixArray(new int[matrixSize]) {
        for(int i = 0; i < matrixSize; i++) {
            this->matrixArray[i] == 0.0;
        }
    }
    //copy constructor
    matrix(const matrix& m): sideLength(m.sideLength), matrixSize(m.sideLength), matrixArray(new int[matrixSize]){}
    //deconstructor
    ~matrix() {delete[] matrixArray;}
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

