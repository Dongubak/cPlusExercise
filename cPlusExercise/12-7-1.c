#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)

int throw_dice(int count_sides);
int throw_dices(int count_sides, int count_dice);
void get_result(int throw_count, int count_sides, int count_dice);

int main12_7_1(void) {

  int throw_count, count_sides, count_dice;

  printf("던질 횟수를 입력하시오 (끝내려면 q).\n");

  while (scanf("%d", &throw_count) == 1) {
    printf("주사위 면 수와 던질 주사위의 개수를 입려가시오(끝내려면 0).\n");
    scanf("%d %d", &count_sides, &count_dice);
    get_result(throw_count, count_sides, count_dice);
    printf("\n던질 횟수를 입력하시오 (끝내려면 q).\n");
  }



  return 0;
}

int throw_dice(int count_sides) {
  const int random_value = (rand() % count_sides) + 1;
  return random_value;
}

int throw_dices(int count_sides, int count_dice) {
  static int prev_seed = 1;
  srand((unsigned int)prev_seed);
  int sum = 0;
  int i;
  for (i = 0; i < count_dice; i++) {
    sum += throw_dice(count_sides);
  }
  prev_seed += sum;
  return sum;
}

void get_result(int throw_count, int count_sides, int count_dice) {
  int i = 0;
  printf("%d면 주사위 %d개를 %d번 던져 얻은 결과는 다음과 같습니다.\n", count_sides, count_dice, throw_count);
  while (i++ < throw_count) {///throw_count만큼 실행 됨
    printf("%4d", throw_dices(count_sides, count_dice));
  }
}
