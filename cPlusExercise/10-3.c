#include <stdio.h>
#include <stdlib.h>

int main10_3(void) {
  ///가장 큰 값을 구하는 알고리즘의 시간복잡도는 O(n) 즉 모든 원소를 따져야 함
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