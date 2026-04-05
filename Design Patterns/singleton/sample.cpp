#include <iostream>
using namespace std;

class Logger {
private:
    // TODO:
    // static instance pointer
    static Logger* instance; //static very important
    // private constructor
    // Logger(){   
    //   instance = new Logger();  ----> this is WRONG, it will initiate a recursive loop of creaating objects
    // }
    // Private constructor
    Logger() {}   //“I’m making constructor private to prevent direct instantiation, and using a static instance to ensure only one object exists.”

public:
    // TODO:
    // delete copy constructor & assignment operator
    //“To prevent creation of multiple instances through copying, which would violate the Singleton guarantee.”
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* getInstance() {
        // TODO
        if(instance==nullptr)
          instance = new Logger();
        
        return instance;
    }

     static Logger& getInstance() {
        static Logger instance;  // 🔥 thread-safe (C++11+)
        return instance;
    }

    void log(string message) {
        cout << "Log: " << message << endl;
    }
};
// Static member initialization
Logger* Logger::instance = nullptr;  //not needed if thread safe init is done in getInstance

int main() {
    Logger* logger1 = Logger::getInstance();
    Logger* logger2 = Logger::getInstance();

    logger1->log("First message");
    logger2->log("Second message");

    if (logger1 == logger2) {
        cout << "Same instance" << endl;
    } else {
        cout << "Different instances" << endl;
    }
}
