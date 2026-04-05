#include <iostream>
using namespace std;

class PaymentProcessor {
public:
    virtual void pay(int amount) = 0;
};

// Existing system (cannot modify)
class OldPaymentSystem {
public:
    void makePayment(int amount) {
        cout << "Paid " << amount << " using old system\n";
    }
};

// TODO: Create Adapter
class PaymentAdapter : public PaymentProcessor {
    // TODO
};

// Example
int main() {
    PaymentProcessor* p = new PaymentAdapter();
    p->pay(100);
}

//Paid 100 using old system
