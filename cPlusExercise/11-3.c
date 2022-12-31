#include <stdio.h>
#include <ctype.h>

void sol3(char* pt);

int main11_3(void) {

  char words[10];

  sol3(words, 10);

  printf("%s", words);

  return 0;
}

void sol3(char* pt) {

  char tmp1, tmp2;

  while (isspace(tmp1 = getchar()) || isspace(tmp2 = getchar())) {
    continue;
  }
  gets(pt + 2);
  *(pt) = tmp1;
  *(pt + 1) = tmp2;

  while (getchar() != '\n') {
    continue;
  }

}