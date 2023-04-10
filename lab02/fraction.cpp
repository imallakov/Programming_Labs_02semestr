#include "fraction.h"

#include <iostream>

#include "memory.h"
#include "operations.h"

struct fraction** matrix_to_struct(int** A, int size) {
    struct fraction** data = allocate_fraction_memory(size, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j].numerator = A[i][j];
            data[i][j].denominator = 1;
        }
    }
    return data;
}

struct fraction** matrix_to_gauss_struct(int** A, const int* b, int size) {
    struct fraction** data = allocate_fraction_memory(size, size + 1);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j].numerator = A[i][j];
            data[i][j].denominator = 1;
        }
        data[i][size].denominator = 1;
        data[i][size].numerator = b[i];
    }
    return data;
}

void output_fraction(struct fraction** data, int row, int column) {
    std::cout << "------------------------------------\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (j) std::cout << "\t";
            print_fraction(data[i][j]);
        }
        std::cout << std::endl;
    }
}

void print_fraction(struct fraction fract) {
    if (fract.denominator != 1) {
        std::cout << fract.numerator << "/" << fract.denominator;
    } else {
        std::cout << fract.numerator;
    }
}

void divide_fraction_by_int(struct fraction** data, int row, int column, int num) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            data[i][j].denominator *= num;
        }
    }
    gcd_fraction(data, row, column);
}

void gcd_fraction(struct fraction** data, int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if ((data[i][j].numerator < 0 && data[i][j].denominator < 0) ||
                (data[i][j].denominator < 0 && data[i][j].numerator > 0)) {
                data[i][j].numerator *= -1;
                data[i][j].denominator *= -1;
            }
            if (data[i][j].numerator != 0) {
                int temp = great_common_divisor(data[i][j].numerator, data[i][j].denominator);
                data[i][j].numerator /= temp;
                data[i][j].denominator /= temp;
            } else {
                data[i][j].numerator = 0;
                data[i][j].denominator = 1;
            }
        }
    }
}

struct fraction divide_fraction_by_fraction(struct fraction first, struct fraction second) {
    struct fraction temp = first;
    temp.numerator *= second.denominator;
    temp.denominator *= second.numerator;
    temp = gcd_one_fraction(temp);
    return temp;
}

struct fraction multiply_fraction_to_fraction(struct fraction first, struct fraction second) {
    struct fraction temp = first;
    temp.numerator *= second.numerator;
    temp.denominator *= second.denominator;
    temp = gcd_one_fraction(temp);
    return temp;
}

struct fraction subtract_fraction_from_fraction(struct fraction first, struct fraction second) {
    struct fraction temp = first;
    first.numerator *= second.denominator;
    first.denominator *= second.denominator;
    second.numerator *= temp.denominator;
    temp = first;
    temp.numerator -= second.numerator;
    temp = gcd_one_fraction(temp);
    return temp;
}

struct fraction gcd_one_fraction(struct fraction data) {
    if ((data.numerator < 0 && data.denominator < 0) || (data.denominator < 0 && data.numerator > 0)) {
        data.numerator *= -1;
        data.denominator *= -1;
    }
    if (data.numerator != 0) {
        int temp = great_common_divisor(data.numerator, data.denominator);
        data.numerator /= temp;
        data.denominator /= temp;
    } else {
        data.numerator = 0;
        data.denominator = 1;
    }
    return data;
}

int compare_fractions(struct fraction first, struct fraction second) {
    int flag = 0;
    if (first.denominator != second.denominator) {
        first.numerator *= second.denominator;
        second.numerator *= first.denominator;
    }
    if (first.numerator > second.numerator) flag = 1;
    if (first.numerator < second.numerator) flag = 2;
    return flag;
}

void output_in_normal_view(struct fraction** matrix, int row, int column) {
    std::cout << "------------------------------------\n";
    for (int i = 0; i < row; ++i) {
        int flag = 0;
        for (int j = i; j < column; ++j) {
            if ((abs(matrix[i][j].numerator) != 1 || abs(matrix[i][j].denominator) != 1) &&
                matrix[i][j].numerator != 0) {
                if (flag == 1) std::cout << "+ ";
                if (matrix[i][j].denominator != 1) std::cout << "(";
                if (j > i && j < column - 1) {
                    print_fraction(multiply_fraction_to_fraction({-1, 1}, matrix[i][j]));
                } else {
                    print_fraction(matrix[i][j]);
                }
                if (matrix[i][j].denominator != 1) std::cout << ")";
                flag = 1;
            }
            if (matrix[i][j].numerator != 0 && j < column - 1) {
                std::cout << "x" << j + 1;
                if (j == i) {
                    std::cout << " = ";
                    flag = 2;
                } else {
                    std::cout << " ";
                    flag = 1;
                }
            }
        }
        if (flag) std::cout << std::endl;
    }
}