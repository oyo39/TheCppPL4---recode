#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Smiley.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

enum class Kind { circle, triangle, smiley, none };

Kind get_kind(istream& is) {
    char ch;
    
    if (!(is >> ch)) {
        return Kind::none; // No more input
    }

    switch (ch) {
        case 'c': return Kind::circle;
        case 't': return Kind::triangle;
        case 's': return Kind::smiley;
        default: throw runtime_error("Unknown shape kind");
    }
}

unique_ptr<Shape> read_shape(istream& is) {
    Kind k = get_kind(is);
    switch (k) {
        case Kind::circle: {
            double x, y;
            int r;
            is >> x >> y >> r;
            Point p{x, y};
            return unique_ptr<Shape>{new Circle{p, r}};
        }
        case Kind::triangle: {
            double x1, y1, x2, y2, x3, y3;
            is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            Point p1{x1, y1}, p2{x2, y2}, p3{x3, y3};
            return unique_ptr<Shape>{new Triangle{p1, p2, p3}};
        }
        case Kind::smiley: {
            double x, y;
            int r;
            is >> x >> y >> r;
            Point p{x, y};
            Smiley* ps = new Smiley(p, r);
            is >> x >> y >> r; // Read eye position and radius
            Point eye1{x, y};
            ps->add_eye(new Circle(eye1, r));
            is >> x >> y >> r; // Read second eye position and radius
            Point eye2{x, y};
            ps->add_eye(new Circle(eye2, r));
            is >> x >> y >> r; // Read mouth position and radius
            Point mouth{x, y};
            ps->set_mouth(new Circle(mouth, r));
            return unique_ptr<Shape>{ps};
        }
        default:
            return nullptr;
    }
}

void draw_all(const vector<unique_ptr<Shape>>& v) {
    for (const auto& shape : v) {
        shape->draw();
    }
}

void rotate_all(vector<unique_ptr<Shape>>& v, int angle) {
    for (auto& shape : v) {
        shape->rotate(angle);
    }
}

void user()
{
    vector<unique_ptr<Shape>> v;
    while (cin)
    {
        try {
            auto p = read_shape(cin);
            if (p) {
                v.push_back(move(p));
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            break;
        }
    }
    draw_all(v);
    rotate_all(v, 45);
    v.clear();
}

int main() {
    user();
    return 0;
}

// Running command: ./app < src/input.txt