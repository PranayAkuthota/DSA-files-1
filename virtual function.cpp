#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() {
        cout << "Area of shape cannot be determined." << endl;
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}
    void area() override {
        cout << "Area of Circle: " << 3.14 * radius * radius << endl;
    }
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

int main() {
    Shape *shapePtr;
    Circle circle(5);
    Rectangle rectangle(4, 6);

    shapePtr = &circle;
    shapePtr->area();

    shapePtr = &rectangle;
    shapePtr->area();

    return 0;
}
