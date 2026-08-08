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

    double& operator[](int i) { return elem[i]; }
    int size() const { return sz; }
};

Vector read(std::istream&);