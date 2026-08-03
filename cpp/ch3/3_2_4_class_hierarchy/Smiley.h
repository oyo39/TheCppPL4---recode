#include <vector>
#include "Point.h"
#include "Circle.h"
#include <iostream>

using namespace std;

class Smiley : public Circle {
public:
    Smiley(Point p, int r) : Circle(p, r), mouth(nullptr) {
    }

    ~Smiley() {
        cout << "Smiley destructor called" << endl;
        delete mouth;
        for (auto p : eyes) delete p;
    }

    void move(Point);

    void draw() const;
    void rotate(int);

    void add_eye(Shape*);
    void set_mouth(Shape*);
    virtual void wink(int i);   // wink eye number i

private:
    vector<Shape*> eyes;
    Shape* mouth;
};