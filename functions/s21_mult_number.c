#include "../s21_matrix.h"
/**
 * @brief умножение матрицы на число
 *
 * @param A матрица (matrix_t)
 * @param number число (double)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err_code = s21_check_matrix_dimmensions(A);
  if (err_code == OK) err_code = s21_check_number(number);
  if (err_code == OK) err_code = s21_create_matrix(A->rows, A->columns, result);
  if (err_code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return err_code;
}
