#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main11_12(void) {
  char tmp[10];
  int words_count = 0, upper_count = 0, lower_count = 0, punct_count = 0, number_count = 0;

  while (fgets(tmp, 10, stdin)) {
    int i;
    for (i = 0; i < strlen(tmp); i++) {
      if (isdigit(tmp[i])) {
        number_count += 1;
      }
      else if (isupper(tmp[i])) {
        upper_count += 1;
      }
      else if (ispunct(tmp[i])) {
        punct_count += 1;
      }
      else if (islower(tmp[i])) {
        lower_count += 1;
      }
    }
  }
  printf("�ܾ� ���� : , �ҹ��� ���� : %d, �빮�� ���� : %d, �������� ���� : %d, ������ ���� : %d\n", lower_count, upper_count, punct_count, number_count);


  return 0;
}