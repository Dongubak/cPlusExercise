#include <stdio.h>

void copy_ptr3(double[], double[], int);

int main10_7(void) {
  double arr[2][2] = {
    {1.2, 2.2},
    {3.4, 5.5},
  };

  double arr2[2][2];

  int outer_iter, inner_iter;
  for (outer_iter = 0; outer_iter < 2; outer_iter++) {
      copy_ptr3(*(arr2 + outer_iter), *(arr + outer_iter), 2);
  }

  for (outer_iter = 0; outer_iter < 2; outer_iter++) {
    for (inner_iter = 0; inner_iter < 2; inner_iter++) {
      printf("arr2[%d][%d] : %.1f\n", outer_iter, inner_iter, arr2[outer_iter][inner_iter]);
    }
  }

  return 0;
}

void copy_ptr3(double target_array[], double source_array[], int element_count) {
  int iter;
  for (iter = 0; iter < element_count; iter++) {
    *(target_array + iter) = *(source_array + iter);
  }
  return 0;
}