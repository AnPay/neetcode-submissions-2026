#include <iostream>
using namespace std;

class Coffee {
public:
    virtual int cost() = 0;
};

// Base coffee
class SimpleCoffee : public Coffee {
public:
    int cost() override {
        return 50;
    }
};

// TODO: Decorator base class
// TODO: MilkDecorator
// TODO: SugarDecorator

int main() {
    Coffee* c = new SimpleCoffee();
    // Add milk and sugar
    cout << c->cost() << endl;
}
