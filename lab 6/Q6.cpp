#include <iostream>
using namespace std;

class Student{
    int id;
    string name;

    public:
       Student(int id , string n) : id(id) , name(n) {}

       void getStudentInfo(){
        cout << "Student Name:" << name << " | ID:" << id << endl;
       }
};

class Marks : public Student{
    protected:
       int marks_oop , marks_pf , marks_ds , marks_db;

    public:
       Marks (int mo , int mp , int ms , int md , string name , int id) : marks_oop(mo) , marks_pf(mp) , marks_ds(ms) , marks_db(md) , Student(id,name) {}

       void getMarks() {
        cout << "OOP Marks" << marks_oop << endl;
        cout << "PF Marks:" << marks_pf << endl;
        cout << "DS Marks:" << marks_ds << endl;
        cout << "DB Marks:" << marks_db << endl;
       }
};

class Result : public Marks{
    protected:
       int totalMarks;
       double averageMarks;

    public:
       Result (int mo , int mp , int ms , int md , string name , int id) : Marks(mo,mp,ms,md,name,id) {}

       void calculate(){
           totalMarks = marks_oop + marks_pf + marks_ds + marks_db;
           averageMarks = totalMarks / 4;
       }

       void display() {
           Student :: getStudentInfo();
           Marks :: getMarks();
           cout << "Total Marks:" << totalMarks << endl << "Average Marks:" << averageMarks << endl;
       }
};

int main() {
    Result result (80 , 78 , 67 , 81 , "Aliyan Sultan" , 78);
    result.calculate();
    result.display();
    
    return 0;
}