#ifndef MATRIX_H
#define MATRIX_H

// functions related to solution of matrix equation
int** matrix_equation();
int matrix_equation_input(int*** A, int*** B, int* n);

// general functions
void free_memory(int** data, int size);
int** allocate_matrix_memory(int n);
int input(int** data, int size);
void output(int** data, int size);
int menu(int* t);
int determinant(int** data, int size);

#endif