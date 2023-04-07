#include "operations.h"

#include <cmath>
#include <iostream>

#include "matrix.h"
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
        //        std::cout << "Minor of Matrix : \n";
        //        output(algebraic, size);
        //        std::cout << "-------------------------------\n";
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
                //                std::cout << "Removed the row=" << i << " and the column=" << j <<
                //                std::endl;
                int** temp = remove_row_column(A, i, j, size);
                if (temp != NULL) {
                    //                    output(temp, size - 1);
                    int det = determinant(temp, size - 1);
                    //                    std::cout << std::endl
                    //                              << "Determinant=" << det << std::endl
                    //                              << "---------------------------\n";
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
        //        std::cout << "Removing row and column function: Memory allocated succesfully!\n";
        int x_0 = 0, y_0 = 0;
        for (int i = 0; i < size; ++i) {
            if (i != x) {
                for (int j = 0; j < size; ++j) {
                    if (j != y) {
                        //                    std::cout << x_0 << " " << y_0 << "  <---  " << i << " " << j <<
                        //                    std::endl;
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

void check_answer(int** A, int** B, int** X, int size) {
    int** ans = multiply_matrices(A, X, size);
    int flag = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (ans[i][j] != B[i][j]) flag = 1;
        }
    }
    if (flag == 0) std::cout << "A*ans=B\n";

    ans = multiply_matrices(X, A, size);
    flag = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (ans[i][j] != B[i][j]) flag = 1;
        }
    }
    if (flag == 0) std::cout << "ans*A=B\n";
}

int is_divisible(int** A, int num, int size) {
    if (num < 0) num *= -1;
    int flag = 1;
    for (int i = 0; i < size && flag == 1; ++i) {
        for (int j = 0; j < size && flag == 1; ++j) {
            if ((A[i][j] % num) != 0) flag = 0;
        }
    }
    return flag;
}