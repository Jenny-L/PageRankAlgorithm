#include <iostream>
#include <fstream>
#include "matrix.hpp"

using namespace std;

int main() {


    //open file for reading
    vector<double> outVector;
    string line;
    ifstream myfile{"connectivity.txt"};
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            size_t pos = line.find(" ");
            string value = line.erase(0, pos);
            double doubleValue = stod(value);
            outVector.push_back(doubleValue);
        }
    }

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