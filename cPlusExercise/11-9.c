#include <stdio.h>
#include <string.h>

char* sol9(char* arr);

int main11_9(void) {

  char arr[3][10] = { "korean", "japan", "china" };
  int i;

  for (i = 0; i < 3; i++) {
    sol9(arr[i]);
    printf("%s\n", arr[i]);
  }

  return 0;
}

char* sol9(char* arr) {
  int i = 0;
  int j = strlen(arr);
  while (i <= (int)(strlen(arr) / 2)) {
    char tmp;
    tmp = arr[strlen(arr) - i - 1];
    arr[strlen(arr) - i - 1] = arr[i];
    arr[i] = tmp;
    i++;
  }

  return arr;
}