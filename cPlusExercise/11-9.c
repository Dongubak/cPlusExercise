#include <stdio.h>
#include <string.h>

char* s_reverse(char* string);

int main(void) {

  char strings[3][10] = {"korea", "japan", "china"};
  int i;

  for (i = 0; i < 3; i++) {
    printf("%s\n", s_reverse(strings[i]));
  }

  return 0;
}

char* s_reverse(char* string) {
  int left_i = 0;
  size_t right_i = strlen(string) - 1;///nullÀº strlen(string)
  
  do {
    char tmp = string[left_i];
    string[left_i] = string[right_i];
    string[right_i] = tmp;

  } while (++left_i < --right_i);

  return string;
}