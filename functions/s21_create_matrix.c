#include "../s21_matrix.h"

/**
 * @brief создает матрицу заданного размера (вариант rows+1 массивами)
 * валидация данных: result на существование, размеры матрицы на корректность,
 * выделение памяти под строки
 * @param rows количество строк (int)
 * @param columns количество столбцов (int)
 * @param result ссылка на структура с матрицей
 * @return код ошибки
 * @retval 0 - OK.
 * @retval 1 - INCORRECT_MATRIX.
 * @retval 2 - CALCULATION_ERROR.
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = 0;
  int err_code = (result && rows > 0 && columns > 0) ? OK : INCORRECT_MATRIX;
  if (err_code == OK){
    result->matrix = (double **)malloc(sizeof(double *) * rows);
    result->rows = rows;
    result->columns = columns;
  }
  if (err_code == OK && result->matrix) {
    flag = 1;
    for (int i = 0; err_code == OK & i < rows; i++) {
      result->matrix[i] = (double *)malloc(sizeof(double) * columns);
      if (result->matrix[i] == NULL) err_code = INCORRECT_MATRIX;
    }
  }
  if (err_code != OK && flag) s21_remove_matrix(result);
  return err_code;
}