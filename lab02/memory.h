#ifndef MEMORY_H
#define MEMORY_H

void free_memory(int** data, int size);
int** allocate_matrix_memory(int size);
void free_fraction_memory(int** data, int row);
struct fraction** allocate_fraction_memory(int row, int column);
#endif