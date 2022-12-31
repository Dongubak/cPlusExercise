#include <stdio.h>
#include <string.h>

char* string_in(char* arr, char* find);

int main11_8(void) {

  char arr[] = "Road shimmer wigglin' the vision";
  char *find[3] = { "oa", "wiggle", "vis" };
  int i;

  for (i = 0; i < 3; i++) {
    char* pt;
    if (pt = string_in(arr, find[i])) {
      printf("대상 문자열 존재!\n대상문자열 : %s, 대상문자열의 주소 : %p, 대상 문자열부터 출력 : %s\n", find[i], pt, pt);
    }
    else {
      printf("대상 문자열이 존재하지 않습니다\n");
    }
  }

  return 0;
}

char* string_in(char* arr, char* find) {
  while (*arr != '\0' && strncmp(arr, find, strlen(find))) {
    arr++;
  }
  if (*arr != '\0') {
    return arr;
  } else {
    return NULL;
  }
}