#include <stdio.h>

void copy_ptr4(double[], double[], int);

int main10_8(void) {
  double arr[7] = {
    1, 2, 3, 4, 5, 6, 7
  };

  double arr2[3];

  copy_ptr4(arr2, arr + 2, 3);

  int outer_iter;

  for (outer_iter = 0; outer_iter < 3; outer_iter++) {
    printf("arr2[%d] : %.1f\n", outer_iter, arr2[outer_iter]);
  }

  return 0;
}

void copy_ptr4(double target_array[], double source_array[], int element_count) {
  int iter;
  for (iter = 0; iter < element_count; iter++) {
    *(target_array + iter) = *(source_array + iter);
  }
  return 0;
}