#include <stdio.h>
#include <ctype.h>
#include "custom.h"

void s_gets_a(char* st);
char* s_gets_b(void);

int main(void) {

  char *words = s_gets_b();

  free(words);

  return 0;
}

char *s_gets_b(void) {

  char buf[1024], tmp1, tmp2;

  while (isspace(tmp1 = getchar()) || isspace(tmp2 = getchar())) {
    continue;
  }
  buf[0] = tmp1;
  buf[1] = tmp2;

  s_gets_a(buf + 2);

  size_t buf_len = strlen(buf) + 1;

  char* words = (char*)malloc(sizeof(char) * buf_len);
  for (int i = 0; i < buf_len; i++) {
    words[i] = buf[i];
  }

  return words;
}

void s_gets_a(char* st) {

  int i = 0;
  char tmp = 0;

  while ((tmp = getchar()) != EOF && !isspace(tmp)) {
    st[i] = tmp;
    i++;
  }
  st[i] = '\0';

  clear_buf();
}