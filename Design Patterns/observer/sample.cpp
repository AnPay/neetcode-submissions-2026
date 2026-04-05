#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Observer Interface
class Observer {
public:
    virtual void update(int price) = 0;
};

// Concrete Observer
class User : public Observer {
    string name;

public:
    User(string n) : name(n) {}

    void update(int price) override {
        // TODO
        cout<<name<<" notified: "<<price<<"\n";
      
    }
};

// Subject
class Stock {
    vector<Observer*> observers;
    int price;

public:
    void subscribe(Observer* o) {
        // TODO
        observers.push_back(o);
    }

    void unsubscribe(Observer* o) {
        // TODO
      auto it = find(observers.begin(),observers.end(),o);
      if (it != observers.end()) {
        observers.erase(it);
      }
    }

    void setPrice(int newPrice) {
        // TODO
      price=newPrice;
      notify();
    }

    void notify() {
        // TODO
      for(auto o : observers)
        o->update(price);
    }
};

// Example usage
int main() {
    Stock s;

    User u1("Alice");
    User u2("Bob");

    s.subscribe(&u1);
    s.subscribe(&u2);

    s.setPrice(100);
    s.setPrice(200);
}
