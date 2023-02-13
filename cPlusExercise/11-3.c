#include <stdio.h>
#include <ctype.h>
#include "custom.h"

void s_gets_a(char* st, int n);
void s_gets_b(char* pt, int n);

int main(void) {

  char words[10];

  s_gets_b(words, 10);

  return 0;
}

void s_gets_b(char* pt, int n) {

  char tmp1, tmp2;

  while (isspace(tmp1 = getchar()) || isspace(tmp2 = getchar())) {
    continue;
  }
  pt[0] = tmp1;
  pt[1] = tmp2;
  s_gets_a(pt + 2, n - 2);

}

void s_gets_a(char* st, int n) {

  int i = 0;
  char tmp = 0;

  while (i < n && (tmp = getchar()) != EOF && !isspace(tmp)) {
    st[i] = tmp;
    i++;
  }
  st[i] = '\0';

  clear_buf();
}