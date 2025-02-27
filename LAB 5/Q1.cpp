#include <iostream>
using namespace std;

class Engine {
    bool isRunning; 

    public:
        Engine() : isRunning(false) {
            cout << "Engine created!" << endl;
        }

        ~Engine() {
            cout << "Engine destroyed!" << endl;
        }

        void start() {
            if (!isRunning) {
                isRunning = true;
                cout << "Engine started!" << endl;
            } else {
                cout << "Engine is already running!" << endl;
            }
        }

        void stop() {
            if (isRunning) {
                isRunning = false;
                cout << "Engine stopped!" << endl;
            } else {
                cout << "Engine is already stopped!" << endl;
            }
        }
};

class Car {
    Engine engine; 

    public:

        Car() {
            cout << "Car created" << endl;
        }

        ~Car() {
            cout << "Car destroyed" << endl;
        }

        void startCar() {
            cout << "Starting car" << endl;
            engine.start();
        }

        void stopCar() {
            cout << "Stopping car" << endl;
            engine.stop();
        }
};

int main() {
    Car car;

    car.startCar();
    car.stopCar();

    return 0;
}