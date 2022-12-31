//#include <stdio.h>
//#include <stdbool.h>
//#pragma warning(disable: 4996)
//
//void menu(void);
//char get_operator(void);
//float get_number(char input_char, bool is_second_value);
//void display_result(char input_char, float first_value, float second_value);
//void clear(void);
//
//int main8_8(void) {
//  char input_char;
//  while ((input_char = get_operator()) != 'q') {
//    float first_input, second_input;
//    first_input = get_number(input_char, false);
//    second_input = get_number(input_char, true);
//    display_result(input_char, first_input, second_input);
//    clear();
//  }
//  return 0;
//}
//
//void menu(void) {
//  printf("���ϴ� ���꿡 �ش��ϴ� ���ڸ� �����Ͻÿ�(�������� q):\n");
//  printf("a. add(����)      s. subtract(����)\n");
//  printf("m. multiply(����) d. divide(������)\n");
//  printf("q. quit(����)\n");
//}
//
//char get_operator(void) {
//  char input_char;
//  menu();
//  while ((input_char = getchar()) != '\n') {
//    if (input_char == 'a' || input_char == 's' || input_char == 'm' || input_char == 'd' || input_char == 'q') {
//      clear();
//      return input_char;
//    }
//    else {
//      printf("a, s, m, d, q�� �Է� �����մϴ�.\n");
//      clear();
//    }
//    menu();
//  }
//}
//
//float get_number(char input_char, bool is_second_value) {
//  float input_value;
//  is_second_value ? printf("�ι�° ���� �Է��Ͻÿ� : ") : printf("ù��° ���� �Է��Ͻÿ� : ");
//  while (scanf("%f", &input_value) != 1 || (input_char == 'd' && is_second_value && input_value == 0)) {
//      printf("�ùٸ� �Է��� �ƴմϴ�.\n");
//      is_second_value ? printf("�ι�° ���� �Է��Ͻÿ� : ") : printf("ù��° ���� �Է��Ͻÿ� : ");
//      clear();
//  }
//  return input_value;
//}
//
//void clear(void) {
//  while (getchar() != '\n') {
//    continue;
//  }
//}
//
//void display_result(char input_char, float first_value, float second_value) {
//  switch (input_char) {
//  case 'a':
//    printf("%.2f + %.2f = %.2f\n", first_value, second_value, first_value + second_value);
//    break;
//  case 's':
//    printf("%.2f - %.2f = %.2f\n", first_value, second_value, first_value - second_value);
//    break;
//  case 'm':
//    printf("%.2f * %.2f = %.2f\n", first_value, second_value, first_value * second_value);
//    break;
//  case 'd':
//    printf("%.2f / %.2f = %.2f\n", first_value, second_value, first_value / second_value);
//    break;
//  }
//}