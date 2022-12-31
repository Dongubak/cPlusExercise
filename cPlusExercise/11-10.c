#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* sol10(char* arr);

int main11_10(void) {
  char tmp[10];
  while (fgets(tmp, 10, stdin) && tmp[0] != '\n') {
    sol10(tmp);
    printf("%s", tmp);
    int i;
    for (i = 0; i < 10; i++) {
      tmp[i] = '\0';
    }
  }

  return 0;
}

char* sol10(char* arr) {
  int i, j;
  int len = strlen(arr) + 1;
  for (i = 0; i < len - 2; i++) {
    for (j = i + 1; j < len - 1; j++) {
      if ((isspace(arr[i]) || arr[i] == '\0') && !isspace(arr[j])) {
        arr[i] = arr[j];
        arr[j] = '\0';
      }
    }
  }
  return arr;
}