#include <stdio.h>

int main(void) {

  int arr[5] = {
    1, 2, 3, 4, 5
  };

  int* end_pt, * start_pt;
  start_pt = arr;
  end_pt = arr + (sizeof(arr) / sizeof(int)) - 1;

  int iter;
  for (iter = 0; iter <= sizeof(arr) / sizeof(int) / 2; iter++) {
    int tmp;
    tmp = *(end_pt - iter);
    *(end_pt - iter) = *(start_pt + iter);
    *(start_pt + iter) = tmp;
  }

  for (iter = 0; iter < sizeof(arr) / sizeof(int); iter++) {
    printf("arr[%d] : %d\n", iter, arr[iter]);
  }

  return 0;
}