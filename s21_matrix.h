#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define S21_PRECISION 1E-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum ERROR_CODES { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// helper
int s21_eq_size(const matrix_t *A, const matrix_t *B);
int s21_squar_size(const matrix_t *source);
int s21_eq_element(double val_1, double val_2);
int s21_eq_content(const matrix_t *A, const matrix_t *B);
int s21_compatibility_size(const matrix_t *A, const matrix_t *B);
int s21_get_minor(const matrix_t *source, int row, int column, double *result);
int s21_create_sub_matrix(const matrix_t *source, int row_del, int column_del,
                          int size, matrix_t *result);
void s21_initialize_matrix(matrix_t *source, double start, double step);
void s21_print_matrix(const matrix_t *source);
int s21_is_valid_matrix_mini(const matrix_t *source);
int s21_is_valid_matrix_midi(const matrix_t *source);
int s21_is_valid_matrix_full(const matrix_t *source);
int s21_is_valid_element(double val);
int s21_is_valid_result_ptr(const matrix_t *source);
int s21_correct_index(int index, int size);

int s21_determinant_old(matrix_t *A, double *result);
int s21_copy_matrix(const matrix_t *source, matrix_t *result);
double s21_main_diagonal_multiple(const matrix_t *source);
int s21_gauss_elimination(const matrix_t *source);
void s21_initialize_matrix_random(matrix_t *source, int shift);

#endif