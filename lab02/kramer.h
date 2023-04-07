#ifndef KRAMER_H
#define KRAMER_H

void kramer();
int** copy_for_kramer(int** A, const int* b, int column, int size);
int array_input(int* b, int size);
int equation_system_input(int*** A, int** b, int* size);

#endif