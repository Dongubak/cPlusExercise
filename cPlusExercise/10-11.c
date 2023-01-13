#include <stdio.h>

void display_arr1(int , int(*)[5]);
void mul_arr1(int, int(*)[5]);

int main10_11(void) {
  int arr[3][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15}
  };

  display_arr1(5, arr);
  mul_arr1(5, arr);
  display_arr1(5, arr);

  return 0;
}

void display_arr1(int row, int(*pt)[5]) {
  int outer_iter, inner_iter;
  for (inner_iter= 0; inner_iter < row; inner_iter++) {
    for (outer_iter = 0; outer_iter < 3; outer_iter++) {
      printf("arr[%d][%d] : %3d    ", outer_iter, inner_iter, *(*(pt + outer_iter) + inner_iter));
    }
    printf("\n");
  }
}

void mul_arr1(int row, int(*pt)[5]) {
  int outer_iter, inner_iter;
  for (outer_iter = 0; outer_iter < 3; outer_iter++) {
    for (inner_iter = 0; inner_iter < row; inner_iter++) {
      *(*(pt + outer_iter) + inner_iter) = *(*(pt + outer_iter) + inner_iter) * 2;
    }
  }
}