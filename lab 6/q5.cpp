#include <iostream>
#include <iomanip>  
using namespace std;

class Vehicle{
    protected:
       double price;

    public:
       Vehicle (double p) : price(p) {}

       void display () {
           cout << "Price:" << fixed << setprecision(0) << price << endl;
       }
};

class Car : public Vehicle{
    protected:
       int seatingCapacity;
       int numOfDoors;
    string fuelType;

    public:
       Car (int sc , int nod , string ft , double p) : seatingCapacity(sc) , numOfDoors(nod) , fuelType(ft) , Vehicle(p) {}
};

class Motorcycle : public Vehicle{
    protected:
       int numOfCylinders;
       int numOfGears;
       int numOfWheels;

    public:
        Motorcycle (int noc , int nog , int now , double p) :numOfCylinders(noc) , numOfGears(nog) , numOfWheels(now) , Vehicle(p) {}
};

class Audi : public Car{
    string modelType;

    public:
       Audi (string mt ,int sc , int nod , string ft , double p ) : modelType(mt) , Car(sc,nod,ft,p) {}

       void display(){
        cout << "Model Type:" << modelType << endl;
        cout << "Seating Capacity:" << seatingCapacity << endl;
        cout << "Number of doors:" << numOfDoors << endl;
        cout << "Type of fuel:" << fuelType << endl;
        Vehicle :: display();   
       }
};

class Yamaha : public Motorcycle{
   string makeType;

   public:
       Yamaha (string mt , int noc , int nog , int now , double p) : makeType(mt) , Motorcycle(noc , nog , now , p) {}

       void display(){
        cout << "Make Type:" << makeType << endl;
        cout << "Number of cylinders:" << numOfCylinders << endl;
        cout << "Number of gears:" << numOfGears << endl;
        cout << "Number of wheels:" << numOfWheels << endl;
        Vehicle :: display();
       }
};

int main() {
    Audi audi("Audi A4" , 5 , 4 , "Petrol" , 1090009090);
    audi.display();

    cout << endl;

    Yamaha yamaha ("Yamaha Y8" , 1 , 2 , 2 , 7890080);
    yamaha.display();

    return 0;
}