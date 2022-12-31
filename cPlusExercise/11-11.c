//#include <stdio.h>
//#include <string.h>
//#pragma warning(disable: 4996)
//
//int gets_11(char arr[][50], int n);
//void menu();
//void menu1(char arr[][50], int n);
//void menu2(char arr[][50], int n);
//void menu3(char arr[][50], int n);
//void menu4(char arr[][50], int n);
//int get_first_word(char* arr_);
//
//int main(void) {
//
//  int input_number;
//  char arr[10][50];
//  printf("문자열 10개를 입력하시오(EOF입력시 입력 종료)\n");
//  int j = gets_11(arr, 10);
//  menu();
//  while (scanf("%d", &input_number) == 1 && input_number != 5) {
//    switch (input_number) {
//    case 1:
//      menu1(arr, j);
//      break;
//    case 2:
//      menu2(arr, j);
//      break;
//    case 3:
//      menu3(arr, j);
//      break;
//    case 4:
//      menu4(arr, j);
//      break;
//    default:
//      NULL;
//    }
//    menu();
//  }
//  printf("프로그램 종료");
//  return 0;
//}
//int get_first_word(char* arr_) {
//  int i = 1;
//  while (!isspace(*arr_++) && *arr_ != '\0') {
//    i++;
//  }
//  return i;
//}
//int gets_11(char arr[][50], int n) {
//  int i = 0;
//  while (i < n && fgets(*(arr + i), 50, stdin)) {
//    i++;
//  }
//  return i;
//}
//void menu1(char arr[][50], int n) {
//  int i;
//  for (i = 0; i < n; i++) {
//    printf("%s", arr[i]);
//  }
//}
//
//void menu() {
//  printf("menu\n");
//  printf("1. 문자열들의 원본리스트를 출력한다.      2. 문자열들을 ascii순서대로 출력.\n");
//  printf("3. 문자열들의 길이가 커지는 순서대로 출력. 4. 문자열의 첫 단어의 길이가 큰 순서대로 출력\n");
//  printf("5. 프로그램 종료\n");
//}
//
//void menu2(char arr[][50], int n) {
//  char* tmp[n];
//  int i, j;
//  for (i = 0; i < n; i++) {
//    tmp[i] = arr[i];
//  }
//  for (i = 0; i < n - 1; i++) {
//    for (j = i + 1; j < n; j++) {
//      if (strcmp(tmp[i], tmp[j]) < 0) {
//        char* tmp_ = tmp[j];
//        tmp[j] = tmp[i];
//        tmp[i] = tmp_;
//      }
//    }
//  }
//  for (i = 0; i < n; i++) {
//    printf("%s", tmp[i]);
//  }
//}
//
//void menu3(char arr[][50], int n) {
//  char* tmp[n];
//  int i, j;
//  for (i = 0; i < n; i++) {
//    tmp[i] = arr[i];
//  }
//  for (i = 0; i < n - 1; i++) {
//    for (j = i + 1; j < n; j++) {
//      if (strlen(tmp[i]) > strlen(tmp[j])) {
//        char* tmp_ = tmp[j];
//        tmp[j] = tmp[i];
//        tmp[i] = tmp_;
//      }
//    }
//  }
//  for (i = 0; i < n; i++) {
//    printf("%s", tmp[i]);
//  }
//}
//
//void menu4(char arr[][50], int n) {
//
//  char* tmp[n];
//  int i, j;
//  for (i = 0; i < n; i++) {
//    tmp[i] = arr[i];
//  }
//  for (i = 0; i < n - 1; i++) {
//    for (j = i + 1; j < n; j++) {
//      if (get_first_word(tmp[i]) > get_first_word(tmp[j])) {
//        char* tmp_ = tmp[j];
//        tmp[j] = tmp[i];
//        tmp[i] = tmp_;
//      }
//    }
//  }
//  for (i = 0; i < n; i++) {
//    printf("%s", tmp[i]);
//  }
//}
