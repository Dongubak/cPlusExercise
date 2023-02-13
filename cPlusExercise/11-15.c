#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int c_atoi(char *number);

int main(void) {

  char* arr[2] = {
    "1234", "12"
  };

  int i;
  for (i = 0; i < 2; i++) {
    printf("%d\n", c_atoi(arr[i]));
  }

  return 0;
}

int c_atoi(char* number) {

  int result = 0;
  int k = 1;
  int j;
  for (j = strlen(number) - 1; j >= 0; j--, k *= 10) {

    if (isdigit(!number[j]))
      return 0;
    
    result += ((int)number[j] - 48) * k;
  }
  return result;
}