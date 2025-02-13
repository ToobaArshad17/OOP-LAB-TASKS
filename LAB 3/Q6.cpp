#include <iostream>
using namespace std;

class Matrix {
    private:
        int rows;
        int columns;
        int data[5][5]; 

    public:
        Matrix(int r, int c) : rows(r), columns(c) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    data[i][j] = 0; 
                }
            }
        }

        int getRows() const {
            return rows;
        }

        int getColumns() const {
            return columns;
        }

        void setElement(int i, int j, int num) {
            if (i >= 0 && i < rows && j >= 0 && j < columns) {
                data[i][j] = num;
            } else {
                cout << "Error: Invalid index!" << endl;
            }
        }

        void display() const {
            cout << "Matrix content:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }

        Matrix add(const Matrix& second) {
            if (rows != second.rows || columns != second.columns) {
                cout << "Addition not possible: Matrices must have the same dimensions!" << endl;
                return Matrix(0, 0);
            }
            Matrix sum(rows, columns);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    sum.data[i][j] = data[i][j] + second.data[i][j];
                }
            }
            return sum;
        }

        Matrix multiply(const Matrix& second) {
            if (columns != second.rows) {
                cout << "Multiplication not possible: Columns of first matrix must match rows of second!" << endl;
                return Matrix(0, 0);
            }
            Matrix product(rows, second.columns);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < second.columns; ++j) {
                    product.data[i][j] = 0;
                    for (int k = 0; k < columns; ++k) {
                        product.data[i][j] += data[i][k] * second.data[k][j];
                    }
                }
            }
            return product;
        }
};

int main(int argc, char* argv[]) {
    if (argc < 9) {
        cout << "Insufficient input! Please provide the correct number of arguments." << endl;
        return 1;
    }
    
    int r1 = atoi(argv[1]);
    int c1 = atoi(argv[2]);
    int r2 = atoi(argv[3]);
    int c2 = atoi(argv[4]);
    
    Matrix m1(r1, c1);
    Matrix m2(r2, c2);
    
    int index = 5;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            m1.setElement(i, j, atoi(argv[index++]));
        }
    }
    
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            m2.setElement(i, j, atoi(argv[index++]));
        }
    }
    
    cout << "First Matrix:" << endl;
    m1.display();
    
    cout << "Second Matrix:" << endl;
    m2.display();
    
    Matrix sum = m1.add(m2);
    cout << "Result of Matrix Addition:" << endl;
    sum.display();
    
    Matrix product = m1.multiply(m2);
    cout << "Result of Matrix Multiplication:" << endl;
    product.display();
    
    return 0;
}
