#include <iostream>
#include <string>
#include <exception>
using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Type mismatch during retrieval.";
    }
};

class BaseHolder {
    public:
        virtual ~BaseHolder() {}
};

template<typename T>
class Holder : public BaseHolder {
    public:
        T data;
        Holder(const T& value) : data(value) {}
};

class TypeSafeContainer {
    BaseHolder* item = nullptr;

    public:
        ~TypeSafeContainer() {
            delete item;
        }

        template<typename T>
        void store(const T& value) {
            delete item;
            item = new Holder<T>(value);
        }

        template<typename T>
        T get() {
            Holder<T>* ptr = dynamic_cast<Holder<T>*>(item);
            if (!ptr) {
                throw BadTypeException();
            }
            return ptr->data;
        }
};

int main() {
    TypeSafeContainer container;

    container.store(42);

    try {
        cout << "Correct get: " << container.get<int>() << endl;
        cout << "Wrong get: " << container.get<string>() << endl;
    } 
    catch (const BadTypeException& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    return 0;
}