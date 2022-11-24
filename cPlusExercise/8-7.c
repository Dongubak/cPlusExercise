#include <stdio.h>
#include <iso646.h>
#pragma warning(disable : 4996)
#define OVER_WORK 1.5
#define BASE_PAY_ONE 8.75
#define BASE_PAY_TWO 9.33
#define BASE_PAY_THREE 10.00
#define BASE_PAY_FOUR 11.20
#define TAX_RATE_TO_300 0.15
#define TAX_RATE_TO_300_TO_450 0.2
#define TAX_RATE_TO_OVER_450 0.25
#define MAX_TAX_TO_300 0.15 * 300
#define MAX_TAX_TO_300_TO_450 0.2 * 150


int main8_7(void) {
  int input_labor_hour;
  float base_pay;
  float gross_pay, taxes, net_pay;
  char input_char;
  printf("*********************************************************************\n");
  printf("자신의 기본급에 해당하는 번호를 선택하시오(끝내려면 5번을 선택하시오): \n");
  printf("a) 시간당 $%6.2f\t\tb) 시간당 $%6.2f\n", BASE_PAY_ONE, BASE_PAY_TWO);
  printf("c) 시간당 $%6.2f\t\td) 시간당 $%6.2f\n", BASE_PAY_THREE, BASE_PAY_FOUR);
  printf("q) 종료\n");
  printf("*********************************************************************\n");
  
  while ((input_char = getchar()) != 'q') {
    printf("노동한 시간을 입력하시오");
    scanf("%d", &input_labor_hour);
    switch (input_char) {
    case 'a':
      base_pay = BASE_PAY_ONE;
      
      break;
    case 'b':
      base_pay = BASE_PAY_TWO;
      
      break;
    case 'c':
      base_pay = BASE_PAY_THREE;
      
      break;
    case 'd':
      base_pay = BASE_PAY_FOUR;
      
    }
    if (input_labor_hour > 40) {
      gross_pay = base_pay * (40 + (input_labor_hour - 40) * OVER_WORK);
    }
    else {
      gross_pay = input_labor_hour * base_pay;
    }
    if (gross_pay <= 300) {
      taxes = gross_pay * TAX_RATE_TO_300;
    }
    else if (gross_pay <= 450) {
      taxes = MAX_TAX_TO_300 + (gross_pay - 300) * TAX_RATE_TO_300_TO_450;
    }
    else {
      taxes = MAX_TAX_TO_300 + MAX_TAX_TO_300_TO_450 + (gross_pay - 450) * TAX_RATE_TO_OVER_450;
    }
    net_pay = gross_pay - taxes;

    printf("총소득 : %.1f, 세금 : %.1f, 순소득 : %.1f", gross_pay, taxes, net_pay);
    printf("\n");
    printf("*********************************************************************\n");
    printf("자신의 기본급에 해당하는 번호를 선택하시오(끝내려면 5번을 선택하시오): \n");
    printf("a) 시간당 $%6.2f\t\tb) 시간당 $%6.2f\n", BASE_PAY_ONE, BASE_PAY_TWO);
    printf("c) 시간당 $%6.2f\t\td) 시간당 $%6.2f\n", BASE_PAY_THREE, BASE_PAY_FOUR);
    printf("q) 종료\n");
    printf("*********************************************************************\n");
    while (getchar() != '\n') {
      continue;
    }
  }


  return 0;
}
