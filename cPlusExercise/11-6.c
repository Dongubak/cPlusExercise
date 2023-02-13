#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_within(char *string, char find);

int main(void) {

  char *string = "Hold on, there will be better days";
  printf("대상 문자열 : %s\n", string);

  char chas[] = { 'a', 'b', 'c', 'd', 'e' };
  int i = 0;

  for (i = 0; i < 5; i++) {
    printf("----------------------------\n");

    if (is_within(string, chas[i]))
      printf("%c가 존재합니다\n", chas[i]);

    else 
      printf("%c가 존재하지 않습니다\n", chas[i]);
    
  }

  return 0;
}

bool is_within(char *string, char find) {
  bool result = false;
  int i;

  for (i = 0; i < strlen(string); i++) {
    if (string[i] == find)
      return true;
  }
  return false;
}