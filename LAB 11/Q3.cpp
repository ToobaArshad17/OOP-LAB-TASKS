#include <iostream>
#include <exception>
using namespace std;

class ArrayIndexOutOfBounds : public exception {
    public:
        const char* what() const noexcept override {
            return "ArrayIndexOutOfBounds: Invalid index accessed.";
        }
};

template<typename T>
class SafeArray {
    T* data;
    int size;

    public:
        SafeArray(int s) : size(s) {
            data = new T[size];
        }

        ~SafeArray() {
            delete[] data;
        }

        T& operator[](int index) {
            if (index < 0 || index >= size)
                throw ArrayIndexOutOfBounds();
            return data[index];
        }

        int length() const {
            return size;
        }
};

int main() {
    SafeArray<int> arr(5);

    try {
        for (int i = 0; i < arr.length(); i++) {
            arr[i] = i * 10;
        }

        for (int i = 0; i < arr.length(); i++) {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }

        cout << "Trying to access arr[7]..." << endl;
        cout << arr[7] << endl;  

    } catch (const ArrayIndexOutOfBounds& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}