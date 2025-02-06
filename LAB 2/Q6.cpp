#include <iostream>
#include <vector>
#include <string>

struct Subject {
    std::string name;
};

struct Student {
    int studentID;
    Subject subjects[5]; 
};

int main() {
    std::vector<Student> studentList; 

    int totalStudents;
    std::cout << "Enter the total number of students: ";
    std::cin >> totalStudents;

    studentList.resize(totalStudents);

    for (int i = 0; i < totalStudents; ++i) {
        std::cout << "Enter Student ID for student " << (i + 1) << ": ";
        std::cin >> studentList[i].studentID;
        std::cin.ignore();  

        for (int j = 0; j < 3; ++j) {
            std::cout << "Enter Subject " << (j + 1) << " for Student " << studentList[i].studentID << ": ";
            std::getline(std::cin, studentList[i].subjects[j].name);
        }
    }

    std::cout << "\nStudent Details:\n";
    for (const auto& student : studentList) {
        std::cout << "Student ID: " << student.studentID << "\nSubjects: ";
        for (const auto& subject : student.subjects) {
            std::cout << subject.name << ", ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
