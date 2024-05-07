#include "../s21_matrix.h"
/**
 * @brief инвертирует матрицу
 *
 * @param A первая матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  status_code status = MATRIX_ERROR;
  double determinant = 0;
  if (A && A->rows == A->columns && s21_determinant(A, &determinant) == OK &&
      determinant != 0) {
    matrix_t complementsT;
    if (s21_prepare_complements_matrix(A, &complementsT) == OK) {
      if (s21_create_matrix(A->rows, A->columns, result) == OK) {
        s21_apply_inverse_formula(&complementsT, determinant, result);
        status = OK;
      }
      s21_remove_matrix(&complementsT);
    }
  } else if (A && A->rows > 0 && A->columns > 0) {
    status = ARITHMETIC_ERROR;
  }
  return status;
}