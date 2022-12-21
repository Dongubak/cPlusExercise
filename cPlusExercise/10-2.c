#include <stdio.h>

void copy_arr(double[], double[], int);
void copy_ptr(double[], double[], int);
void copy_ptr2(double[], double[], double[]);
void display_array(double[], int, int);
int main10_2(void) {
  double source[5] = {
    1.1, 2.2, 3.3, 4.4, 5.5
  };

  double target1[5];
  double target2[5];
  double target3[5];

  copy_arr(target1, source, 5);
  copy_ptr(target2, source, 5);
  copy_ptr2(target3, source, source + 5);
  char *name[3] = {
    "target-1", "target-2", "target-3"
  };
  display_array(target1, 3, 5);
  
  return 0;
}

void copy_arr(double target_array[], double source_array[], int element_count) {
  int iter;
  for (iter = 0; iter < element_count; iter++) {
    target_array[iter] = source_array[iter];
  }
  return 0;
}

void copy_ptr(double target_array[], double source_array[], int element_count) {
  int iter;
  for (iter = 0; iter < element_count; iter++) {
    *(target_array + iter) = *(source_array + iter);
  }
  return 0;
}

void copy_ptr2(double target_array[], double source_array[], double source_array_last_element_pointer[]) {
  double* iter;
  for (iter = source_array; iter <= source_array_last_element_pointer; iter++) {
    *(target_array++) = *iter;
  }
}

void display_array(double target1_pointer[], int array_count, int element_count) {
  int outer_iter, inner_iter;
  for (outer_iter = 0; outer_iter < array_count; outer_iter++) {
    printf("-----target%d-----\n", outer_iter + 1);
    for (inner_iter = 0; inner_iter < element_count; inner_iter++) {
      printf("target%d[%d] : %.1f\n", outer_iter + 1, inner_iter, *(target1_pointer + (outer_iter * 8) + inner_iter));
    }
  }
}