#include <iostream>
using namespace std;

class B;

class A {
    int value;
public:
    A(int v = 0) : value(v) {}

    int getValue() const { return value; }

    // Class A to class B conversion
    operator B();
};

class B {
    int value;
public:
    B(int v = 0) : value(v) {}

    int getValue() const { return value; }

    // Class B to class A conversion
    operator A() {
        return A(value);
    }

    void display() const {
        cout << "Value in class B: " << value << endl;
    }
};

// Definition of conversion from A to B
A::operator B() {
    return B(value);
}

int main() {
    A a(10);
    B b = a;  // Class A to class B conversion

    b.display();

    A a2 = b;  // Class B to class A conversion
    cout << "Value in class A: " << a2.getValue() << endl;

    return 0;
}
