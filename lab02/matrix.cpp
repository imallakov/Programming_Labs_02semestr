#include "matrix.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

int main() {
    int t = 0, flag;
    flag = menu(&t);
    if (flag == 0) {
        if (t == 1) {
            matrix_equation();
        }
        if (t == 2) {
            // code
        }
        if (t == 3) {
            // code
        }
    } else {
        std::cout << "Error!";
    }
    return 0;
}

int** matrix_equation() {
    int type = 1;
    std::cout << "Please choose the type of equation(default=1):\n1. XA=B\n2. AX=B\n";
    std::cin >> type;
    if (type != 1 && type != 2) type = 1;
    int n = 0;
    int** A = nullptr;
    int** B = nullptr;
    if (matrix_equation_input(&A, &B, &n) == 0) {
        //        output(A, n);
        std::cout << determinant(A, n) << std::endl;
        std::cout << determinant(B, n) << std::endl;
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
                //                std::cout << "Enter the matrix B :\n";
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

void free_memory(int** data, int size) {
    for (int i = 0; i < size; ++i) {
        if (data[i] != nullptr) free(data[i]);
        data[i] = nullptr;
    }
    free(data);
}

int** allocate_matrix_memory(int size) {
    int** data = (int**)calloc(size, sizeof(int*));
    if (data != nullptr) {
        int flag = 0;
        for (int i = 0; i < size && flag == 0; ++i) {
            data[i] = (int*)calloc(size, sizeof(int));
            if (!data[i]) flag = 1;
        }
        if (flag == 1) {
            free_memory(data, size);
            data = nullptr;
        }
    }
    return data;
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

int determinant(int** data, int size) {
    if (size == 2) {
        return (data[0][0] * data[1][1]) - (data[0][1] * data[1][0]);
    }
    int sum = 0;
    int** temp = allocate_matrix_memory(size - 1);
    if (temp != nullptr) {
        //        std::cout << "Memory for temporary matrix is allocated succesfully!\n";
        for (int i = 0; i < size; ++i) {
            int x = 0, y = 0, y1 = 0;
            while (x < size - 1 && y < size - 1) {
                if (y1 == i) ++y1;
                temp[x][y] = data[x + 1][y1];
                ++y1;
                ++y;
                if (y == size - 1) {
                    y1 = 0;
                    y = 0;
                    x++;
                }
            }
            int minor = (int)pow(-1, 0 + i) * data[0][i] * determinant(temp, size - 1);
            //            output(temp, size - 1);
            //            std::cout << (int)pow(-1, 0 + i) << "   " << minor << std::endl;
            sum += minor;
        }
        free_memory(temp, size - 1);
    }
    return sum;
}