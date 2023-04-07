#include <iostream>

#include "matrix.h"
#include "memory.h"
#include "operations.h"

int main() {
    int n;
    std::cout << "Enter the size of matrix: ";
    std::cin >> n;
    int** A = allocate_matrix_memory(n);
    std::cout << "Enter the matrix :\n";
    input(A, n);
    int det = determinant(A, n);
    std::cout << "Matrix : \n";
    output(A, n);
    std::cout << "------------------------------\n";
    A = adjoint_matrix(A, n);
    std::cout << 1 << "/" << det << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}