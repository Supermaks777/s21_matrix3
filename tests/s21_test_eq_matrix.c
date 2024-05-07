#include "s21_test.h"

START_TEST(s21_eq_matrix_1) {
  // успех: корректные инициализированные матрицы
  // memory_counter = 0;
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 21, 21);
  s21_initialize_matrix(&B, 21, 21);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  // успех: неинициализированные матрицы
  // memory_counter = 0;
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  // успех: отклонение значения элемента меньше порогового значения
  // memory_counter = 0;
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 1, 0.000000001);
  s21_initialize_matrix(&B, 1, 0.000000002);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  // ошибка: разная размерность
  // memory_counter = 0;
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(3, 4, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  // ошибка: некорректная структура матрицы
  // memory_counter = 0;
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  // ошибка: разные значения
  // memory_counter = 0;
  matrix_t A = {};
  matrix_t B = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 21, 1);
  s21_initialize_matrix(&B, 42, 1);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // printf("memory_counter: %d\n", memory_counter);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *suite = suite_create("s21_eq_matrix");
  TCase *tc_core = tcase_create("core_of_eq_matrix");
  tcase_add_test(tc_core, s21_eq_matrix_1);
  tcase_add_test(tc_core, s21_eq_matrix_2);
  tcase_add_test(tc_core, s21_eq_matrix_3);
  tcase_add_test(tc_core, s21_eq_matrix_4);
  tcase_add_test(tc_core, s21_eq_matrix_5);
  tcase_add_test(tc_core, s21_eq_matrix_6);
  suite_add_tcase(suite, tc_core);

  return suite;
}