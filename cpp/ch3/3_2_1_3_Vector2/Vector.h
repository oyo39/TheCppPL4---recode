#include <string>

class Vector {
private:
    double* elem;
    int sz;
public:
    Vector(std::initializer_list<double>);
    ~Vector();
    void push_back(double);
    std::string to_string() const;
};

Vector read(std::istream&);