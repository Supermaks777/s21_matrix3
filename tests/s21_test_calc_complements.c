#include "s21_test.h"

START_TEST(s21_calc_complements_1) {
  // ошибка: null в указателе на результат
  // memory_counter = 0;
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  // ошибка: вектор в исходной матрице (всего 1 строка), т.е. матрица не
  // квадратная
  // memory_counter = 0;
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(1, 3, &A);
  s21_initialize_matrix(&A, 1, 3);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  // успех: матрица с заданными значениями элементов
  // memory_counter = 0;
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 10,
  eq_matrix.matrix[0][2] = -20;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = -14,
  eq_matrix.matrix[1][2] = 8;
  eq_matrix.matrix[2][0] = -8, eq_matrix.matrix[2][1] = -2,
  eq_matrix.matrix[2][2] = 4;

  int res = s21_calc_complements(&A, &result);

  // s21_print_matrix(&A);
  // printf("\n");
  // s21_print_matrix(&result);
  // printf("\n");
  // s21_print_matrix(&eq_matrix);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *suite = suite_create("s21_calc_complements");
  TCase *tc_core = tcase_create("core_of_calc_complements");
  tcase_add_test(tc_core, s21_calc_complements_1);
  tcase_add_test(tc_core, s21_calc_complements_2);
  tcase_add_test(tc_core, s21_calc_complements_3);
  suite_add_tcase(suite, tc_core);

  return suite;
}