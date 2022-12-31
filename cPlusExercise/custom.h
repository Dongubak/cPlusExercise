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
  if (input_values) { // EOF검사
    while (*(st++) != '\n' && *st != '\0') { /// \n과 \0이 나올 때까지 st증가
      continue;
    }
    *(--st) == '\n' ? *st = '\0' : c_b();
  }

  return input_values;
}

//p1 : 문자열의 포인터
//return value: 출력한 문자 개수
int c_put(const char* string) {
  int count = 0;
  while (*string) {
    putchar(*(string++));
    count++;
  }
  return count;
}