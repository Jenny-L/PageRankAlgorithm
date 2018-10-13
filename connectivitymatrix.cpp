//
// Created by Jenny Ly on 2018-10-10.
//

#include <iomanip>
#include "connectivitymatrix.hpp"
connectivitymatrix::connectivitymatrix(): matrix(){};

connectivitymatrix::connectivitymatrix(int input): matrix(input){};

connectivitymatrix::connectivitymatrix(int r, int c): matrix(r,c){};

connectivitymatrix::connectivitymatrix(vector<double> arrayValues): matrix(arrayValues){};

connectivitymatrix::connectivitymatrix(const matrix& m): matrix(m){};

connectivitymatrix::~connectivitymatrix() {delete[] matrixArray;};

std::ostream& operator<<(std::ostream& os, connectivitymatrix& obj) {
    double objValue;
    int rowSize = obj.get_row_size();
    int columnSize = obj.get_column_size();
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < columnSize; j++) {


            objValue = obj.get_value(i, j);
            os << fixed << setprecision(4) << objValue << " ";
            if ((j + 1) % rowSize == 0) {
                os << endl;
            }
        }
    }
    return os;
}

connectivitymatrix& connectivitymatrix::convert_no_link_to_ones() {
    for(int i = 0; i < sum_container.size(); i++) {
        if (sum_container[i] == 0) {
            for(int y = 0; y < get_column_size(); y++) {
                set_value(y, i, 1);
            }
            sum_container[i] = get_column_size();
        }
    }
    return *this;
}

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
//bool connectivitymatrix::isConnectivity() {
//    for(int y = 0; y < this->get_column_size(); y++) {
//        int total = 0;
//        for(int x = 0; x < this->get_row_size(); x++) {
//            total += get_value(x, y);
//        }
//        if(total != 1) {
//            throw invalid_argument("This matrix is not a connective matrix.");
//        }
//    }
//
//}