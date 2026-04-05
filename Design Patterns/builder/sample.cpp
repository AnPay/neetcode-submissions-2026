#include <iostream>
using namespace std;

class Computer {
public:
    string cpu;
    string ram;
    string storage;

    void show() {
        cout << cpu << ", " << ram << ", " << storage << endl;
    }
};

class ComputerBuilder {
public:
    virtual void setCPU() = 0;
    virtual void setRAM() = 0;
    virtual void setStorage() = 0;
    virtual Computer* build() = 0;
};

// TODO: GamingComputerBuilder
// TODO: OfficeComputerBuilder

int main() {
    // Build a Gaming PC and print config
}

/*
Expected Output (example)
i9, 32GB, 1TB SSD
*/
