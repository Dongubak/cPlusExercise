#include <stdio.h>
#include <ctype.h>
#pragma warning(disable: 4996)

int main8_3(void) {
  int input_char;
  int upper_count = 0, lower_count = 0;
  while ((input_char = getchar()) != EOF) {
    isupper(input_char) ? ++upper_count : ++lower_count;
  }
  printf("대문자의 개수 : %d\n", upper_count);
  printf("소문자의 개수 : %d\n", lower_count);

  return 0;
}