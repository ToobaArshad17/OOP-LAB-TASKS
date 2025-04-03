#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string n, string addr, string phone, string mail) {
        name = n;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }
};

class Student : public Person {
private:
    string coursesEnrolled;
    float GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string mail, string courses, float gpa, int year)
        : Person(n, i, addr, phone, mail), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
private:
    string department;
    string coursesTaught;
    float salary;

public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, string courses, float sal)
        : Person(n, i, addr, phone, mail), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    float salary;

public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, float sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course {
private:
    string courseID;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(string cid, string cname, int cred, string instr, string sched)
        : courseID(cid), courseName(cname), credits(cred), instructor(instr), schedule(sched) {}

    void registerStudent(Student& student) {
        cout << student.name << " has been registered for the course: " << courseName << endl;
    }

    void calculateGrades(Student& student) {
        cout << "Grades calculated for " << student.name << " in " << courseName << endl;
    }
};

int main() {
    Student student1("Alice", "S12345", "123 Main St", "555-1234", "alice@email.com", "Math, Physics", 3.8, 2021);
    Professor professor1("Dr. John", "P98765", "456 University Ave", "555-5678", "john.prof@univ.com", "Physics", "Quantum Mechanics", 70000);
    Staff staff1("Michael", "ST1122", "789 Admin Blvd", "555-8765", "michael@univ.com", "HR", "Manager", 45000);

    student1.displayInfo();
    professor1.displayInfo();
    staff1.displayInfo();

    Course course1("C101", "Introduction to Physics", 3, "Dr. John", "Mon-Wed-Fri 10:00-12:00");
    course1.registerStudent(student1);
    course1.calculateGrades(student1);

    return 0;
}
