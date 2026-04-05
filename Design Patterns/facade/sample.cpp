#include <iostream>
using namespace std;

class DVDPlayer {
public:
    void on() { cout << "DVD ON\n"; }
};

class Projector {
public:
    void on() { cout << "Projector ON\n"; }
};

class SoundSystem {
public:
    void on() { cout << "Sound ON\n"; }
};

// TODO: Facade

int main() {
    HomeTheaterFacade h;
    h.watchMovie();
}
/*
Expected Output
DVD ON
Projector ON
Sound ON
*/
