#include "Vector.h"
#include <string>
#include <iostream>

Vector::Vector(std::initializer_list<double> lst)
    : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
{
    std::copy(lst.begin(), lst.end(), elem);
}

Vector::~Vector()
{
    delete[] elem;
}

void Vector::push_back(double value)
{
    double* new_elem = new double[sz + 1];
    std::copy(elem, elem + sz, new_elem);
    new_elem[sz] = value;
    delete[] elem;
    elem = new_elem;
    ++sz;
}

std::string Vector::to_string() const
{
    std::string result = "{";
    for (int i = 0; i < sz; ++i) {
        result += std::to_string(elem[i]);
        if (i < sz - 1) {
            result += ", ";
        }
    }
    result += "}";
    return result;
}

Vector read(std::istream& is)
{
    Vector v{};
    for(double d; is >> d;)
        v.push_back(d);
    return v;
}