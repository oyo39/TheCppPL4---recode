#include <stdexcept>
#include <string>

class Vector {
private:
    double* elem;
    std::size_t sz;
public:
    Vector() : elem{nullptr}, sz{0} {}
    Vector(std::size_t s) : elem{new double[s]}, sz{s} {}
    ~Vector() { delete[] elem; }

    Vector(const Vector&) = delete;
    Vector& operator=(const Vector&) = delete;

    // move constructor & move assignment operator
    Vector(Vector&&) noexcept;
    Vector& operator=(Vector&&) noexcept;

    double& operator[](std::size_t index) {
        return elem[index];
    }

    const double& operator[](std::size_t index) const {
        return elem[index];
    }

    std::size_t size() const {
        return sz;
    }

    std::string toString() const;
};

class Vector_size_mismatch : public std::length_error {
public:
    Vector_size_mismatch() : std::length_error{"Vector size mismatch"} {}
};

Vector operator+(const Vector&, const Vector&);