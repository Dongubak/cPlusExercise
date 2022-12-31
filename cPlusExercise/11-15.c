#include <stdio.h>
#include <string.h>

int sol15(char *number);

int main11_15(void) {

  char* arr[2] = {
    "1234", "12"
  };

  int i;
  for (i = 0; i < 2; i++) {
    sol15(arr[i]);
  }

  return 0;
}

int sol15(char* number) {
    int result = 0;
    int k = 1;
    int j;
    for (j = strlen(number) - 1; j >= 0; j--, k *= 10) {
      result += ((int)number[j] - 48) * k;
    }
    printf("result : %d\n", result);
}