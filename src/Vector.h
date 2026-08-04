#include <stdexcept>
#include <string>
#include <list>
#include <iostream>
using namespace std;

template<typename T>
class Vector {
private:
    T* elem; // elem points to an array of sz elements of type T
    int sz;  // number of elements
public:
    Vector(int s); // constructor
    ~Vector() { delete[] elem; } // destructor
    
    // move constructor & move assignment operator
    // Vector(Vector&&) noexcept;
    // Vector& operator=(Vector&&) noexcept;

    T& operator[](int i); // access: return reference
    const T& operator[](int i) const; // access: return const reference
    int size() const { return sz; } // return number of elements
};

class Negative_size : public std::length_error {
public:
    Negative_size() : std::length_error{"Vector constructor: negative size"} {}
};

template<typename T>
Vector<T>::Vector(int s)
{
    if (s < 0) throw Negative_size{};
    elem = new T[s];
    sz = s;
}

template<typename T>
T& Vector<T>::operator[](int i)
{
    if(i < 0 || i >= sz) 
        throw out_of_range{"Vector::operator[]: index out of range"};
    return elem[i];
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
    if(i < 0 || i >= sz) 
        throw out_of_range{"Vector::operator[]: index out of range"};
    return elem[i];
}

// template<typename T>
// Vector<T>::Vector(Vector&& a) noexcept : elem{a.elem}, sz{a.sz} {
//     a.elem = nullptr;
//     a.sz = 0;
// }

// template<typename T>
// Vector<T>& Vector<T>::operator=(Vector&& a) noexcept {
//     if (this != &a) {
//         delete[] elem;
//         elem = a.elem;
//         sz = a.sz;
//         a.elem = nullptr;
//         a.sz = 0;
//     }
//     return *this;
// }
