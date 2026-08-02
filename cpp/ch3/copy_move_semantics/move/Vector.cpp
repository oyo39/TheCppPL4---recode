#include "Vector.h"
#include <string>

Vector::Vector(Vector&& a) noexcept : elem{a.elem}, sz{a.sz} {
    a.elem = nullptr;
    a.sz = 0;
}

Vector& Vector::operator=(Vector&& a) noexcept {
    if (this != &a) {
        delete[] elem;
        elem = a.elem;
        sz = a.sz;
        a.elem = nullptr;
        a.sz = 0;
    }
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