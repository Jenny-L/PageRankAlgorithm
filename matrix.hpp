/**
 * matrix.hpp
 * This class uses a one dimensional array and treats it as a 2-D array.
 * The matrix contains getters and setters to modify the array along with
 * overriden uniary and binary operators.
 *
 * @author Jenny Ly
 * @version 2018-10-05
 */

#ifndef LAB4_MATRIX_HPP
#define LAB4_MATRIX_HPP
#include <cmath>
#include <ostream>
#include <iostream>
#include <vector>


using namespace std;

class matrix {

private:
    const int DEFAULTSIZE = 1;
    int sideRow;
    int sideColumn;
    int matrixSize;
protected:
    double *matrixArray;
public:
    matrix();
    matrix(int input);
    matrix(int r, int c);
    matrix(vector<double> arrayValues);
    matrix(const matrix& m);
    ~matrix();
    int get_row_size() const;
    int get_column_size() const;
    void set_value(int x, int y, double value);
    const double get_value(int x, int y);
    void clear();
    friend std::ostream& operator<<(std::ostream& os, matrix& obj);
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
    friend matrix operator*(double number, matrix& m);
    friend void swap(matrix &m1, matrix &m2);
    matrix& operator=(matrix &other);
    vector<double> row_sum_vector();
    double find_sum_first_column();
    matrix& convert_markov_to_percent();

};


#endif