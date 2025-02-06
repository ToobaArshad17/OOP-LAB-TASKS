#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int empID;
    string empName;
};

void swap(Employee &x, Employee &y) {
    Employee temp = x;
    x = y;
    y = temp;
}

void sortByIdThenName(Employee workers[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (workers[j].empID > workers[j + 1].empID || 
               (workers[j].empID == workers[j + 1].empID && workers[j].empName[0] > workers[j + 1].empName[0])) {
                swap(workers[j], workers[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "How many employees do you want to enter? ";
    cin >> n;

    Employee workers[n]; 

    for (int i = 0; i < n; i++) {
        cout << "Enter Employee ID and Name for entry " << i + 1 << ": ";
        cin >> workers[i].empID >> workers[i].empName;
    }

    sortByIdThenName(workers, n);

    cout << "\nSorted list (by Employee ID and first letter of Name):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "ID: " << workers[i].empID << ", Name: " << workers[i].empName << endl;
    }

    return 0;
}
