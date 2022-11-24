#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable: 4996)
/*
  수로 이루어진 한 리스트를 읽는다.
  그 수들을 정렬한다.
  평균을 구한다.
  막대 그래프를 표시한다.

  readlist(list, SIZE);
  sort(list, SIZE);
  average(list, SIZE);
  bargraph(list, SIZE);

  return 0;
*/
///header : 전처리기 지시자 사용, 함수프로토타입
///body :~~~
///parameter는 피호출함수(함수의 프로토타입, 선언문)에 있음
///argument는 호출함수에 의해 형식매개변수에 대입되는 특정한 값
///프로토타입에서 선언한 변수이름과 정의문에서 선언한 변수이름이 같을 필요는 없음
///호출함수(main)은 호출문에서 arguments들을 stack에 저장한다
///피호출함수 imax는 두개의 정수값을 읽는데 첫번째는 스택에 놓인 값
/// 두번째는 우연히 두번째 스택에 있었던 값이다.
///               ANSI이후
///parameter의 형과 arguments의 형이 다른경우
///parameter의 형으로 arguments를 데이터형변환 함.
/// 
#define NAME "GIGATHINK, INK."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40

void starbar(void);
///starbar의 signature은 리턴값x 전달인자 x인 함수이다.
///세미콜론이 없으면 프로토타입이나 호출이 아닌 정의로 인식한다.
///void형에서는 return;사용 가능
///parameter의 형과 arguments의 형이 다른경우
///parameter의 형으로 arguments를 데이터형변환 함.
///
int factorial(int n);
void show_info(void) {
  printf("팩토리얼을 계산하는 프로그램입니다\n");
  printf("0-12범위의 한 값을 입력하시오(종료시 q): ");
}

bool is_valid(int input_number) {
  bool is_valid = true;
  if (input_number > 12 || input_number < 0) {
    printf("0-12사이의 값을 입력하시오\n");
    is_valid = false;
  }
  return is_valid;
}

int convert_binary(int input_number) {
  int mod_binary = input_number % 2;
  int div_binary = input_number / 2;
  if (div_binary >= 2) {
    convert_binary(div_binary);
    printf("%d", mod_binary);
  }
  else {
    printf("%d", mod_binary);
  }
}

bool is_valid_1(int input_number) {
  bool is_valid = true;
  if (input_number < 0) {
    is_valid = false;
  }
  return is_valid;
}

int main_play_1(void) {
 
  int input_number;
  while (scanf("%d", &input_number) == 1) {
    if (!is_valid) continue;
    convert_binary(input_number);
  }

  /*show_info();
  while (scanf("%d", &input_number) == 1) {
    if (!is_valid(input_number)) 
      continue;
    printf("%d! = %d\n", input_number, factorial(input_number));
    show_info();
  }*/
  printf("종료!");
  return 0;
}

int factorial(int n) {
  if (n == 1) {
    return 1;
  }
  else if (n == 0){
    return 1;
  }
  else {
    return factorial(n - 1) * n;
  }
}

void starbar(void) {
  int count;
  for (count = 1; count <= WIDTH; count++) {
    putchar('*');
  }
  putchar('\n');
}