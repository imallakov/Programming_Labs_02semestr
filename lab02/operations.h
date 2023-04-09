#ifndef OPERATIONS_H
#define OPERATIONS_H

int** multiply_matrices(int** A, int** B, int size);
void multiply_number_to_matrix(double num, int** A, int size);
int determinant(int** data, int size);
// int** inverse_matrix(int** A, int size);
int** transpose_matrix(int** A, int size);
int** matrix_minor(int** A, int size);
int** remove_row_column(int** A, int x, int y, int size);
int** adjoint_matrix(int** A, int size);
int great_common_divisor(int first_number, int second_number);
#endif