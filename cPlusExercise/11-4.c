#include <stdio.h>
#include <ctype.h>

void sol4(char* pt);

int main11_4(void) {

  char words[10];

  sol4(words, 10);

  printf("%s", words);

  return 0;
}

void sol4(char* pt) {

  char tmp1, tmp2;

  while (isspace(tmp1 = getchar()) || isspace(tmp2 = getchar())) {
    continue;
  }
  fgets(pt + 2, 7, stdin);
  *(pt) = tmp1;
  *(pt + 1) = tmp2;
  while (!isspace(*(pt++))) {
    continue;
  }
  *(--pt) = '\0';


  while (getchar() != '\n') {
    continue;
  }

}