#include <iostream>
using namespace std;

class State {
public:
    virtual void handle() = 0;
};

// TODO: RedState, GreenState, YellowState

class TrafficLight {
    State* state;

public:
    void setState(State* s) {
        state = s;
    }

    void request() {
        // TODO
    }
};

int main() {
    TrafficLight t;

    // switch states and call request()
}

/*
Expected Output (example)
Red Light
Green Light
Yellow Light*/
