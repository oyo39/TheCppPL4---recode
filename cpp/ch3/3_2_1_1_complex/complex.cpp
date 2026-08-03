#include "complex.h"
#include <string>

complex::complex(double r, double i) : re{r}, im{i} {}
complex::complex(double r) : re{r}, im{0} {}
complex::complex() : re{0}, im{0} {}

double complex::real() const { return re; }
void complex::real(double r) { re = r; }
double complex::imag() const { return im; }
void complex::imag(double i) { im = i; }

complex complex::operator+=(complex z)
{
    re += z.re;
    im += z.im;
    return *this;
}

complex complex::operator-=(complex z)
{
    re -= z.re;
    im -= z.im;
    return *this;
}

complex complex::operator*=(complex z)
{
    double r = re * z.re - im * z.im;
    double i = re * z.im + im * z.re;
    re = r;
    im = i;
    return *this;
}

complex complex::operator/=(complex z)
{
    double denom = z.re * z.re + z.im * z.im;
    double r = (re * z.re + im * z.im) / denom;
    double i = (im * z.re - re * z.im) / denom;
    re = r;
    im = i;
    return *this;
}

std::string complex::to_string() const
{
    return std::to_string(re) + (im >= 0 ? " + " : " - ") + std::to_string(std::abs(im)) + "i";
}

complex operator+(complex a, complex b)
{
    return a += b;
}

complex operator-(complex a, complex b)
{
    return a -= b;
}

complex operator*(complex a, complex b)
{
    return a *= b;
}

complex operator/(complex a, complex b)
{
    return a /= b;
}