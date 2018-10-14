/**
 * connectivitymatrix.cpp
 * This class uses a one dimensional array and treats it as a 2-D array.
 * The matrix contains getters and setters to modify the array along with
 * overriden uniary and binary operators.
 *
 * @author Jenny Ly
 * @version 2018-10-05
 */

#ifndef LAB4_CONNECTIVITYMATRIX_HPP
#define LAB4_CONNECTIVITYMATRIX_HPP


#include <fstream>
#include "matrix.hpp"

using namespace::std;

class connectivitymatrix: public matrix {
    vector<double> sum_container = this->row_sum_vector();

public:
    connectivitymatrix();
    connectivitymatrix(int);
    connectivitymatrix(int, int);
    connectivitymatrix(vector<double>);
    connectivitymatrix(const matrix&);
    ~connectivitymatrix();
    connectivitymatrix& operator++();
    friend std::ostream& operator<<(std::ostream& os, connectivitymatrix& obj2);
    connectivitymatrix& connectivity_to_importance();
};


#endif //LAB4_CONNECTIVITYMATRIX_HPP
