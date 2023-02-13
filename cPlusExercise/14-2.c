//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#pragma warning(disable: 4996)
//struct month {
//  char fullname_month[10];
//  char name_month[10];
//  int days_count;
//  int number_month;
//};
//
//enum { JAN = 1, FAB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
//
//struct month every_month[12] = {
//  {"January", "JAN", 31, JAN},
//  {"February", "FAB", 28, FAB},
//  {"March", "MAR", 31, MAR},
//  {"April", "APR", 30, APR},
//  {"May", "MAY", 31, MAY},
//  {"June", "JUN", 30, JUN},
//  {"July", "JUL", 31, JUL},
//  {"Agust", "AUG", 31, AUG},
//  {"September", "SEP", 30, SEP},
//  {"October", "OCT", 31, OCT},
//  {"November", "NOV", 30, NOV},
//  {"December", "DEC", 31, DEC}
//};
//
//int get_days(char* full_month_name);
//
//int main(void) {
//
//  char input_month_name[10] = { 0 };
//  printf("enter the string(quit #) : ");
//  while (scanf("%s", input_month_name) == 1 && input_month_name[0] != '#') {
//    printf("%d\n", get_days(input_month_name));
//    printf("enter the string(quit #) : ");
//  }
//  return 0;
//}
//
//int get_days(char* input_month_name) {
//
//  int sum = 0;
//  int i = 0;
//  int input_month = get_index(input_month_name);
//
//  if (input_month == EOF) {
//    return 0;
//  }
//
//  for (i = 0; i < input_month; i++) {
//    sum += every_month[i].days_count;
//  }
//  return sum;
//}
//
//int get_index(char* input_month_name) {
//  int i = 0;
//  for (i = 0; i < 12; i++) {
//    if (strcmp(every_month[i].fullname_month, input_month_name) == 0 || strcmp(every_month[i].name_month, input_month_name) == 0) {
//      return i + 1;
//    }
//  }
//  return EOF;
//}