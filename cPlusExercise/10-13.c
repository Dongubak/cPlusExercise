#include <stdio.h>
#pragma warning(disable :4996)
void input_double(int, double(*)[5]);
double get_avg(int, double*);
double get_all_avg(int, double(*)[5]);
double get_max(int, double(*)[5]);
int main10_13(void) {

  double arr[3][5];
  input_double(3, arr);
  int outer_iter, inner_iter;
  for (outer_iter = 0; outer_iter < 3; outer_iter++) {
    for (inner_iter = 0; inner_iter < 5; inner_iter++) {
      printf("arr[%d][%d] : %.1lf  ", outer_iter, inner_iter, *(*(arr + outer_iter) + inner_iter));
    }
    printf("\n");
  }

  printf("\n\n---------row avg----------\n");
  printf("1st row  2nd row   3rd row\n");
  for (outer_iter = 0; outer_iter < 3; outer_iter++) {
    printf("   %.1lf   ", get_avg(5, *(arr + outer_iter)));
  }

  printf("\n\n---------all avg----------\n");
  printf("         avg : %.1lf          ", get_all_avg(3, arr));

  printf("\n\n---------  max  ----------\n");
  printf("         max : %.1lf          ", get_max(3, arr));
  return 0;
}

void input_double(int r, double(*pt)[5]) {
  int outer_iter, inner_iter;

  printf("5개의 double형 값을 3번 입력하시오");
  for (outer_iter = 0; outer_iter < r; outer_iter++) {
    for (inner_iter = 0; inner_iter < 5; inner_iter++) {
      scanf("%lf", (*(pt + outer_iter) + inner_iter));
    }
  }
}

double get_avg(int c, double*pt) {
  double total = 0;
  int iter; 
  for (iter = 0; iter < c; iter++) {
    total += *(pt + iter);
  }
  return total / c;
}

double get_all_avg(int r, double(*pt)[5]) {
  int outer_iter, inner_iter;
  double total = 0;
  for (outer_iter = 0; outer_iter < r; outer_iter++) {
    for (inner_iter = 0; inner_iter < 5; inner_iter++) {
      total += *(*(pt + outer_iter) + inner_iter);
    }
  }
  return total / (r * 5);
}

double get_max(int r, double(*pt)[5]) {
  int outer_iter, inner_iter;
  double tmp_max = pt[0][0];
  for (outer_iter = 0; outer_iter < r; outer_iter++) {
    for (inner_iter = 0; inner_iter < 5; inner_iter++) {
      tmp_max = *(*(pt + outer_iter) + inner_iter) >= tmp_max ? *(*(pt + outer_iter) + inner_iter) : tmp_max;
    }
  }

  return tmp_max;
}