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
  printf("�ڽ��� �⺻�޿� �ش��ϴ� ��ȣ�� �����Ͻÿ�(�������� 5���� �����Ͻÿ�): \n");
  printf("a) �ð��� $%6.2f\t\tb) �ð��� $%6.2f\n", BASE_PAY_ONE, BASE_PAY_TWO);
  printf("c) �ð��� $%6.2f\t\td) �ð��� $%6.2f\n", BASE_PAY_THREE, BASE_PAY_FOUR);
  printf("q) ����\n");
  printf("*********************************************************************\n");
  
  while ((input_char = getchar()) != 'q') {
    printf("�뵿�� �ð��� �Է��Ͻÿ�");
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

    printf("�Ѽҵ� : %.1f, ���� : %.1f, ���ҵ� : %.1f", gross_pay, taxes, net_pay);
    printf("\n");
    printf("*********************************************************************\n");
    printf("�ڽ��� �⺻�޿� �ش��ϴ� ��ȣ�� �����Ͻÿ�(�������� 5���� �����Ͻÿ�): \n");
    printf("a) �ð��� $%6.2f\t\tb) �ð��� $%6.2f\n", BASE_PAY_ONE, BASE_PAY_TWO);
    printf("c) �ð��� $%6.2f\t\td) �ð��� $%6.2f\n", BASE_PAY_THREE, BASE_PAY_FOUR);
    printf("q) ����\n");
    printf("*********************************************************************\n");
    while (getchar() != '\n') {
      continue;
    }
  }


  return 0;
}
