#include "gauss.h"

#include <iostream>

#include "fraction.h"
#include "kramer.h"

void gauss() {
    int** A = nullptr;
    int* b = nullptr;
    int size = 0;
    if (equation_system_input(&A, &b, &size) == 0 && size > 0) {
        std::cout << "-----CREATING EXTENDED MATRIX!------\n";
        struct fraction** matrix = matrix_to_gauss_struct(A, b, size);
        output_fraction(matrix, size, size + 1);
        std::cout << "THE ROW WITH MINIMAL ELEMENT SHOUL BE ON THE TOP!\n";
        row_with_min_element_on_top(matrix, size, size + 1);
        output_fraction(matrix, size, size + 1);
        std::cout << "--------OPERATING FORWARD!---------\n";
        for (int i = 0; i < size - 1; ++i) {
            //            std::cout << "--------------- i = " << i << " --------------\n";
            if (matrix[i][i].numerator != 1 || matrix[i][i].denominator != 1) {
                //                std::cout << "Making first element equal to one!\n";
                make_first_element_one(matrix, size, size + 1, i);
                //                output_fraction(matrix, size, size + 1);
            }
            //            std::cout << "Operating the next rows!\n";
            operate_next_rows(matrix, size, size + 1, i);
            //            output_fraction(matrix, size, size + 1);
        }
        output_fraction(matrix, size, size + 1);
        std::cout << "--------OPERATING BACKWARD!---------\n";
        for (int i = size - 1; i > 0; --i) {
            //            std::cout << "Operating the next rows!\n";
            backward_operate_previous_rows(matrix, size, size + 1, i);
            //            output_fraction(matrix, size, size + 1);
        }
        output_fraction(matrix, size, size + 1);
        std::cout << "----------FINAL SOLUTION!-----------\n";
        output_in_normal_view(matrix, size, size + 1);
    } else {
        std::cout << "Error!";
    }
}

void gauss_elimination(struct fraction** matrix, int row, int column) {
    for (int i = 0; i < row - 1; ++i) {
        make_first_element_one(matrix, row, column, i);
    }
}

void make_first_element_one(struct fraction** matrix, int row, int column, int current_row) {
    struct fraction temp = matrix[current_row][current_row];
    for (int i = 0; i < column; ++i) {
        matrix[current_row][i] = divide_fraction_by_fraction(matrix[current_row][i], temp);
    }
}

void row_with_min_element_on_top(struct fraction** matrix, int row, int column) {
    int min_ind = 0;
    for (int i = 0; i < row; ++i) {
        if (compare_fractions(matrix[i][0], matrix[min_ind][0]) == 2) {
            min_ind = i;
        }
    }
    if (min_ind != 0) {
        row_to_top(matrix, row, column, min_ind);
    }
}

void row_to_top(struct fraction** matrix, int row, int column, int current_row) {
    while (current_row > 0) {
        for (int i = 0; i < column; ++i) {
            struct fraction temp = matrix[current_row - 1][i];
            matrix[current_row - 1][i] = matrix[current_row][i];
            matrix[current_row][i] = temp;
        }
        --current_row;
    }
}

void operate_next_rows(struct fraction** matrix, int row, int column, int current_row) {
    for (int i = current_row + 1; i < row; ++i) {
        struct fraction multiple = matrix[i][current_row];
        for (int j = 0; j < column; ++j) {
            struct fraction temp = multiply_fraction_to_fraction(matrix[current_row][j], multiple);
            matrix[i][j] = subtract_fraction_from_fraction(matrix[i][j], temp);
        }
        if (matrix[i][i].numerator != 1 || matrix[i][i].denominator != 1) {
            make_first_element_one(matrix, row, column, i);
        }
    }
}

void backward_operate_previous_rows(struct fraction** matrix, int row, int column, int current_row) {
    for (int i = current_row - 1; i >= 0; --i) {
        struct fraction multiple = matrix[i][current_row];
        for (int j = 0; j < column; ++j) {
            struct fraction temp = multiply_fraction_to_fraction(matrix[current_row][j], multiple);
            matrix[i][j] = subtract_fraction_from_fraction(matrix[i][j], temp);
        }
        if (matrix[i][i].numerator != 1 || matrix[i][i].denominator != 1) {
            make_first_element_one(matrix, row, column, i);
        }
    }
}