#include<iostream>
using namespace std;

class Person {
	int ID;
	public:
		void getData(){
			cout << "Enter ID: " ;
			cin >> ID;
		}
		void displayData() {
			cout << "Employee ID: " << ID << endl;
		}
};

class Admin : public Person {
	string name;
	double income; // monthly income
	
	public:
		Admin(){
			name = "";
			income = 0.0;
		}
		void getData(){
			Person::getData();
			cout << "Enter Name: " ;
			cin >> name;
			cout << "Enter Monthly Income: " ;
			cin >> income;
		}
		double calcBonus () {
			return (0.5 * income * 12);
		}
		void displayData() {
			Person::displayData();
			cout << "Employee Name: " << name << endl;
			cout << "Monthly Income: " << income << endl;
			double bonus = calcBonus();
			cout << "Monthly Income (with bonus): " << bonus << endl;
		}
};

class Accounts : public Person {
	string name;
	double income; // monthly income
	
	public:
		Accounts(){
			name = "";
			income = 0.0;
		}
		void getData(){
			Person::getData();
			cout << "Enter Name: " ;
			cin >> name;
			cout << "Enter Monthly Income: " ;
			cin >> income;
		}
		double calcBonus () {
			return (0.5 * income * 12);
		}
		void displayData() {
			Person::displayData();
			cout << "Employee Name: " << name << endl;
			cout << "Monthly Income: " << income << endl;
			double bonus = calcBonus();
			cout << "Monthly Income (with bonus): " << bonus << endl;
		}
};

int main() {
    Admin adminEmp;
    Accounts accEmp;

    cout << endl << "Enter Admin Employee details:" << endl;
    adminEmp.getData();

    cout << endl << "Enter Accounts Employee details:" << endl;
    accEmp.getData();

    cout << "\n\nAdmin Employee:" << endl;
    adminEmp.displayData();
    
    cout << endl << "Accounts Employee:" << endl;
    accEmp.displayData();

    return 0;	
}