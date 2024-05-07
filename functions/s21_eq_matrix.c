#include "../s21_matrix.h"

/**
 * @brief сравнивает две матрицы
 *
 * @param A первая матрица (matrix_t)
 * @param B вторая матрица (matrix_t)
 * @param result результат (double)
 * @return результат сравнения (int)
 * @retval 0 - FAILURE.
 * @retval 1 - SUCCESS.
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (!A || !B || (A->rows != B->rows) || (A->columns != B->columns)) {
    result = FAILURE;
  } else {
    for (int i = 0; result != FAILURE && i < A->rows; i++) {
      for (int j = 0; result != FAILURE && j < A->columns; j++) {
        result =
            fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-07 ? SUCCESS : FAILURE;
      }
    }
  }
  return result;
}
