#include "../s21_matrix.h"
/**
 * @brief вычитает матрицы
 *
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err_code = s21_check_matrix_dimmensions(A);
  if (err_code == OK) err_code = s21_check_matrix_dimmensions(B);
  if (err_code == OK) err_code = s21_check_matrix_dimmension_equality(A, B);
  if (err_code == OK) err_code = s21_create_matrix(A->rows, A->columns, result);
  if (err_code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return err_code;
}