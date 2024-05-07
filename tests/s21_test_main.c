#include "s21_test.h"

int main(void) {
  int error = 0;
  Suite *testing[] = {s21_create_matrix_suite(),
                      s21_remove_matrix_suite(),
                      s21_eq_matrix_suite(),
                      s21_sum_matrix_suite(),
                      s21_sub_matrix_suite(),
                      s21_mult_number_suite(),
                      s21_mult_matrix_suite(),
                      s21_transpose_suite(),
                      s21_calc_complements_suite(),
                      s21_determinant_suite(),
                      s21_inverse_matrix_suite(),

                      NULL};
  for (int i = 0; testing[i] != NULL; i++) {
    SRunner *testing_runner = srunner_create(testing[i]);
    srunner_run_all(testing_runner, CK_NORMAL);
    error += srunner_ntests_failed(testing_runner);
    srunner_free(testing_runner);
  }
  return (error == 0) ? 0 : 1;
}
