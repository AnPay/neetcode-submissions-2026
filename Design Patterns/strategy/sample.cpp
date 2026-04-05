#include <iostream>
#include <memory>
using namespace std;

// Strategy Interface
class PaymentStrategy {
public:
    virtual string pay() = 0;
virtual ~PaymentStrategy() {}  //Prevents undefined behavior when deleting via base pointer
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
//The context delegates the payment behavior to the strategy. This allows runtime switching and avoids if-else chains, making the system extensible
class PaymentContext {
    PaymentStrategy* strategy;

public:
    PaymentContext(PaymentStrategy* s) : strategy(s) {}

    string executePayment() {
        // TODO
        return strategy->pay();
    }

    void setStrategy(PaymentStrategy* s){
        strategy=s;
    }
};

// Example usage
int main() {
    PaymentStrategy* s1 = new CreditCardPayment();
    //unique_ptr<PaymentStrategy> s1 = make_unique<CreditCardPayment>(); //In production I’d prefer smart pointers to avoid memory leaks
    PaymentContext context1(s1);
    cout << context1.executePayment() << endl;

    PaymentStrategy* s2 = new UPIPayment();
    PaymentContext context2(s2);
    cout << context2.executePayment() << endl;

    PaymentStrategy* s3 = new PayPalPayment();
    PaymentContext context3(s3);
    cout << context3.executePayment() << endl;

    context1.setStrategy(s2);
    cout << context1.executePayment() << endl;
    delete s1;
    delete s2;
    delete s3;
}
