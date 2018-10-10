//
// Created by Jenny Ly on 2018-10-05.
//
#include <cmath>
#include <ostream>

using namespace std;

class matrix {

private:
    const int DEFAULTSIZE = 1;
    int sideRow;
    int sideColumn;
    int matrixSize;
    int *matrixArray;
public:
    //default constructor
    matrix() : sideRow(DEFAULTSIZE), sideColumn(DEFAULTSIZE), matrixSize(DEFAULTSIZE * DEFAULTSIZE), matrixArray(new int[matrixSize]) {
        this->matrixArray[0] == 0.0;
    }
    //constructor with one parameter
    matrix(int input) : sideRow(input), sideColumn(input), matrixSize(input * input)  {
        if (input <= 0) {
            throw invalid_argument("input side length is a negative integer");
        } else {
            matrixArray = new int[matrixSize];
        }
        for(int i = 0; i < matrixSize; i++) {
            this->matrixArray[i] == 0.0;
        }
    }
    //constructor with 2 parameter
    matrix(int r, int c) : sideRow(r), sideColumn(c), matrixSize(r * c)  {
        if (r <= 0 || c <= 0) {
            throw invalid_argument("input r or c  is a negative integer");
        } else {
            matrixArray = new int[matrixSize];
        }
        for(int i = 0; i < matrixSize; i++) {
            this->matrixArray[i] == 0.0;
        }
    }
    //copy constructor
    matrix(const matrix& m): sideColumn(m.sideColumn), sideRow(m.sideRow), matrixSize(m.sideColumn * m.sideRow), matrixArray(new int[matrixSize]){}
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

