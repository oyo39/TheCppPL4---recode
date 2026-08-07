#include "complex.h"
#include <iostream>
using namespace std;

void f(complex z)
{
    complex a{2.3};
    complex b{1/a};
    complex c{a+z*complex{1,2.3}};

    if(c!=b)
        c=-(b/a)+2*b;

    cout << "c : " << c.to_string() << endl;
}

int main()
{
    complex z1{3, 4};
    complex z2{1, -2};

    cout << "z1 + z2: " << (z1 + z2).to_string() << endl;
    cout << "z1 - z2: " << (z1 - z2).to_string() << endl;
    cout << "z1 * z2: " << (z1 * z2).to_string() << endl;
    cout << "z1 / z2: " << (z1 / z2).to_string() << endl;

    f(z1);

    return 0;
}