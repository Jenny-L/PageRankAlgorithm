/**
 * connectivitymatrix.cpp
 * This class uses a one dimensional array and treats it as a 2-D array.
 * The matrix contains getters and setters to modify the array along with
 * overriden uniary and binary operators.
 *
 * @author Jenny Ly
 * @version 2018-10-05
 */

#include <iomanip>
#include "connectivitymatrix.hpp"

/**
 * Default constructor
 */
connectivitymatrix::connectivitymatrix(): matrix(){};

/**
 * 1 parameter constructor which takes in a length and creates an l * l array
 * @param input int
 */
connectivitymatrix::connectivitymatrix(int input): matrix(input){};

/**
 * 2 parameter constructor which takes in a row and column and creates an r * c matrix
 * @param r int
 * @param c int
 */
connectivitymatrix::connectivitymatrix(int r, int c): matrix(r,c){};

/**
 * takes in an array of value and creates a sqaure array to but the values in
 * @param arrayValues vector<double>
 */
connectivitymatrix::connectivitymatrix(vector<double> arrayValues): matrix(arrayValues){};

/**
 * Copy constructor
 * @param m const
 */
connectivitymatrix::connectivitymatrix(const matrix& m): matrix(m){};

/**
 * Destructor
 */
connectivitymatrix::~connectivitymatrix() {delete[] matrixArray;};

/**
 * Print out the final result as a percentage
 * @param os std::ostream
 * @param obj connectivitymatrix
 * @return std::ostream
 */
std::ostream& operator<<(std::ostream& os, connectivitymatrix &obj) {
    double objValue;
    int rowSize = obj.get_row_size();
    int columnSize = obj.get_column_size();
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < columnSize; j++) {
            objValue = obj.get_value(i, j);
            char c = 'A' + j;
            os << "Page " << c << ": ";
            os << fixed << setprecision(2) << objValue << "% ";
            if ((j + 1) % rowSize == 0) {
                os << endl;
            }
        }
    }
    return os;
}

/**
 * Overriden ++
 * adds 1 to every value of the matrix
 * @return connectivitymatrix
 */
connectivitymatrix& connectivitymatrix::operator++() {
    for(int i = 0; i < sum_container.size(); i++) {
        if (sum_container[i] == 0) {
            for(int y = 0; y < get_column_size(); y++) {
                int value = get_value(y, i);
                set_value(y, i, value + 1);
            }
            sum_container[i] = get_column_size();
        }
    }
    return *this;
}

/**
 * Convert connectivit matrix to importance
 * @return connectivitymatrix&
 */
connectivitymatrix& connectivitymatrix::connectivity_to_importance() {
    for (int x = 0; x < get_row_size(); x++) {
        for (int y = 0; y < get_column_size(); y++) {

            double value = get_value(x, y);
            if (value == 1) {
                double denominator = sum_container[y];
                double result = value / denominator;
                set_value(x, y, result);
            }
        }
    }
    return *this;
};
