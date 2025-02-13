#include <iostream>
using namespace std;

class Employee {
    public:
        string firstName;
        string lastName;
        double salary;

        void setSalary(double s) {
            if (s < 0) {
                salary = 0.0;
            } else {
                salary = s;
            }
        }
};

int main(int argc , char *argv[]) {
    Employee E[2];

    E[0].firstName = argv[1];
    E[0].lastName = argv[2];
    E[0].salary = stod(argv[3]);

    E[1].firstName = argv[4];
    E[1].lastName = argv[5];
    E[1].salary = stod(argv[6]);

    cout << "Employee 1 salary is: " << E[0].salary << endl;
    cout << "Employee 2 salary is: " << E[1].salary << endl;

    E[0].salary += E[0].salary * 0.1;
    E[1].salary += E[1].salary * 0.1;

    cout << "Employee 1 salary after raise: " << E[0].salary << endl;
    cout << "Employee 2 salary after raise: " << E[1].salary << endl;

    return 0;
}