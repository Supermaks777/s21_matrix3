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
  status_code status = s21_check_matrix_dimmensions(A);
  if (status == OK) {
    status = s21_create_matrix(A->columns, A->rows, result);
  }
  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return status;
}
