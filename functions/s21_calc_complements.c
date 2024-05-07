#include "../s21_matrix.h"

/**
 * @brief формирует матрицу алгебраических дополнений
 *
 * @param A исходная матрица (matrix_t)
 * @param result результирующая матрица (matrix_t)
 * @return код ошибки (int)
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err_code = s21_check_matrix_dimmensions(A);
  if (err_code == OK) err_code = s21_check_matrix_squareness(A);
  if (err_code == OK) {
    if (A->rows == 1) {
      err_code = s21_create_matrix(1, 1, result);
      if (err_code == OK) result->matrix[0][0] = 1;
    } else {
      err_code = s21_create_matrix(A->rows, A->columns, result);
      if (err_code == OK) err_code = fill_complements(A, result);
      if (err_code != OK) s21_remove_matrix(result);
    }
  }
  return err_code;
}