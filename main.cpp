#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <regex>
#include "matrix.hpp"
#include "connectivitymatrix.hpp"


using namespace std;

int main() {

    regex("[0-1]");
    smatch value_match;
    //open file for reading
    vector<double> outVector;
    string line;
    ifstream myfile{"connectivity.txt"};
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            for(char&c: line) {
                if (c == '0' || c == '1') {
                    double doubleValue = c - '0';
                    outVector.push_back(doubleValue);
                }
            }
        }
    }
//
//    for (int i: outVector) {
//        cout << outVector[i] << endl;
//    }
    connectivitymatrix* connectivity= new connectivitymatrix(outVector);
    connectivitymatrix* teleportation = new connectivitymatrix(connectivity->get_row_size());

    connectivity->convert_no_link_to_ones();
    teleportation->convert_no_link_to_ones();

    cout << *connectivity << endl;
    cout << *teleportation << endl;

    matrix importance = connectivity->connectivity_to_importance();
    matrix teleportationProbability = teleportation->connectivity_to_importance();
    cout << *connectivity << endl;
    cout << teleportationProbability << endl;
    cout << importance << endl;

    matrix transitional = 0.85 * importance + (1 - 0.85) * teleportationProbability;


    cout << transitional << endl;

    matrix* rank = new matrix(1, transitional.get_row_size());
    rank->set_all_values_to(1);

    //cout << *rank;

    matrix last_result = *rank;
    matrix rank2 = *rank;

    operator*(*rank, transitional);
    cout << *rank << endl;
    while(true) {
        if (last_result == *rank) {
            break;
        }
        matrix m = *rank;
        last_result = m;

        operator*(*rank, transitional);
        //matrix m = *rank * transitional;

        //*rank = m;
        //cout << *rank << endl;
        //cout << transitional << endl;
    }

    double denominator = rank -> row_sum_vector()[0];
  cout << denominator;
    for (int i = 0; i < rank->get_row_size(); i++) {
        for (int j = 0; j < rank->get_column_size(); j++) {
            rank->get_value(i,j) / denominator;
        }
    }
    cout << *rank;

    //matrix* teleportation= new matrix(outVector);

    //matrixtransition
    //matrix* mconnectivity = (matrix*) connectivity;
    //cout << *connectivity;

//    vector<double> list = {5.2, 6.2, 7.2, 8.2};
//    matrix defaultConstructor;
//    matrix oneParam1(2);
//    matrix arrayParam(list);
//    matrix twoParam1(2 ,2);
//    matrix twoParam(3, 2);
//
//
//    operator<<(cout, arrayParam);
//
//
//    operator<<(cout, twoParam);
//
//    defaultConstructor.set_value(0,0, 2.3);
//    operator<<(cout, defaultConstructor);
//
//    oneParam1.set_value(0, 0, 1.1);
//    oneParam1.set_value(0, 1, 2.2);
//    oneParam1.set_value(1, 0, 3.3);
//    oneParam1.set_value(1, 1, 4.4);
//    operator<<(cout, oneParam1);
//
//    twoParam1.set_value(0, 0, 5.1);
//    twoParam1.set_value(0, 1, 6.1);
//    twoParam1.set_value(1, 0, 7.1);
//    twoParam1.set_value(1, 1, 8.1);
//    operator<<(cout, twoParam1);
//    cout << endl;
//    //oneParam1.operator+=(twoParam1);
//    operator<<(cout, oneParam1);

    //oneParam1.operator+=(twoParam);
    return 0;
}