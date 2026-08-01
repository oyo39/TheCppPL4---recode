#include "Point.h"
#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(Point p1, Point p2, Point p3) : a(p1), b(p2), c(p3) {}
    Point center() const override;
    void move(Point to) override;
    void draw() const override;
    void rotate(int angle) override;
private:
    Point a, b, c;
};