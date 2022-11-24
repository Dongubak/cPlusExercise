#include <stdio.h>
#pragma warning(disable: 4996)
///추측 수 > 생각한 수
///max값을 추측수로, 추측수를 min과 max의 평균으로
///추측 수 < 생각한 수
///min값을 추측수로, 추측수을 min과 max의 평균으로
int main8_5(void) {
  char input_char;
  int tmp_max = 100;
  int tmp_guess = 50;
  int tmp_min = 1;
  printf("1-100사이 생각하라\n");
  printf("생각한 값이 시스템추측값보다 작으면 d, 크면 u, 같으면 c입력하라\n");
  printf("생각한 값이 %d인가?\n", tmp_guess);
  while ((input_char = getchar()) != '\n') {
    if (input_char == 'd') {
      tmp_max = tmp_guess;
      tmp_guess = (tmp_min + tmp_max) / 2;
      printf("생각한 값이 %d인가?\n", tmp_guess);
    }
    else if(input_char == 'u') {
      tmp_min = tmp_guess;
      tmp_guess = (tmp_min + tmp_max) / 2;
      printf("생각한 값이 %d인가?\n", tmp_guess);
    }
    else {
      break;
    }

    while (getchar() != '\n') {
      continue;
    }
  }
  printf("당신이 생각한 수는 %d입니다", tmp_guess);

  return 0;
}