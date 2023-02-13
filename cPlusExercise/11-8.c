#include <stdio.h>
#include <string.h>

char* s_find(const char* string, const char* find);

int main(void) {

  char *string = "Road shimmer wigglin' the vision";
  char *find[3] = { "oa", "wiggle", "vis" };
  int i;

  printf("타겟 문자열 : %s\n", string);

  for (i = 0; i < 3; i++) {

    printf("------------------------------\n");
    printf("대상문자열 : %s\n", find[i]);

    char* pt;

    if (pt = s_find(string, find[i]))
      printf("대상문자열의 주소 : %p, 대상 문자열부터 출력 : %s\n", pt, pt);

    else
      puts("대상문자열이 존재하지 않습니다.");
  }

  return 0;
}

char* s_find(const char* string, const char* find) {
  int i = 0;

  while (string[i] != '\0' && 
    strncmp(string + i, find, strlen(find))) {
    i++;
  }
  return string[i] == '\0' ? (void*)0 : string + i;
}