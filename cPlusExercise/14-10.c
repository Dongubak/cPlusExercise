#include <stdio.h>
#pragma warning(disable: 4996)

void sumfunction(int (*function_pointer)(int, int), int first_value, int second_value);

int mer(int first_value, int second_value) {
  return first_value + second_value;
}

int sub(int first_value, int second_value) {
  return first_value - second_value;
}

int mul(int first_value, int second_value) {
  return first_value * second_value;
}

int div(int first_value, int second_value) {
  return first_value / second_value;
}

void clear_buf(void) {
  while (getchar() != '\n') {
    continue;
  }
}

int main(void) {

  int first_value = 10, second_value = 20;
  int (*function_arr[4])() = { mer, sub, mul, div };
  char menu[4] = { 'a', 'b', 'c', 'd' };

  char input_char = 0;

  while (1) {
    printf("firstvalue: %d, second_value: %d\n", first_value, second_value);
    printf("a: 합, b: 차, c: 곱, d: 나, (quit : q) : \n");
    printf("입력 : ");
    scanf("%c", &input_char);
    clear_buf();

    if (input_char == 'q') {
      break;
    }

    int i = 0;
    for (i = 0; i < 4; i++) {
      if (menu[i] == input_char) {
        sumfunction(function_arr[i], first_value, second_value);
      }
    }
  }

  return 0;
}

void sumfunction(int(*function_pointer)(int, int), int first_value, int second_value)
{
  printf("%d\n", (*function_pointer)(first_value, second_value));
}
