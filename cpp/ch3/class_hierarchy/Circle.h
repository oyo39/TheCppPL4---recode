#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(Point p, int rr) : x(p), r(rr) {}

    Point center() const { return x;}
    void move(Point to) { x = to; }

    void draw() const;
    void rotate(int);
private:
    Point x;
    int r;
};

#endif // CIRCLE_H