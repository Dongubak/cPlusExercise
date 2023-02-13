#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* s_gets_a(char* st, int n);
char* wipe_s(char* string);

int main(void) {
  
  char tmp[10];
  while (s_gets_a(tmp, 10) != EOF) {
    printf("%s", wipe_s(tmp));
  }

  return 0;
}

char* s_gets_a(char* st, int n) {
  char* ret_val;
  int i = 0;

  ret_val = fgets(st, n, stdin);
  if (st[0] == '\n') {
    return EOF;
  }

  if (ret_val) {
    while (st[i] != '\n' && st[i] != '\0')
      i++;
    if (st[i] == '\n')
      st[i] = '\0';
  }

  return ret_val;
}

char* wipe_s(char* string) {
  int i = 0;
  size_t right_i = strlen(string);

  for (int j = 0; j < right_i; j++) {
    if (!isspace(string[j])) {
      string[i++] = string[j];
    }
  }

  string[i] = '\0';
  
  return string;
}