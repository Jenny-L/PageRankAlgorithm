//
// Created by Jenny Ly on 2018-10-10.
//

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

    friend std::ostream& operator<<(std::ostream& os, connectivitymatrix& obj2);

    connectivitymatrix& convert_no_link_to_ones();

    connectivitymatrix& connectivity_to_importance();

};


#endif //LAB4_CONNECTIVITYMATRIX_HPP
