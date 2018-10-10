#include <iostream>
#include "matrix.hpp"

int main() {

    matrix defaultConstructor;
    matrix oneParam1(2);
    matrix twoParam1(2 ,2);
    matrix twoParam(3, 2);


    operator<<(cout, defaultConstructor);


    operator<<(cout, twoParam);

    defaultConstructor.set_value(0,0, 2.3);
    operator<<(cout, defaultConstructor);

    oneParam1.set_value(0, 0, 1.1);
    oneParam1.set_value(0, 1, 2.2);
    oneParam1.set_value(1, 0, 3.3);
    oneParam1.set_value(1, 1, 4.4);
    operator<<(cout, oneParam1);

    twoParam1.set_value(0, 0, 5.1);
    twoParam1.set_value(0, 1, 6.1);
    twoParam1.set_value(1, 0, 7.1);
    twoParam1.set_value(1, 1, 8.1);
    operator<<(cout, twoParam1);
    cout << endl;
    oneParam1.operator+=(twoParam1);
    operator<<(cout, oneParam1);

    oneParam1.operator+=(twoParam);
    return 0;
}