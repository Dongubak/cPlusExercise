#include <stdio.h>
#pragma warning(disable :4996)

int main8_1(void) {
  int input_char;
  int count = 0;

  while ((input_char = getchar()) != EOF) {
    count++;
  }
  printf("���� �� : %d", count);

  return 0;
}