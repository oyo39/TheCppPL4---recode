#include "Vector.h"
#include <string>

Vector::Vector(const Vector& a) : elem{new double[a.sz]}, sz{a.sz} {
        std::copy(a.elem, a.elem + a.sz, elem);
}

Vector& Vector::operator=(const Vector& a)
{
    if (this == &a) return *this; // self-assignment check
    double* p = new double[a.sz]; // allocate new memory
    std::copy(a.elem, a.elem + a.sz, p); // copy elements
    delete[] elem; // free old memory
    elem = p; // assign new memory
    sz = a.sz; // update size
    return *this;
}

std::string Vector::toString() const {
    std::string result = "[";
    for (std::size_t i = 0; i < sz; ++i) {
        result += std::to_string(elem[i]);
        if (i < sz - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

Vector operator+(const Vector& a, const Vector& b) {
    if (a.size() != b.size()) {
        throw Vector_size_mismatch{};
    }
    Vector res(a.size());
    for (std::size_t i = 0; i < a.size(); ++i) {
        res[i] = a[i] + b[i];
    }
    return res;
}