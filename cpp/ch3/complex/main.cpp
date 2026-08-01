#include "complex.h"
#include <iostream>



int main()
{
    complex z1{3, 4};
    complex z2{1, -2};

    std::cout << "z1 + z2: " << (z1 + z2).to_string() << std::endl;
    std::cout << "z1 - z2: " << (z1 - z2).to_string() << std::endl;
    std::cout << "z1 * z2: " << (z1 * z2).to_string() << std::endl;
    std::cout << "z1 / z2: " << (z1 / z2).to_string() << std::endl;

    return 0;
}