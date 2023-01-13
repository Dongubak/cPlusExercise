#include <stdio.h>
#pragma warning(disable :4996)

//두 포인터가 가리키는 값들 중 큰 값을 구하여
//큰 값이 아닌 값을 큰 값으로 변경 함
void largerOf(double *pointerOfX, double *pointerOfy);

int main9_5(void) {

  double firstValue = 3.0;
  double secondValue = 5.0;

  printf("firstValue : %lf\n", firstValue);
  printf("secondValue : %lf\n", secondValue);

  largerOf(&firstValue, &secondValue);

  printf("firstValue : %lf\n", firstValue);
  printf("secondValue : %lf\n", secondValue);

  return 0;
}

void largerOf(double* pointerOfX, double* pointerOfY) {
  if (*pointerOfX > *pointerOfY) {
    *pointerOfY = *pointerOfX;
  }
  else {
    *pointerOfX = *pointerOfY;
  }
}