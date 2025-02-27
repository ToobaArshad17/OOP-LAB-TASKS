#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        const int roll_no; 
        string name;

    public:
        Student(int roll, const string& studentName)
            : roll_no(roll), name(studentName) {}

        void display() const {
            cout << "Roll No: " << roll_no << endl;
            cout << "Name: " << name << endl;
        }
};

int main() {
    int roll;
    string name;

    cout << "Enter Roll No: ";
    cin >> roll;
    cin.ignore(); 
    cout << "Enter Name: ";
    getline(cin, name);

    Student student(roll, name);

    cout << "\nStudent Details:" << endl;
    student.display();

    return 0;
}