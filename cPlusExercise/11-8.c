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
      printf("��� ���ڿ� ����!\n����ڿ� : %s, ����ڿ��� �ּ� : %p, ��� ���ڿ����� ��� : %s\n", find[i], pt, pt);
    }
    else {
      printf("��� ���ڿ��� �������� �ʽ��ϴ�\n");
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