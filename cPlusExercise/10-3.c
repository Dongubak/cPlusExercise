#include <stdio.h>
#include <stdlib.h>

int main10_3(void) {
  ///���� ū ���� ���ϴ� �˰����� �ð����⵵�� O(n) �� ��� ���Ҹ� ������ ��
  int numbers[10];
  int iter, upper_int;
  ///upper_int is bigger than previous value;

  for (iter = 0; iter < sizeof(numbers) / sizeof(int); iter++) {
    numbers[iter] = rand();
  }

  upper_int = numbers[0];
  for (iter = 0; iter < sizeof(numbers) / sizeof(int); iter++) {
    printf("numbers[%d] : %d\n", iter, numbers[iter]);
    upper_int = numbers[iter] >= upper_int ? numbers[iter] : upper_int;
  }

  printf("Most biggest number is %d\n", upper_int);

  return 0;
}