//
// Created by Jenny Ly on 2018-10-05.
//
#include <cmath>
#include <ostream>
#include <iostream>
#include <vector>


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
    matrix();
    //constructor with one parameter
    matrix(int input);
    //constructor with 2 parameter
    matrix(int r, int c);
    //constructor with array as parameter
    matrix(vector<double> arrayValues);

    void set_value(int x, int y, double value);
    int get_value(int x, int y);
    double* get_matrix();
    //copy constructor
    matrix(const matrix& m);
    //deconstructor
    ~matrix();
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

