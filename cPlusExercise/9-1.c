#include <stdio.h>
#pragma warning(disable: 4996)

//first_input과 second_input을 비교하여
//둘 중 작은 값을 반환하는 함수
double min(double first_input, double second_input);

int main9_1(void) {
  double first_value = 2.1;
  double second_value = 6.3;

  printf("min value : %lf", min(first_value, second_value));

  return 0;
}

double min(double first_input, double second_input) {
  double min_value;
  if (first_input > second_input) {///first_input 이 second_input보다 큰 경우 second_input 반환
    min_value = second_input;
  }
  else if(second_input > first_input){///second_input 이 first_input보다 큰 경우 first_input 반환
    min_value = first_input;
  }
  else {
    min_value = first_input;
    printf("입력한 두 값이 같습니다\n");
  }
  return min_value;
}