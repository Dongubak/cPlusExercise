#include <stdio.h>

void reverse_array(double*, double*);

int main10_6(void) {
  int iter;
  double arr[5] = {
    1., 2., 3., 4., 5.
  };

  reverse_array(arr, arr + sizeof(arr) / sizeof(double) - 1);

  for (iter = 0; iter < sizeof(arr) / sizeof(double); iter++) {
    printf("arr[%d] : %.1lf\n", iter, arr[iter]);
  }

  return 0;
}

void reverse_array(double*pt, double*end_pt)
{
  do {
    double tmp;
    tmp = *end_pt;
    *end_pt = *pt;
    *pt = tmp;
  } while (++pt < --end_pt);
}