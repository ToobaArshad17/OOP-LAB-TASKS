#include <iostream>
#include <string>
using namespace std;

int main() {
    string studentName;
    float scores[5], total = 0, avg = 0;

    cout << "Enter name: ";
    getline(cin, studentName);

    cout << "Enter test scores: ";
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
        total += scores[i];
    }

    avg = total / 5;

    cout << "Student name: " << studentName << endl;
    cout << "Test Scores: ";
    for (int i = 0; i < 5; i++) {
        cout << scores[i] << " ";
    }

    cout << "\nAverage test score: " << avg;

    return 0;
}
