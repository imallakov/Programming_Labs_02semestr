#include <stdlib.h>

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