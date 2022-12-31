#include <stdio.h>
#include <stdbool.h>

bool is_within(char input_char, char* pt_string);

int main11_6(void) {
  char arr[] = "Hold on, there will be better days";
  char chas[] = { 'a', 'b', 'c', 'd', 'e' };
  int i;

  for (i = 0; i < 5; i++) {
    if (is_within(chas[i], arr)) {
      printf("대상 문자열 %s에 %c가 존재합니다\n", arr, chas[i]);
    }
    else {
      printf("대상 문자열 %s에 %c가 존재하지 않습니다\n", arr, chas[i]);
    }
  }

  return 0;
}

bool is_within(char input_char, char* pt_string) {
  bool result = false;
  int i;

  for (i = 0; i < strlen(pt_string); i++) {
    if (*(pt_string + i) == input_char) {
      return true;
    }
  }
  return false;
}