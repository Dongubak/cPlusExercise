#include <stdio.h>
#pragma warning(disable: 4996)

//인수로 받은 문자를
//두번째 인수값의 열부터 
//세번째 인수값의 열까지 
//출력하는 함수
void chline(char input_char, int first_column, int second_column);

int main9_2(void) {

  char input_char;

  printf("문자를 입력하시오\n");
  scanf("%c", &input_char);
  chline(input_char, 5, 10);

  return 0;
}

void chline(char input_char, int first_column, int second_column) {
  int iter;
  for (iter = 1; iter < first_column; iter++) {
    printf(" ");
  }
  for (iter = first_column; iter <= second_column; iter++) {
    printf("%c", input_char);
  }
}