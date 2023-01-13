#include <stdio.h>
#pragma warning(disable: 4996)
///2ab / (a + b)
double getHarmonicMean(double firstValue, double secondValue);

int main9_4(void) {

  printf("%lf", getHarmonicMean(2.0, 3.0));

  return 0;
}

double getHarmonicMean(double firstValue, double secondValue) {
  return (firstValue + secondValue == 0) ? 0 : (2 * firstValue * secondValue) / (firstValue + secondValue);
}