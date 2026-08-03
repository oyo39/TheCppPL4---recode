#include "Vector.h"
#include <iostream>
using namespace std;

Vector read_vector(istream& is) {
    std::size_t size;
    is >> size;
    Vector v(size);
    for (std::size_t i = 0; i < size; ++i) {
        is >> v[i];
    }
    return v;
}

void f(const Vector& x, const Vector& y, const Vector& z) {
    Vector r;
    r = x + y + z;
    cout << "r = " << r.toString() << endl;
}

int main() {
    try {
        Vector v1 = read_vector(cin);
        Vector v2 = read_vector(cin);
        Vector v3 = read_vector(cin);
        f(v1, v2, v3);
        
        /**
         * Only for testing move semantics 
         */
        // cout << "v1 = " << v1.toString() << endl;
        // Vector v4;
        // cout << "v4 = " << v4.toString() << endl;
        // cout << "Moving v1 to v4..." << endl;
        // v4 = std::move(v1);
        // cout << "v1 = " << v1.toString() << endl;
        // cout << "v4 = " << v4.toString() << endl;
    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}