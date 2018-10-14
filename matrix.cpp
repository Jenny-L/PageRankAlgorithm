/**
 * matrix.cpp
 * This class uses a one dimensional array and treats it as a 2-D array.
 * The matrix contains getters and setters to modify the array along with
 * overriden uniary and binary operators.
 *
 * @author Jenny Ly
 * @version 2018-10-05
 */

#include "matrix.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

const double TOLERENCE = 0.0001;

using namespace std;

/**
 * Default constructor
 */
matrix::matrix() : sideRow(DEFAULTSIZE), sideColumn(DEFAULTSIZE), matrixSize(DEFAULTSIZE * DEFAULTSIZE), matrixArray(new double[matrixSize]) {
    this->matrixArray[0] = 0.0;
}

/**
 * 1 parameter constructor which takes in a length and creates an l * l array
 * @param input int
 */
matrix::matrix(int input) : sideRow(input), sideColumn(input), matrixSize(input * input)  {
    if (input <= 0) {
        throw invalid_argument("input side length is a negative integer");
    } else {
        matrixArray = new double[matrixSize];
    }
    for(int i = 0; i < matrixSize; i++) {
        this->matrixArray[i] = 0.0;
    }
}

/**
 * 2 parameter constructor which takes in a row and column and creates an r * c matrix
 * @param r int
 * @param c int
 */
matrix::matrix(int r, int c) : sideRow(r), sideColumn(c), matrixSize(r * c)  {
    if (r <= 0 || c <= 0) {
        throw invalid_argument("input r or c  is a negative integer");
    } else {
        matrixArray = new double[matrixSize];
    }
    for(int i = 0; i < matrixSize; i++) {
        this->matrixArray[i] = 0.0;
    }
}

/**
 * takes in an array of value and creates a sqaure array to but the values in
 * @param arrayValues vector<double>
 */
matrix::matrix(vector<double> arrayValues) {
    int arraySize = arrayValues.size();
    int sqrtArraySize = sqrt(arraySize);
    sideRow = sqrtArraySize;
    sideColumn = sqrtArraySize;
    matrixSize = sideRow * sideColumn;
    if (sqrtArraySize * sqrtArraySize != arraySize) {
    throw invalid_argument("input array is not a perfect square");
    } else {
    matrixArray = new double[matrixSize];
    }
    for(int i = 0; i < arraySize; i++) {
    this->matrixArray[i] = arrayValues[i];
    }
}

/**
 * Copy constructor
 * @param m const
 */
matrix::matrix(const matrix& m): sideColumn(m.sideColumn), sideRow(m.sideRow), matrixSize(m.sideColumn * m.sideRow), matrixArray(new double[matrixSize]){
    for (int i = 0; i < m.matrixSize; i++) {
        this->matrixArray[i] = m.matrixArray[i];
    }
}

/**
 * Destructor
 */
matrix::~matrix() {delete[] matrixArray;}

/**
 * Setter for value
 * @param x int
 * @param y int
 * @param value double
 */
void matrix::set_value(int x, int y, double value) {
    if (x >= sideRow || x < 0) {
        throw invalid_argument("input x contains an invalid value");
    }
    if (y >= sideColumn || y < 0) {
        throw invalid_argument("input y contains an invalid value");
    }
    matrixArray[x * sideRow + y] = value;
}

/**
 * Getter for value
 * @param x int
 * @param y int
 * @return value double
 */
const double matrix::get_value(int x, int y) {
    if (x >= sideRow || x < 0) {
        throw invalid_argument("input x contains an invalid value");
    }
    if (y >= sideColumn || y < 0) {
        throw invalid_argument("input y contains an invalid value");
    }
    double value = matrixArray[x * sideRow + y];
    return value;
}

/**
 * Change all values in array to 0.0
 */
void matrix::clear() {
    for(int i = 0; i < matrixSize; i++) {
        matrixArray[i] = 0.0;
    }
}

/**
 * Overloaded friend insertion opperator. Prints out values in a matrix shape.
 * @param os std::ostream
 * @param obj matrix&
 * @return os std::ostream
 */
