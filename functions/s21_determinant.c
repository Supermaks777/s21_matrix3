#include "../s21_matrix.h"
/**
 * @brief расчитывает определитель квадратной матрицы
 *
 * @param A исходная матрица (matrix_t)
 * @param result результат (double)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_determinant(matrix_t *A, double *result) {
  int err_code = s21_check_matrix_dimmensions(A);
  if (err_code == OK) err_code = s21_check_matrix_squareness(A);
  if (err_code == OK) {
    if (A->rows == 1) *result = A->matrix[0][0];
    else if (A->rows == 2) *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    else err_code = calculate_determinant(A, result);
  }
  return err_code;
}