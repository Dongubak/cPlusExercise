#include <stdio.h>
#include <string.h>

char* s_find(const char* string, const char* find);

int main(void) {

  char *string = "Road shimmer wigglin' the vision";
  char *find[3] = { "oa", "wiggle", "vis" };
  int i;

  printf("Ÿ�� ���ڿ� : %s\n", string);

  for (i = 0; i < 3; i++) {

    printf("------------------------------\n");
    printf("����ڿ� : %s\n", find[i]);

    char* pt;

    if (pt = s_find(string, find[i]))
      printf("����ڿ��� �ּ� : %p, ��� ���ڿ����� ��� : %s\n", pt, pt);

    else
      puts("����ڿ��� �������� �ʽ��ϴ�.");
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