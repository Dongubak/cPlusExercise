#include <stdio.h>
#pragma warning(disable : 4996)

double power(double n, int p);

int main9_8(void) {
  double x, xpow;
  int exp;

  printf("어떤 수와, 원하는 정수 거듭제곱수를");
  printf(" 입력하시오.\n끝내려면 q를");
  printf(" 입력하시오\n");
  while (scanf("%lf%d", &x, &exp) == 2) {
    xpow = power(x, exp);
    if (xpow == EOF) {
      printf("%.3g의 %d승은 %d입니다.\n", x, exp, 1);
      printf("0의 0승은 정의되지 않았고 1의 값을 사용중입니다.\n");
      printf("두 수를 입력하시오. 끝내려면 q를 입력하시오.\n");
      continue;
    }
    else {
      printf("%.3g의 %d승은 %.5g입니다.\n", x, exp, xpow);
      printf("두 수를 입력하시오. 끝내려면 q를 입력하시오.\n");
    }
  }
  printf("거듭제곱 구하기가 재미 있었나요? --안녕!\n");

  return 0;
}

double power(double n, int p) {
  double pow = 1;
  int absP = p < 0 ? -p : p;
  int i;

  if (n == 0 && p == 0) {
    return EOF;
  }
  else if (p == 0){
    return 1;
  }
  else if (n == 0) { 
    return 0;
  }
  else {
    for (i = 1; i <= absP; i++) {
      pow *= p < 0 ? 1. / n : n;
    }
  }


  return pow;
}