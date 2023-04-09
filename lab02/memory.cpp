#include "memory.h"

#include <stdlib.h>

#include "fraction.h"

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

void free_fraction_memory(struct fraction** data, int row) {
    for (int i = 0; i < row; ++i) {
        if (data[i] != nullptr) free(data[i]);
        data[i] = nullptr;
    }
    free(data);
}

struct fraction** allocate_fraction_memory(int row, int column) {
    struct fraction** data = (struct fraction**)calloc(row, sizeof(struct fraction*));
    if (data != nullptr) {
        int flag = 0;
        for (int i = 0; i < row && flag == 0; ++i) {
            data[i] = (struct fraction*)calloc(column, sizeof(struct fraction));
            if (!data[i]) flag = 1;
        }
        if (flag == 1) {
            free_fraction_memory(data, row);
            data = nullptr;
        }
    }
    return data;
}