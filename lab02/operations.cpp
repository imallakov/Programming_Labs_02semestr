#include "operations.h"

#include <cmath>
#include <iostream>

#include "memory.h"

int** multiply_matrices(int** A, int** B, int size) {
    int** result = allocate_matrix_memory(size);
    if (result != NULL) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int sum = 0;
                for (int k = 0; k < size; ++k) {
                    sum += A[i][k] * B[k][j];
                }
                result[i][j] = sum;
            }
        }
    }
    return result;
}

void multiply_number_to_matrix(double num, int** A, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A[i][j] = (int)round(A[i][j] * num);
        }
    }
}

int determinant(int** data, int size) {
    if (size == 1) {
        return data[0][0];
    }
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
            //            std::cout << "-----------------------\n";
            sum += minor;
        }
        free_memory(temp, size - 1);
    }
    return sum;
}

// int** inverse_matrix(int** A, int size) {
//     // code
//     return {};
// }

int** transpose_matrix(int** A, int size) {
    int** A_t = allocate_matrix_memory(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A_t[j][i] = A[i][j];
        }
    }
    return A_t;
}

int** adjoint_matrix(int** A, int size) {
    int** algebraic = matrix_minor(A, size);
    if (algebraic != NULL) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                algebraic[i][j] = pow(-1, i + 1 + j + 1) * algebraic[i][j];
            }
        }
        algebraic = transpose_matrix(algebraic, size);
    }
    return algebraic;
}

int** matrix_minor(int** A, int size) {
    int** minor = allocate_matrix_memory(size);
    if (minor != NULL) {
        int flag = 0;
        for (int i = 0; i < size && flag == 0; ++i) {
            for (int j = 0; j < size && flag == 0; ++j) {
                int** temp = remove_row_column(A, i, j, size);
                if (temp != NULL) {
                    int det = determinant(temp, size - 1);
                    minor[i][j] = det;
                } else {
                    flag = 1;
                    free_memory(temp, size - 1);
                }
            }
        }
        if (flag) {
            free_memory(minor, size);
            minor = NULL;
        }
    }
    return minor;
}

int** remove_row_column(int** A, int x, int y, int size) {
    int** result = allocate_matrix_memory(size - 1);
    if (result != NULL) {
        int x_0 = 0, y_0 = 0;
        for (int i = 0; i < size; ++i) {
            if (i != x) {
                for (int j = 0; j < size; ++j) {
                    if (j != y) {
                        result[x_0][y_0] = A[i][j];
                        y_0++;
                        if (y_0 == size - 1) {
                            y_0 = 0;
                            x_0++;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int great_common_divisor(int first_number, int second_number) {
    int gcd = 1;
    int num = 2;
    first_number = abs(first_number);
    second_number = abs(second_number);
    while (num <= std::min(first_number, second_number)) {
        if (first_number % num == 0 && second_number % num == 0) {
            gcd = num;
        }
        num++;
    }
    return gcd;
}