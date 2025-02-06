#include <iostream>
#include <cstring>
using namespace std;

struct Employee {
    int employee_id;
    char name[50];
    double salary;
};

struct Organisation {
    char organisation_name[50] , organisation_number[50];
    Employee emp;
};

int main() {
    Organisation org = {
        "NU-Fast", 
        "NUFAST789UHJ", 
        {123, "Linus Sebastian", 56000}
    };

    cout << "The size of structure organisation : " << sizeof(org) << endl;
    cout << "Organisation Name : " << org.organisation_name << endl;
    cout << "Organisation Number : " << org.organisation_number << endl;
    cout << "Employee id : " << org.emp.employee_id << endl;
    cout << "Employee name : " << org.emp.name << endl;
    cout << "Employee Salary : " << org.emp.salary << endl;

    return 0;
}