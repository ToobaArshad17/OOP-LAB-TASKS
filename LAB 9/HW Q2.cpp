#include <iostream>
using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    virtual void setPrice() = 0;

    void setModel(string model) {
        this->model = model;
    }

    void display() {
        cout << model << endl << price << endl;
    }

    double getPrice() {
        return price;
    }

    virtual ~Car() {}
};

class Color : public Car {
    string color;

public:
    Color(string c) {
        color = c;
    }

    void setPrice() override {
        if (color == "white") {
            price = 10000;
        } else if (color == "black") {
            price = 20000;
        } else {
            price = 18900;
        }
    }
};

class Company : public Car {
    string company;

public:
    Company(string c) {
        company = c;
    }

    void setPrice() override {
        if (company == "contour") {
            price = 20000;
        } else if (company == "pearls top") {
            price = 30000;
        } else {
            price = 98900;
        }
    }
};

int main() {
    Car* car1 = new Color("red");
    Car* car2 = new Company("contour");

    car1->setModel("Yaris");
    car1->setPrice();

    car2->setModel("Vitz");
    car2->setPrice();

    car1->display();
    car2->display();

    delete car1;
    delete car2;

    return 0;
}