#include "../s21_matrix.h"
/**
 * @brief удаляет матрицу
 *
 * @param A матрица для удаления (matrix_t *)
 */
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    for (int row = 0; row < A->rows; row++) {
      free(A->matrix[row]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}