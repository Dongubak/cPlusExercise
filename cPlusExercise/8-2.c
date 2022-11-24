#include <stdio.h>

int main2141(void) {
  char input_char;
  int count = 0;
  while ((input_char = getchar()) != EOF) {
    if (input_char >= 0 && input_char < 32 && (input_char != 10 && input_char != 9)) {
      printf("^%c", 64 + input_char);
      count += 1;
    }
    else if (input_char == 10 || input_char == 9) {
      if (input_char == 10) {
        printf("   \\n - %5d", input_char);
        count = 0;
      }
      else {
        printf("   \\t - %5d", input_char);
        count++;
      }
    } else {
      printf("%5c - %5d", input_char, input_char);
      count += 1;
    }
    if (count % 10 == 0) {
      printf("\n");
    }
  }

  return 0;
}