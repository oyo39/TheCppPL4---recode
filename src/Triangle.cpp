#include <iostream>
#include "Triangle.h"

Point Triangle::center() const {
    double centerX = (a.getX() + b.getX() + c.getX()) / 3.0;
    double centerY = (a.getY() + b.getY() + c.getY()) / 3.0;
    return Point(centerX, centerY);
}

void Triangle::move(Point to) {
    // Calculate the offset to move the triangle
    double offsetX = to.getX() - center().getX();
    double offsetY = to.getY() - center().getY();

    // Move each vertex of the triangle
    a = Point(a.getX() + offsetX, a.getY() + offsetY);
    b = Point(b.getX() + offsetX, b.getY() + offsetY);
    c = Point(c.getX() + offsetX, c.getY() + offsetY);
}

void Triangle::draw() const {
    // Implementation for drawing the triangle on the current "Canvas"
    std::cout << "Drawing Triangle with vertices at (" 
                << a.getX() << ", " << a.getY() << "), ("
                << b.getX() << ", " << b.getY() << "), ("
                << c.getX() << ", " << c.getY() << ")" << std::endl;
}

void Triangle::rotate(int angle) {
    // Implementation for rotating the triangle around its center
    // This is a placeholder implementation; actual rotation code would depend on the graphics library used.
    std::cout << "Rotating Triangle by " << angle << " degrees around its center." << std::endl;
}