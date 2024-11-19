#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int **mat;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new int[cols];
        }
    }

    void inputMatrix() {
        cout << "Enter elements of the matrix: " << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    Matrix operator + (const Matrix &obj) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + obj.mat[i][j];
            }
        }
        return result;
    }

    void displayMatrix() {
        cout << "Matrix: " << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }
};

int main() {
    int r, c;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> r >> c;

    Matrix m1(r, c), m2(r, c);
    cout << "Matrix 1: " << endl;
    m1.inputMatrix();

    cout << "Matrix 2: " << endl;
    m2.inputMatrix();

    Matrix m3 = m1 + m2;  // Matrix addition

    m3.displayMatrix();  // Display result

    return 0;
}