std::ostream& operator<<(std::ostream& os, matrix& obj){
    double objValue;
    int rowSize = obj.get_row_size();
    int columnSize = obj.get_column_size();
    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < columnSize; j++) {
            objValue = obj.get_value(i, j);
            os << fixed << setprecision(2) << objValue << " ";
            if ((j + 1) % rowSize == 0) {
                os << endl;
            }
        }
    }
    return os;
}

/**
 * Overloaded ==
 * Checks if double is within a tolerance range.
 * @param m1 matrix&
 * @param m2 matrix&
 * @return true if within tolerance, else false
 */
bool operator==(const matrix& m1, const matrix& m2) {
    if(m1.matrixSize != m2.matrixSize) {
        return false;
    }
    for (int i = 0; i < m1.matrixSize; i++) {
        if ((abs(m1.matrixArray[i] - m2.matrixArray[i])) > TOLERENCE){
            return false;
        }
    }
    return true;
}

/**
 * != overloaded. checks if 2 matrix are no equal
 * @param m1 matrix&
 * @param m2 matrix&
 * @return bool
 */
bool operator!=(const matrix& m1, const matrix& m2) {
    return !operator==(m1,m2);
}

/**
 * < overloaded. checks if m1's size  < m2's size
 * @param m1 matrix&
 * @param m2 matrix&
 * @return bool
 */
bool operator<(const matrix& m1, const matrix& m2) {
   return (m1.matrixSize < m2.matrixSize);
}

/**
 * < overloaded. checks if m1's size  > m2's size
 * @param m1 matrix&
 * @param m2 matrix&
 * @return bool
 */
bool operator>(const matrix& m1, const matrix& m2) {
    return  (m2.matrixSize < m1.matrixSize);
}

/**
 * < overloaded. checks if m1's size  <= m2's size
 * @param m1 matrix&
 * @param m2 matrix&
 * @return bool
 */
bool operator<=(const matrix& m1, const matrix& m2) {
    return !operator>(m1.matrixSize, m2.matrixSize);
}

/**
 * < overloaded. checks if m1's size  >= m2's size
 * @param m1 matrix&
 * @param m2 matrix&
 * @return bool
 */
bool operator>=(const matrix&m1, const matrix& m2) {
    return !operator<(m1.matrixSize, m2.matrixSize);
}

/**
 * Prefix incrementer. increments every value in matrix by one
 * @return matrix&
 */
matrix& matrix::operator++(){
    for (int i = 0; i < this->matrixSize; i++) {
        this->matrixArray[i] = this->matrixArray[i] + 1.0;
    }
    return *this;
}

/**
 * Postfix incrementer. increments every value in matrix by one
 * @return matrix &
 */
matrix matrix::operator++(int) {
    matrix temp(*this);
    operator++();
    return temp;
}

/**
 * Prefix decrementer. decrements every value in matrix by one
 * @return matrix&
 */
matrix& matrix::operator--(){
    for (int i = 0; i < this->matrixSize; i++) {
        this->matrixArray[i] = this->matrixArray[i] - 1.0;
    }
    return *this;
}

/**
 * Postfix decrementer. decrements every value in matrix by one
 * @return matrix&
 */
matrix matrix::operator--(int) {
    matrix temp(*this);
    operator--();
    return temp;
}

/**
 * += overloader. does matrix addition and return result to *this
 * @return matrix&
 */
matrix& matrix::operator+=(const matrix &m1) {
    if (this->matrixSize != m1.matrixSize) {
        throw invalid_argument("Cannot add matrices because their size are different");
    }
    for (int i = 0; i < m1.matrixSize; i++) {
        this->matrixArray[i] = this->matrixArray[i] + m1.matrixArray[i];
    }
    return *this;
}

/**
 * Performs matrix addition
 * @param m1 matrix
 * @param m2 matrix
 * @return m1 matrix
 */
matrix operator+(matrix m1, const matrix &m2) {
    m1 += m2;
    return m1;
}

