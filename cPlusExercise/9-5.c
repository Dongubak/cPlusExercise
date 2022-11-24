#include <stdio.h>
#pragma warning(disable :4996)

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