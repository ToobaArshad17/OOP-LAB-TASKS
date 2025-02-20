#include <iostream>
using namespace std;

class Matrix {
    int rows;
    int cols;
    double **mat;

public:

    Matrix() : rows(0), cols(0), mat(nullptr) {}

    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        mat = new double*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new double[cols]();
        }
    }

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        mat = new double*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), mat(other.mat) {
        other.rows = 0;
        other.cols = 0;
        other.mat = nullptr;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    double& at(int r, int c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return mat[r][c];
        }
        throw out_of_range("Index out of range");
    }

    void fill(double value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = value;
            }
        }
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed.mat[j][i] = mat[i][j];
            }
        }
        return transposed;
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(3, 1);

    m1.fill(5.0);
    cout << "Matrix m1:" << endl;
    m1.display();

    Matrix m1_transposed = m1.transpose();
    cout << "Transposed m1:" << endl;
    m1_transposed.display();

    Matrix m2(m1);
    cout << "Matrix m2 (copy of m1):" << endl;
    m2.display();

    Matrix m3 = move(m1);
    cout << "Matrix m3 (moved from m1):" << endl;
    m3.display();

    return 0;
}