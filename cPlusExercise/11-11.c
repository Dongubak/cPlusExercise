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
//  printf("���ڿ� 10���� �Է��Ͻÿ�(EOF�Է½� �Է� ����)\n");
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
//  printf("���α׷� ����");
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
//  printf("1. ���ڿ����� ��������Ʈ�� ����Ѵ�.      2. ���ڿ����� ascii������� ���.\n");
//  printf("3. ���ڿ����� ���̰� Ŀ���� ������� ���. 4. ���ڿ��� ù �ܾ��� ���̰� ū ������� ���\n");
//  printf("5. ���α׷� ����\n");
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
