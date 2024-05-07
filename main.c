#include "s21_matrix.h"

int main(){
//   matrix_t A;
//   matrix_t B;
//   matrix_t C;
//   s21_create_matrix(1, 1, &A);
//   s21_create_matrix(1, 1, &C);
//   A.matrix[0][0] = 984.1238;
//   C.matrix[0][0] = 984.1238;
// //   printf("\n\n!!!\n\n");
//   int res = s21_calc_complements(&A, &B);
//   int res2 = s21_eq_matrix(&B, &C);
// //   printf("\n\n!!!\n\n");

//     printf("err_code of calc: %d\nres_comp: %d\n", res, res2);

//   s21_print_matrix(&A);
//   s21_print_matrix(&B);
//   s21_print_matrix(&C);

//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   s21_remove_matrix(&C);



  matrix_t A;
  matrix_t B;
  matrix_t C;
  double det = 0.0;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &C);
  s21_initialize_matrix_random(&A, 1);
  s21_initialize_matrix_random(&C, 2);
  s21_determinant(&A, &det);
  printf("calc_err_code: %d\n",s21_inverse_matrix(&A, &B));
  printf("determinant A: %f\n", det);
  printf("comp B vs A: %d\n", s21_eq_matrix(&B, &A));
  printf("comp A vs A: %d\n", s21_eq_matrix(&A, &A));
  printf("comp C vs A: %d\n", s21_eq_matrix(&C, &A));

  s21_print_matrix(&A);
  printf("\n");
  s21_print_matrix(&B);
  printf("\n");
  s21_print_matrix(&C);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}