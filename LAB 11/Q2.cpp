#include <iostream>
#include <exception>
using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "DimensionMismatchException: Matrix dimensions are incompatible.";
    }
};

class OutOfBoundsException : public exception {
public:
    const char* what() const noexcept override {
        return "OutOfBoundsException: Index is out of matrix bounds.";
    }
};

template<typename T>
class Matrix {
    int rows, cols;
    T** data;

    public:
        Matrix(int r, int c) : rows(r), cols(c) {
            data = new T*[rows];
            for (int i = 0; i < rows; i++)
                data[i] = new T[cols]();
        }

        ~Matrix() {
            for (int i = 0; i < rows; i++)
                delete[] data[i];
            delete[] data;
        }

        T& at(int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols)
                throw OutOfBoundsException();
            return data[r][c];
        }

        Matrix<T> operator+(const Matrix<T>& other) {
            if (rows != other.rows || cols != other.cols)
                throw DimensionMismatchException();

            Matrix<T> result(rows, cols);
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    result.data[i][j] = data[i][j] + other.data[i][j];
            return result;
        }

        Matrix<T> operator*(const Matrix<T>& other) {
            if (cols != other.rows)
                throw DimensionMismatchException();

            Matrix<T> result(rows, other.cols);
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < other.cols; j++)
                    for (int k = 0; k < cols; k++)
                        result.data[i][j] += data[i][k] * other.data[k][j];
            return result;
        }

        void display() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                    cout << data[i][j] << " ";
                cout << endl;
            }
        }
};

int main() {
    Matrix<int> A(2, 2), B(2, 2);

    A.at(0, 0) = 1; A.at(0, 1) = 2;
    A.at(1, 0) = 3; A.at(1, 1) = 4;

    B.at(0, 0) = 5; B.at(0, 1) = 6;
    B.at(1, 0) = 7; B.at(1, 1) = 8;

    try {
        Matrix<int> C = A + B;
        cout << "A + B:\n";
        C.display();

        Matrix<int> D = A * B;
        cout << "A * B:\n";
        D.display();

    } 
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}