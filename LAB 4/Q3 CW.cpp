#include <iostream>
using namespace std;

class DynamicArray {
    private:
        int* data;
        int length;

    public:
        DynamicArray(){
            data = nullptr;
            length =0;
        }

        DynamicArray(int n){
            length = n;
            data = new int[length](); 
        }

        DynamicArray(const DynamicArray& other) : length(other.length) {
            data = new int[length];
            for (int i = 0; i < length; ++i) {
                data[i] = other.data[i];
            }
        }

        DynamicArray(DynamicArray&& other) noexcept : data(other.data), length(other.length) {
            other.data = nullptr;
            other.length = 0;
        }

        DynamicArray& operator=(const DynamicArray& other) {
            if (this == &other) return *this; 

            delete[] data;
            
            length = other.length;
            data = new int[length];
            for (int i = 0; i < length; ++i) {
                data[i] = other.data[i];
            }
            return *this;
        }

        DynamicArray& operator=(DynamicArray&& other) noexcept {
            if (this == &other) return *this; 
            
            delete[] data; 
            
            data = other.data;
            length = other.length;
            
            other.data = nullptr;
            other.length = 0;
            return *this;
        }

        ~DynamicArray() {
            delete[] data;
        }

        int size() const {
            return length;
        }

        int& at(int index) {
            return data[index];
        }

        const int& at(int index) const {
            return data[index];
        }

        void resize(int newSize) {
            if (newSize == length) return;
            
            int* newData = new int[newSize](); 
            int minSize = (newSize < length) ? newSize : length;
            
            for (int i = 0; i < minSize; ++i) {
                newData[i] = data[i];
            }
            
            delete[] data;
            data = newData;
            length = newSize;
        }
};

int main() {
    DynamicArray arr(5);
    for (int i = 0; i < arr.size(); ++i) {
        arr.at(i) = i * 10;
    }

    DynamicArray arr2 = arr; 
    DynamicArray arr3 = move(arr);
    
    arr2.resize(7);
    
    for (int i = 0; i < arr2.size(); ++i) {
        cout << arr2.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}