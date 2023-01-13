#include <stdio.h>
#pragma warning(disable: 4996)

void sortValues(double* pointerOfX, double* pointerOfY, double* pointerOfZ);

int main9_6(void) {
  double firstValue = 2.0, secondValue = 3.0, thirdValue = 1.0;
  printf("firstValue : %lf, secondValue : %lf, thirdValue : %lf\n", firstValue, secondValue, thirdValue);

  sortValues(&firstValue, &secondValue, &thirdValue);

  printf("firstValue : %lf, secondValue : %lf, thirdValue : %lf\n", firstValue, secondValue, thirdValue);

  return 0;
}

void sortValues(double* pointerOfX, double* pointerOfY, double* pointerOfZ) {
  double tmp;
  while (!(*pointerOfX < *pointerOfY && *pointerOfY < *pointerOfZ)) {///sort될 때까지 while loop
    if (*pointerOfX > *pointerOfY) {
      tmp = *pointerOfY;
      *pointerOfY = *pointerOfX;
      *pointerOfX = tmp;
    }
    if (*pointerOfY > *pointerOfZ) {
      tmp = *pointerOfZ;
      *pointerOfZ = *pointerOfY;
      *pointerOfY = tmp;
    }
  }
}