/**
 * Performs matrix subtraction and place results in *this
 * @param m1
 * @return matrix&
 */
matrix& matrix::operator-=(const matrix &m1) {
    if (this->matrixSize != m1.matrixSize) {
        throw invalid_argument("Cannot subtract matrices because their size are different");
    }
    for (int i = 0; i < m1.matrixSize; i++) {
        this->matrixArray[i] = this->matrixArray[i] - m1.matrixArray[i];
    }
    return *this;
}

/**
 * Performs matrix subtraction
 * @param m1 matrix
 * @param m2 matrix
 * @return matrix
 */
matrix operator-(matrix m1, const matrix &m2) {
    m1 += m2;
    return m1;
}

/**
 * Swap variable of *this with another matrix
 * @param m matrix&
 * @return *this
 */
matrix& matrix::operator=(matrix &m) {
    swap(*this, m);
    return *this;
}

/**
 * Swap the varible of 2 matrix
 * @param m1 matrix
 * @param m2 matrix
 */
void swap(matrix &m1, matrix &m2) {
    using std::swap;
    swap(m1.sideColumn, m2.sideColumn);
    swap(m1.sideRow, m2.sideRow);
    swap(m1.matrixArray, m2.matrixArray);
    swap(m1.matrixSize, m2.matrixSize);
}

/**
 * Performs matrix multiplication
 * @param m1 matrix
 * @return matrix
 */
matrix& matrix::operator*=(matrix &m1) {
    int nRows = this->sideRow;
    int nColumn = m1.sideColumn;
    int commonSize = m1.sideColumn;
    matrix* result_matrix = new matrix(nRows, nColumn);
    if (this->sideColumn != m1.sideRow ) {
        throw invalid_argument("column length of matrix 1 does != row length of matrix 2");
    }
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nColumn; j++) {
            double product = 0.0;
            for(int k = 0; k < commonSize; k++) {
                product = product + (this->get_value(i, k) * m1.get_value(j, k));
            }
            product = product + 0.0;
            result_matrix->set_value(i, j, product);
        }
    }
    *this = *result_matrix;
    return *this;
}

/**
 * Performs muiltplication of a matrix and a double
 * @param probability double
 * @param m matrix
 * @return matrix
 */
matrix operator*(double probability, matrix &m) {
    for(int x = 0; x < m.get_row_size(); x++) {
        for(int y = 0; y < m.get_column_size(); y++) {
            double newResult = m.get_value(x, y) * probability;
            m.set_value(x, y, newResult);
        }
    }
    return m;
}

/**
 * Performs matrix multiplication
 * @param result matrix
 * @param m matrix
 * @return matrix
 */
matrix operator*(matrix &result, matrix &m) {
    result *= m;
    return result;
}

/**
 *
 * @return
 */
int matrix::get_row_size() const {
    return sideRow;
}

/**
 * gets the column size
 * @return sideColumn
 */
int matrix::get_column_size() const {
    return sideColumn;
}

/**
 * calculates the sum of the first column
 * @return sum double
 */
double matrix::find_sum_first_column() {
    double sum = 0;
    for (int i = 0; i < get_column_size(); i++) {
        sum += get_value(0, i);
    }
    return sum;
}

/**
 * Converts markov matrix to a percent
 * @return matrix&
 */
matrix& matrix::convert_markov_to_percent() {
    double sum = this->find_sum_first_column();
    for (int i = 0; i < this->get_row_size(); i++) {
        for(int j = 0; j < this->get_column_size(); j++) {
            double proportion = this->get_value(i, j) / sum * 100;
            this->set_value(i, j, proportion);
        }
    }
    return *this;
}

/**
 * Calculates the sum of each row
 * @return vector<double>
 */
vector<double> matrix::row_sum_vector() {
    vector<double> sum_container;
    for (int x = 0; x < this->get_row_size(); x++) {

        int sum = 0;
        for(int y = 0; y < this->get_column_size(); y++) {
            sum += get_value(x, y);
        }
        sum_container.push_back(sum);
    }
    return sum_container;
}







