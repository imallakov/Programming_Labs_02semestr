#ifndef FRACTION_H
#define FRACTION_H

struct fraction {
    int numerator;
    int denominator;
};

struct fraction** matrix_to_struct(int** A, int size);
struct fraction** matrix_to_gauss_struct(int** A, const int* b, int size);
void output_fraction(struct fraction** data, int row, int column);
void print_fraction(struct fraction fract);
void divide_fraction_by_int(struct fraction** data, int row, int column, int num);
void gcd_fraction(struct fraction** data, int row, int column);
struct fraction divide_fraction_by_fraction(struct fraction first, struct fraction second);
struct fraction multiply_fraction_to_fraction(struct fraction first, struct fraction second);
struct fraction subtract_fraction_from_fraction(struct fraction first, struct fraction second);
struct fraction gcd_one_fraction(struct fraction data);
int compare_fractions(struct fraction first, struct fraction second);
void output_in_normal_view(struct fraction** matrix, int row, int column);

#endif