#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;
    double salary;

public:
    virtual void getData() {
        cout << "Enter name: ";
        cin.ignore();
        getline (cin , name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> salary;
    }

    virtual void displayData() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual void bonus() {
        cout << "Bonus: " << salary * 0.10 << endl;
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getData() override {
        Person::getData();
    }

    void displayData() override {
        Person::displayData();
    }

    void bonus() override {
        cout << "Admin Bonus: " << salary * 0.15 << endl;
    }
};

class Account : virtual public Person {
public:
    void getData() override {
        Person::getData();
    }

    void displayData() override {
        Person::displayData();
    }

    void bonus() override {
        cout << "Account Bonus: " << salary * 0.12 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        Person::getData();
    }

    void displayData() override {
        Person::displayData();
    }

    void bonus() override {
        cout << "Master Bonus: " << salary * 0.20 << endl;
    }
};

int main() {
    Person* ptr;

    Admin a;
    Account acc;
    Master m;

    cout << "Admin" << endl;
    ptr = &a;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << endl;

    cout << "Account" << endl;
    ptr = &acc;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << endl;

    cout << "Master" << endl;
    ptr = &m;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    return 0;
}