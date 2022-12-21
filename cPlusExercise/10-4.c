#include <stdio.h>
#include <stdlib.h>

int main10_4(void) {
  ///가장 큰 값을 구하는 알고리즘의 시간복잡도는 O(n) 즉 모든 원소를 따져야 함
  double numbers[10];
  int iter; 
  double upper_double;
  int upper_index = 0;
  ///upper_index is the index of the most biggest number.

  for (iter = 0; iter < sizeof(numbers) / sizeof(double); iter++) {
    numbers[iter] = rand() * 0.1;
  }

  upper_double = numbers[0];
  for (iter = 0; iter < sizeof(numbers) / sizeof(double); iter++) {
    printf("numbers[%d] : %.1f\n", iter, numbers[iter]);
    upper_double = numbers[iter] >= upper_double ? numbers[iter] : upper_double;
  }
  printf("Most biggest number is %.1f\n", upper_double);
  for (iter = 0; iter < sizeof(numbers) / sizeof(double); iter++) {
    if (numbers[iter] == upper_double) {
      printf("the index of the most biggest number : %d\n", upper_index);
      break;
    }
    upper_index++;
  }

  return 0;
}