#include <iostream>
using namespace std;

// Strategy Interface
class PaymentStrategy {
public:
    virtual string pay() = 0;
};

// Concrete Strategies
class CreditCardPayment : public PaymentStrategy {
public:
    // TODO
    string pay() override{
      return "Paid using Credit Card\n";
    }
};

class UPIPayment : public PaymentStrategy {
public:
    // TODO
    string pay() override{
      return "Paid using UPI\n";
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    // TODO
    string pay() override{
      return "Paid using PayPal\n";
    }
};

// Context
class PaymentContext {
    PaymentStrategy* strategy;

public:
    PaymentContext(PaymentStrategy* s) : strategy(s) {}

    string executePayment() {
        // TODO
        return strategy->pay();
    }
};

// Example usage
int main() {
    PaymentStrategy* s1 = new CreditCardPayment();
    PaymentContext context1(s1);
    cout << context1.executePayment() << endl;

    PaymentStrategy* s2 = new UPIPayment();
    PaymentContext context2(s2);
    cout << context2.executePayment() << endl;

    PaymentStrategy* s3 = new PayPalPayment();
    PaymentContext context3(s3);
    cout << context3.executePayment() << endl;
}
