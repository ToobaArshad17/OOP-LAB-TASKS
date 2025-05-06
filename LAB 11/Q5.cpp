#include <iostream>
#include <exception>
using namespace std;

class StackUnderflowException : public exception {
    public:
        const char* what() const noexcept override {
            return "StackUnderflowException: Stack is empty.";
        }
};

template<typename T>
class Stack {
    T* data;
    int topIndex;
    int capacity;

    public:
        Stack(int size = 100) {
            capacity = size;
            data = new T[capacity];
            topIndex = -1;
        }

        ~Stack() {
            delete[] data;
        }

        void push(const T& value) {
            if (topIndex + 1 == capacity) {
                cout << "Stack is full. Cannot push more." << endl;
                return;
            }
            data[++topIndex] = value;
        }

        void pop() {
            if (isEmpty())
                throw StackUnderflowException();
            --topIndex;
        }

        T top() const {
            if (isEmpty())
                throw StackUnderflowException();
            return data[topIndex];
        }

        bool isEmpty() const {
            return topIndex == -1;
        }
};

int main() {
    Stack<int> s(5);

    try {
        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Top element: " << s.top() << endl;

        s.pop();
        s.pop();
        s.pop();

        cout << "Trying to access top of empty stack..." << endl;
        cout << "Top element: " << s.top() << endl;  // ? Should throw exception

    } catch (const StackUnderflowException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}