#include <iostream>
using namespace std;

void* incrementArray(void* arr, void* size, void* increment) {
    int* intArr = static_cast<int*>(arr);
    int arrSize = *static_cast<int*>(size); 
    int incValue = *static_cast<int*>(increment);  

    for (int i = 0; i < arrSize; i++) {
        intArr[i] += incValue;
    }
    return static_cast<void*>(intArr);
}

int main(int argc, char* argv[]) {
    int n, incrementValue;

    if (argc < 3) {
        cout << "Enter the size of the array: ";
        cin >> n;
        cout << "Enter the value to be added: ";
        cin >> incrementValue;

        int* arr = new int[n];

        cout << "Enter " << n << " elements for the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Initial Array:" << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        void* updatedArray = incrementArray(arr, &n, &incrementValue);

        cout << "Updated Array (after adding " << incrementValue << " to each element):" << endl;
        int* intArr = static_cast<int*>(updatedArray);
        for (int i = 0; i < n; i++) {
            cout << intArr[i] << " ";
        }
        cout << endl;

        delete[] arr;
    } else {
        n = atoi(argv[1]);
        incrementValue = atoi(argv[2]);

        int* arr = new int[n];

        for (int i = 0; i < n; i++) {
            if (i + 3 < argc) {
                arr[i] = atoi(argv[i + 3]);
            } else {
                cout << "Insufficient array elements provided!" << endl;
                delete[] arr;
                return 1;
            }
        }

        cout << "Initial Array:" << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        void* updatedArray = incrementArray(arr, &n, &incrementValue);

        cout << "Updated Array (after adding " << incrementValue << " to each element):" << endl;
        int* intArr = static_cast<int*>(updatedArray);
        for (int i = 0; i < n; i++) {
            cout << intArr[i] << " ";
        }
        cout << endl;

        delete[] arr;
    }

    return 0;
}
