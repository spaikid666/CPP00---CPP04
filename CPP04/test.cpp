#include <iostream>

class Base {
public:
    virtual ~Base() {}
    virtual void hi() const { std::cout << "Base\n"; }
};

class Derived : public Base {
public:
    void hi() const { std::cout << "Derived\n"; }
};

int main() {
    Base* b = new Derived();
    b->hi();
    delete b;
}
