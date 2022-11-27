#include <stdio.h>
#pragma warning(disable : 4996)
void to_base_n(unsigned long n, int nt);

int main9_10(void) {
  unsigned long number;
  printf("정수 하나를 입력하시오(끝내려면 q):\n");
  while (scanf("%ul", &number) == 1) {
    int nt;
    printf("진수를 입력하시오(끝내려면 q):\n");
    while (scanf("%d", &nt) != 1) {
      printf("올바른 입력이 아닙니다");
    }
    printf("%d진수 표기: ", nt);
    to_base_n(number, nt);
    putchar('\n');
    printf("정수 하나를 입력하시오(끝내려면 q):\n");
  }
  printf("종료!");
  return 0;
}

void to_base_n(unsigned long n, int nt) {
  int r;

  r = n % nt;
  if (n >= nt) {
    to_base_n(n / nt, nt);
  }
  printf("%d", r);
  return;
}