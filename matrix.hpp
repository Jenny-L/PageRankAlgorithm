//
// Created by Jenny Ly on 2018-10-05.
//
#include <cmath>
#include <ostream>


using namespace std;

class matrix {

private:
    const int DEFAULTSIZE = 1;
    //const double TOLERANCE = 0.01;
    int sideRow;
    int sideColumn;
    int matrixSize;
    double *matrixArray;
public:
    //default constructor
    matrix() : sideRow(DEFAULTSIZE), sideColumn(DEFAULTSIZE), matrixSize(DEFAULTSIZE * DEFAULTSIZE), matrixArray(new double[matrixSize]) {
        this->matrixArray[0] = 0.0;
    }
    //constructor with one parameter
    matrix(int input) : sideRow(input), sideColumn(input), matrixSize(input * input)  {
        if (input <= 0) {
            throw invalid_argument("input side length is a negative integer");
        } else {
            matrixArray = new double[matrixSize];
        }
        for(int i = 0; i < matrixSize; i++) {
            this->matrixArray[i] = 0.0;
        }
    }
    //constructor with 2 parameter
    matrix(int r, int c) : sideRow(r), sideColumn(c), matrixSize(r * c)  {
        if (r <= 0 || c <= 0) {
            throw invalid_argument("input r or c  is a negative integer");
        } else {
            matrixArray = new double[matrixSize];
        }
        for(int i = 0; i < matrixSize; i++) {
            this->matrixArray[i] = 0.0;
        }
    }
    //constructor with array as parameter
    matrix(double* arrayValues) {
        int arraySize = sizeof(arrayValues);
        if (sqrt(arraySize) * sqrt(arraySize) != arraySize) {
            throw invalid_argument("input array is not a perfect square");
        }
        for(int i = 0; i < arraySize; i++) {
            this->matrixArray[i] = arrayValues[i];
        }
    }

    void set_value(int x, int y, double value);
    int get_value(int x, int y);
    //copy constructor
    matrix(const matrix& m): sideColumn(m.sideColumn), sideRow(m.sideRow), matrixSize(m.sideColumn * m.sideRow), matrixArray(new double[matrixSize]){
        for (int i = 0; i < m.matrixSize; i++) {
            this->matrixArray[i] = m.matrixArray[i];
        }
    }
    //deconstructor
    ~matrix() {delete[] matrixArray;}
    void printmatrix();
    void clear();

    friend std::ostream& operator<<(std::ostream& os, const matrix& obj);

    friend bool operator==(const matrix& m1, const matrix& m2);
    friend bool operator!=(const matrix& m1, const matrix& m2);
    friend bool operator<(const matrix& m1, const matrix& m2);
    friend bool operator>(const matrix& m1, const matrix& m2);
    friend bool operator<=(const matrix& m1, const matrix& m2);
    friend bool operator>=(const matrix& m1, const matrix& m2);
    matrix& operator++();
    matrix operator++(int);
    matrix& operator--();
    matrix operator--(int);

    matrix& operator+=(const matrix& m1);
    friend matrix operator+(matrix m1, const matrix& m2);
    matrix& operator-=(const matrix& m1);
    friend matrix operator-(matrix m1, const matrix& m2);
    matrix& operator*=(matrix& m1);
    friend matrix operator*(matrix &m1, matrix& m2);

    friend void swap(matrix &m1, matrix &m2);
    matrix& operator=(matrix &other);


};

