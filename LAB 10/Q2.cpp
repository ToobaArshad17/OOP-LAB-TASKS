#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int yearsOfService;
};

const string FILENAME = "employees.txt";

void createDummyData();
vector<Employee> readAllEmployees();
void writeAllEmployees(const vector<Employee>& employees);
vector<Employee> findManagersWithMinYears(int minYears);
void deleteAllExcept(const vector<Employee>& employeesToKeep);
void duplicateWithIncrementedIdsAndYears(const vector<Employee>& employees);

int main() {
    createDummyData();

    cout << "\nQuery a) Managers with at least 2 years of service:\n";
    vector<Employee> managers = findManagersWithMinYears(2);
    for (const auto& emp : managers) {
        cout << emp.id << ", " << emp.name << ", " << emp.designation << ", " << emp.yearsOfService << endl;
    }
    
    deleteAllExcept(managers);
    cout << "\nAfter deletion, remaining employees:\n";
    vector<Employee> remaining = readAllEmployees();
    for (const auto& emp : remaining) {
        cout << emp.id << ", " << emp.name << ", " << emp.designation << ", " << emp.yearsOfService << endl;
    }
    
    duplicateWithIncrementedIdsAndYears(remaining);
    cout << "\nAfter duplication with incremented IDs and years:\n";
    vector<Employee> finalData = readAllEmployees();
    for (const auto& emp : finalData) {
        cout << emp.id << ", " << emp.name << ", " << emp.designation << ", " << emp.yearsOfService << endl;
    }
    
    return 0;
}

void createDummyData() {
    vector<Employee> employees = {
        {1, "ALi kHan", "Manager", 3},
        {2, "Sara Mannan", "Developer", 1},
        {3, "Aliza Faraz", "Manager", 5},
        {4, "Arsalan Laraib", "Designer", 2},
        {5, "Laiba Nusrat", "Manager", 1}
    };
    
    writeAllEmployees(employees);
}

vector<Employee> readAllEmployees() {
    vector<Employee> employees;
    ifstream inFile(FILENAME);
    
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return employees;
    }
    
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        Employee emp;
        
        getline(ss, token, ',');
        emp.id = stoi(token);
        
        getline(ss, emp.name, ',');
        getline(ss, emp.designation, ',');
        
        getline(ss, token);
        emp.yearsOfService = stoi(token);
        
        employees.push_back(emp);
    }
    
    inFile.close();
    return employees;
}

void writeAllEmployees(const vector<Employee>& employees) {
    ofstream outFile(FILENAME);
    
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    
    for (const auto& emp : employees) {
        outFile << emp.id << "," << emp.name << "," << emp.designation << "," << emp.yearsOfService << endl;
    }
    
    outFile.close();
}

vector<Employee> findManagersWithMinYears(int minYears) {
    vector<Employee> allEmployees = readAllEmployees();
    vector<Employee> result;
    
    for (const auto& emp : allEmployees) {
        if (emp.designation == "Manager" && emp.yearsOfService >= minYears) {
            result.push_back(emp);
        }
    }
    
    return result;
}

void deleteAllExcept(const vector<Employee>& employeesToKeep) {
    writeAllEmployees(employeesToKeep);
}

void duplicateWithIncrementedIdsAndYears(const vector<Employee>& employees) {
    vector<Employee> allEmployees = employees; 
    
    for (const auto& emp : employees) {
        Employee newEmp = emp;
        newEmp.id += 10; 
        newEmp.yearsOfService += 1;
        allEmployees.push_back(newEmp);
    }
    
    writeAllEmployees(allEmployees);
}