#include "matrix.h"

#include <cmath>
#include <iostream>

#include "fraction.h"
#include "memory.h"
#include "operations.h"

int** matrix_equation() {
    int type = 1;
    std::cout << "Please choose the type of equation(default=1):\n1. XA=B\n2. AX=B\n";
    std::cin >> type;
    if (type != 1 && type != 2) type = 1;
    int n = 0;
    int** A = nullptr;
    int** B = nullptr;
    if (matrix_equation_input(&A, &B, &n) == 0 && n > 0) {
        int** ans;
        std::cout << "----------------------------\n";
        if (type == 1) {
            int det = determinant(A, n);
            if (det != 0) {
                int** adjoint_A = adjoint_matrix(A, n);
                ans = multiply_matrices(B, adjoint_A, n);
                struct fraction** final = matrix_to_struct(ans, n);
                divide_fraction_by_int(final, n, n, det);
                output_fraction(final, n, n);
            } else {
                std::cout << "No solution!";
            }
        } else {
            int det = determinant(A, n);
            if (det != 0) {
                int** adjoint_A = adjoint_matrix(A, n);
                ans = multiply_matrices(adjoint_A, B, n);
                struct fraction** final = matrix_to_struct(ans, n);
                divide_fraction_by_int(final, n, n, det);
                output_fraction(final, n, n);
            } else {
                std::cout << "No solution!";
            }
        }
    } else {
        std::cout << "Error!";
    }
    free_memory(A, n);
    A = nullptr;
    free_memory(B, n);
    B = nullptr;
    return {};
}

int matrix_equation_input(int*** A, int*** B, int* n) {
    int flag = 0;
    std::cout << "Please enter the size of matrix n = ";
    std::cin >> (*n);
    if (!std::cin.fail()) {
        //        std::cout << "Memory allocated successfully!\n";
        *A = allocate_matrix_memory(*n);
        *B = allocate_matrix_memory(*n);
        if (*A != nullptr && *B != nullptr) {
            std::cout << "Enter the matrix A :\n";
            if (input(*A, *n) == 0) {
                if (!(std::cout << "Enter the matrix B :\n") || input(*B, *n) != 0) {
                    flag = 1;
                }
            } else {
                flag = 1;
            }
        } else {
            flag = 1;
        }
    }
    return flag;
}

int input(int** data, int size) {
    int flag = 0;
    for (int i = 0; i < size && flag == 0; ++i) {
        for (int j = 0; j < size && flag == 0; ++j) {
            std::cin >> data[i][j];
            if (std::cin.fail()) {
                flag = 1;
                std::cin.clear();
            }
        }
    }
    return flag;
}

void output(int** data, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int menu(int* t) {
    int flag = 0;
    while (!(*t >= 1 && *t <= 3) && flag == 0) {
        std::cout << "Please choose one of the options below:\n1.Solve matrix equation\n2.Solve a system of "
                     "linear equations using Gauss method\n3.Solve the system of equations by the method "
                     "Kramer\n";
        std::cin >> (*t);
        if (std::cin.fail()) {
            flag = 1;
        }
    }
    return flag;
}