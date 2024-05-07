#include "../s21_matrix.h"
/**
 * @brief умножение матриц
 *
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err_code = s21_check_matrix_dimmensions(A);
  if (err_code == OK) err_code = s21_check_matrix_dimmensions(B);
  if (err_code == OK) err_code = s21_check_matrix_mutipliety(A, B);
  if (err_code == OK) err_code = s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; err_code == OK && i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < B->rows; k++) result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }
  return err_code;
}