#include "../s21_matrix.h"
/**
 * @brief создает транспонированную матрицу
 *
 * @param A исходная матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  int err_code = s21_check_matrix_dimmensions(A);
  if (err_code == OK) err_code = s21_create_matrix(A->columns, A->rows, result);
  if (err_code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return err_code;
}
