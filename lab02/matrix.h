#ifndef MATRIX_H
#define MATRIX_H

// functions related to solution of matrix equation
int** matrix_equation();
int matrix_equation_input(int*** A, int*** B, int* n);

// general functions
int input(int** data, int size);
void output(int** data, int size);
int menu(int* t);

#endif