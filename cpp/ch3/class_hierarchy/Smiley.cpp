#include "Smiley.h"
#include <iostream>
using namespace std;

void Smiley::move(Point to) {
    Circle::move(to);
    for (auto p : eyes) p->move(to);
    if (mouth) mouth->move(to);
}

void Smiley::draw() const {
    cout << "Drawing Smiley:" << std::endl;
    Circle::draw();
    for (auto p : eyes) p->draw();
    if (mouth) mouth->draw();
    cout << "Finished drawing Smiley." << std::endl;
}

void Smiley::rotate(int angle) {
    cout << "Rotating Smiley:" << std::endl;
    Circle::rotate(angle);
    for (auto p : eyes) p->rotate(angle);
    if (mouth) mouth->rotate(angle);
    cout << "Finished rotating Smiley." << std::endl;
}

void Smiley::add_eye(Shape* s) {
    eyes.push_back(s);
}

void Smiley::set_mouth(Shape* s) {
    if (mouth) delete mouth;
    mouth = s;
}

void Smiley::wink(int i) {
    if (i < 0 || i >= static_cast<int>(eyes.size())) {
        throw std::out_of_range("Eye index out of range");
    }
    // Implementation for winking the specified eye
    // This is a placeholder implementation; actual winking code would depend on the graphics library used.
    std::cout << "Winking eye at index " << i << std::endl;
}