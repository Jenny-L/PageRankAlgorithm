/**
 * main.cpp
 * Opens file
 * Performs search algorithm
 *
 * @author Jenny Ly
 * @version 2018-10-05
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <regex>
#include <iomanip>
#include "matrix.hpp"
#include "connectivitymatrix.hpp"

const double PROBABILITY_CLICKS = 0.85;
const double PROBABILITY_TELEPORT = 0.15;
const int ONE = 1;
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

    connectivitymatrix* connectivity= new connectivitymatrix(outVector);
    connectivitymatrix* teleportation = new connectivitymatrix(connectivity->get_row_size());
    ++*connectivity;
    ++*teleportation;

    matrix importance = connectivity->connectivity_to_importance();
    matrix teleportation_probability = teleportation->connectivity_to_importance();

    matrix transitional = PROBABILITY_CLICKS * importance + PROBABILITY_TELEPORT * teleportation_probability;

    matrix* rank = new matrix(ONE, transitional.get_row_size());
    ++*rank;

    matrix last_result = *rank;
   *rank * transitional;

    while(true) {
        if (last_result == *rank) {
            break;
        }
        matrix m = *rank;
        last_result = m;
        *rank * transitional;
    }

    rank->convert_markov_to_percent();
    connectivitymatrix* m = (connectivitymatrix*) rank;

    cout << *m;

    return 0;
}