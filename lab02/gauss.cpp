#include "gauss.h"

#include <iostream>

#include "kramer.h"
#include "matrix.h"
#include "memory.h"
#include "operations.h"

void gauss() {
    int** A = nullptr;
    int* b = nullptr;
    int size = 0;
    if (equation_system_input(&A, &b, &size) == 0) {
    }
}

void gauss_elimination(int** A, int* b, int size) {
    // code
}