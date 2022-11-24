#include <stdio.h>
#pragma warning(disable: 4996)

//두개의 정수를 인수로 받고
//두개의 정수중 작은 정수를 반환하는 함수
//같다면 그 값을 반환한다.
double min(double x, double y);

int main9_1(void) {
  double first_value = 2.1;
  double second_value = 6.3;

  printf("min value : %lf", min(first_value, second_value));

  return 0;
}

double min(double x, double y) {
  double min_value;
  if (x > y) {
    min_value = y;
  }
  else if(y > x){
    min_value = x;
  }
}