#include "s21_test.h"

START_TEST(s21_remove_matrix_1) {
  // успех
  // memory_counter = 0;
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  // ошибка: пустой указатель на результат (отлавливает сегу)
  // memory_counter = 0;
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  // ошибка: некорректная структура матрицы (отлавливает сегу)
  // memory_counter = 0;
  matrix_t A = {};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *suite = suite_create("s21_remove_matrix");
  TCase *tc_core = tcase_create("core_of_remove_matrix");
  tcase_add_test(tc_core, s21_remove_matrix_1);
  tcase_add_test(tc_core, s21_remove_matrix_2);
  tcase_add_test(tc_core, s21_remove_matrix_3);
  suite_add_tcase(suite, tc_core);

  return suite;
}