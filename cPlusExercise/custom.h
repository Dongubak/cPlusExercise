#pragma once
#include <stdio.h>
void c_b() {
  while (getchar() != '\n') {
    continue;
  }
}

char * c_gets(char* st, int n) {
  char* input_values;

  input_values = fgets(st, n, stdin);
  if (input_values) { // EOF�˻�
    while (*(st++) != '\n' && *st != '\0') { /// \n�� \0�� ���� ������ st����
      continue;
    }
    *(--st) == '\n' ? *st = '\0' : c_b();
  }

  return input_values;
}

//p1 : ���ڿ��� ������
//return value: ����� ���� ����
int c_put(const char* string) {
  int count = 0;
  while (*string) {
    putchar(*(string++));
    count++;
  }
  return count;
}