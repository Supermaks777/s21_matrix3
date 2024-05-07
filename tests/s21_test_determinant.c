#include "s21_test.h"

START_TEST(s21_determinant_1) {
  // ошибка: некорректная матрица
  // memory_counter = 0;
  matrix_t A = {};
  double det = 0;
  ck_assert_int_eq(s21_determinant(&A, &det), INCORRECT_MATRIX);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_determinant_2) {
  // ошибка: не квадратная матрица
  // memory_counter = 0;
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 2, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_determinant_3) {
  // успех: заданные значения
  // memory_counter = 0;
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_determinant_4) {
  // успех: матрица 2х2
  // memory_counter = 0;
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(2, 2, &A);
  s21_initialize_matrix(&A, 3, 3);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, -18);
  s21_remove_matrix(&A);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_determinant_5) {
  // успех: матрица 1х1
  // memory_counter = 0;
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *suite = suite_create("s21_determinant");
  TCase *tc_core = tcase_create("core_of_determinant");
  tcase_add_test(tc_core, s21_determinant_1);
  tcase_add_test(tc_core, s21_determinant_2);
  tcase_add_test(tc_core, s21_determinant_3);
  tcase_add_test(tc_core, s21_determinant_4);
  tcase_add_test(tc_core, s21_determinant_5);
  suite_add_tcase(suite, tc_core);

  return suite;
}