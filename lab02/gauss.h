#ifndef GAUSS_H
#define GAUSS_H

void gauss();
void gauss_elimination(int** A, int* b, int size);
void make_first_element_one(struct fraction** matrix, int column, int current_row);
void row_with_min_element_on_top(struct fraction** matrix, int row, int column);
void row_to_top(struct fraction** matrix, int column, int current_row);
void operate_next_rows(struct fraction** matrix, int row, int column, int current_row);
void backward_operate_previous_rows(struct fraction** matrix, int column, int current_row);

#endif