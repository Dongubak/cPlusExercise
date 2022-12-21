#include <stdio.h>
#include <stdlib.h>

int main10_5(void) {
  ///���� ū ���� ���ϴ� �˰����� �ð����⵵�� O(n) �� ��� ���Ҹ� ������ ��
  double numbers[10];
  int iter;
  double upper_double;
  double lower_double;
  int diff;
  ///diff is the difference between the most biggest number and the most smallest number

  for (iter = 0; iter < sizeof(numbers) / sizeof(double); iter++) {
    numbers[iter] = rand() * 0.1;
  }

  upper_double = numbers[0];
  lower_double = numbers[0];
  for (iter = 0; iter < sizeof(numbers) / sizeof(double); iter++) {
    printf("numbers[%d] : %.1f\n", iter, numbers[iter]);
    upper_double = numbers[iter] >= upper_double ? numbers[iter] : upper_double;
    lower_double = numbers[iter] <= lower_double ? numbers[iter] : lower_double;
  }
  printf("Most biggest number is %.1f\n", upper_double);
  printf("Most smallest number is %.1f\n", lower_double);
  printf("the difference between the most biggest number and the most smallest number : %.1f", upper_double - lower_double);

  return 0;
}