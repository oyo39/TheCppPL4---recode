#include <string>

class complex {
    double re, im;
public:
    complex(double, double);
    complex(double);
    complex();

    double real() const;
    void real(double);
    double imag() const;
    void imag(double);

    complex operator+=(complex);

    complex operator-=(complex);

    complex operator*=(complex);

    complex operator/=(complex);

    std::string to_string() const;
};

complex operator+(complex, complex);
complex operator-(complex, complex);
complex operator*(complex, complex);
complex operator/(complex, complex);
bool operator==(complex, complex);
bool operator!=(complex, complex);
complex operator-(complex);
