template<typename T>
class Vector {
private:
    T* elem; // elem points to an array of sz elements of type T
    int sz;  // number of elements
public:
    Vector(int s) : elem{new T[s]}, sz{s} {} // constructor
    ~Vector() { delete[] elem; } // destructor
    