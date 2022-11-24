#include <stdio.h>
#pragma warning(disable: 4996)

int main8_6(void) {
  int ch;
  while ((ch = getchar()) == ' ' || ch == '\n') {
    continue;
  }
  
  while (getchar() != '\n')
    continue;

  printf("%c", ch);

  return 0;
}