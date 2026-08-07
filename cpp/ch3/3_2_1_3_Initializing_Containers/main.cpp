#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    Vector v1 = {1, 2, 3, 4, 5};
    Vector v2 = {1.23, 3.45, 6.7, 8};

    cout << "v1: " << v1.to_string() << endl;
    cout << "v2: " << v2.to_string() << endl;

    cout << "Enter numbers for v3 (non-numeric input to stop): ";
    Vector v3 = read(cin);
    cout << "v3: " << v3.to_string() << endl;

    return 0;
}