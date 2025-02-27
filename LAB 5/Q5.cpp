#include <iostream>
using namespace std;

class Car{
    public:
        mutable int engineHorsePower;
        mutable int seatingCapacity;
        mutable int numberOfSpeakers;

        Car (int hp , int seats , int speakers) : engineHorsePower(hp) , seatingCapacity(seats) , numberOfSpeakers(speakers) {}

        void changeAttributes(int hp , int seats , int speakers) const {
            engineHorsePower = hp;
            numberOfSpeakers = speakers;
            seatingCapacity = seats;
        }

        void display() const {
            cout << "Engine Horsepower:" << engineHorsePower << endl;
            cout << "Seats Capacity:" << seatingCapacity << endl;
            cout << "Number of Speakers:" << numberOfSpeakers << endl;
        }
};

int main(){
    Car car(234 , 56 , 45);

    cout << "INITIAL VALUES:" << endl;
    car.display();
    car.changeAttributes(34 , 67 , 67);
    cout << "MODIFIED VALUES:" << endl;
    car.display();

    return 0;
}