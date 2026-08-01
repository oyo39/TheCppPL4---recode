#include <iostream>
#include "Circle.h"

void Circle::draw() const {
    // Implementation for drawing the circle on the current "Canvas"
    // This is a placeholder implementation; actual drawing code would depend on the graphics library used.
    std::cout << "Drawing Circle at (" << x.getX() << ", " << x.getY() << ") with radius " << r << std::endl;
}

void Circle::rotate(int angle) {
    // Implementation for rotating the circle
    // Since a circle is symmetric, rotating it does not change its appearance.
    std::cout << "Rotating Circle by " << angle << " degrees." << std::endl;
}