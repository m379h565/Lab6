#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the square matrices

// Function prototypes
void readMatrixFromFile(int matrix[][MAX_SIZE], int size, ifstream& inputFile);
void printMatrix(const int matrix[][MAX_SIZE], int size);
void addMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size);

int main() {
    cout << "Zia Hosainzada" << endl;
    cout << "Lab #6: Matrix manipulation" << endl << endl;

    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size; // Size of the square matrices

    ifstream inputFile("matrix_input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    inputFile >> size; // Read the size of the square matrix

    // Read the first matrix (Matrix A)
    readMatrixFromFile(matrix1, size, inputFile);

    // Read the second matrix (Matrix B)
    readMatrixFromFile(matrix2, size, inputFile);

    inputFile.close();

    cout << "Matrix A:" << endl;
    printMatrix(matrix1, size);

    cout << "Matrix B:" << endl;
    printMatrix(matrix2, size);

    // Add matrices and print the result
    addMatrices(matrix1, matrix2, result, size);
    cout << "Matrix Sum (A + B):" << endl;
    printMatrix(result, size);

    // Multiply matrices and print the result
    multiplyMatrices(matrix1, matrix2, result, size);
    cout << "Matrix Product (A * B):" << endl;
    printMatrix(result, size);

    // Subtract matrices and print the result
    subtractMatrices(matrix1, matrix2, result, size);
    cout << "Matrix Difference (A - B):" << endl;
    printMatrix(result, size);

    return 0;
}

// Function to read matrix data from a file
void readMatrixFromFile(int matrix[][MAX_SIZE], int size, ifstream& inputFile) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> matrix[i][j]; // Read matrix values from the file
        }
    }
}

// Function to print a matrix
void printMatrix(const int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices and store the result in a third matrix
void addMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices and store the result in a third matrix
void multiplyMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another and store the result in a third matrix
void subtractMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
