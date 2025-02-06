#include <iostream>
using namespace std;

int main() {
    int capacity = 5;  
    int count = 0;      
    int* numbers = new int[capacity];

    cout << "Start entering numbers (enter 0 to stop):" << endl;
    while (true) {
        int input;
        cin >> input;
        if (input == 0) break;

        if (count >= capacity * 2) {
            int newCapacity = capacity * 2;
            int* tempArray = new int[newCapacity];
            for (int i = 0; i < capacity; i++) {
                tempArray[i] = numbers[i];
            }
            delete[] numbers;
            numbers = tempArray;
            capacity = newCapacity;
            cout << "Array resized to capacity: " << capacity << endl;
        }
        numbers[count++] = input;
    }

    int* finalNumbers = new int[count];
    for (int i = 0; i < count; i++) {
        finalNumbers[i] = numbers[i];
    }
    delete[] numbers;
    numbers = finalNumbers;
    capacity = count;
    cout << "Final resized array capacity: " << capacity << endl;

    cout << "Final array: ";
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    delete[] numbers;
    return 0;
}
