#include <iostream>
#include <vector>
using namespace std;

class Car {
    string name;
    int id;

    public:
        Car(string carName, int carId) : name(carName), id(carId) {
            cout << "Car created: " << name << " (ID: " << id << ")" << endl;
        }

        ~Car() {
            cout << "Car destroyed: " << name << " (ID: " << id << ")" << endl;
        }

        string getName() const {
            return name;
        }

        int getId() const {
            return id;
        }
};

class Garage {
    vector<Car*> cars; 

    public:
        void parkCar(Car* car) {
            cars.push_back(car);
            cout << "Car parked: " << car->getName() << " (ID: " << car->getId() << ")" << endl;
        }

        void listCars() const {
            if (cars.empty()) {
                cout << "No cars parked in the garage." << endl;
            } else {
                cout << "Cars parked in the garage:" << endl;
                for (const Car* car : cars) {
                    cout << "- " << car->getName() << " (ID: " << car->getId() << ")" << endl;
                }
            }
        }
};

int main() {
    Car car1("Toyota", 1);
    Car car2("Honda", 2);
    Car car3("Grande", 3);

    Garage garage;

    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    garage.listCars();

    cout << "End of main(). Cars will be destroyed." << endl;

    return 0;
}