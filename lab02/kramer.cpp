#include "kramer.h"

#include <stdlib.h>

#include <iostream>

#include "matrix.h"
#include "memory.h"
#include "operations.h"

void kramer() {
    int** A = nullptr;
    int* b = nullptr;
    int size = 0;
    if (kramer_input(&A, &b, &size) == 0) {
        int det = determinant(A, size);
        //        std::cout << "Det = " << det << std::endl;
        if (det != 0) {
            for (int i = 0; i < size; ++i) {
                int** temp = copy_for_kramer(A, b, i, size);
                int temp_det = determinant(temp, size);
                //                std::cout << "-------matrix" << i << "-------\n";
                //                output(temp, size);
                //                std::cout << "det" << i + 1 << " = " << temp_det << std::endl;
                double x = (double)temp_det / (double)det;
                std::cout << "x" << i + 1 << " = " << x << std::endl;
            }
        } else {
            std::cout << "Either the system has no solution or it has an infinite number of solutions!\n";
        }
    }
}

int kramer_input(int*** A, int** b, int* size) {
    int flag = 0;
    std::cout << "Please enter the size of matrix n = ";
    std::cin >> (*size);
    if (!std::cin.fail()) {
        //        std::cout << "Memory allocated successfully!\n";
        *A = allocate_matrix_memory(*size);
        *b = (int*)calloc(*size, sizeof(int));
        if (*A != nullptr && *b != nullptr) {
            std::cout << "Enter the matrix A :\n";
            if (input(*A, *size) == 0) {
                //                std::cout << "Enter the matrix b :\n";
                if (!(std::cout << "Enter the matrix b :\n") || array_input(*b, *size) != 0) {
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

int array_input(int* b, int size) {
    int flag = 0;
    for (int i = 0; i < size && flag == 0; ++i) {
        std::cin >> b[i];
        if (std::cin.fail()) {
            flag = 1;
        }
    }
    return flag;
}

int** copy_for_kramer(int** A, const int* b, int column, int size) {
    int** temp = allocate_matrix_memory(size);
    if (temp != NULL) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                temp[i][j] = A[i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            temp[i][column] = b[i];
        }
    }
    return temp;
}