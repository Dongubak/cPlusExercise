//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define COL 20
//#define ROW 30
//#pragma warning(disable: 4996)
//
//int gen_rand_value(void) {
//  return rand() % 10;
//}
//
//char convert_int(int number) {
//  char returnValue = 0;
//  switch (number) {
//  case 0:
//    returnValue = ' ';
//    break;
//  case 1:
//    returnValue = '.';
//    break;
//  case 2:
//    returnValue = '\'';
//    break;
//  case 3:
//    returnValue = ':';
//    break;
//  case 4:
//    returnValue = '~';
//    break;
//  case 5:
//    returnValue = '*';
//    break;
//  case 6:
//    returnValue = '=';
//    break;
//  case 7:
//    returnValue = '&';
//    break;
//  case 8:
//    returnValue = '%';
//    break;
//  case 9:
//    returnValue = '#';
//    break;
//  default:
//    NULL;
//  }
//  return returnValue;
//}
//
//int main(void) {
//  srand((unsigned short)time(0));
//  int row = 0, col = 0;
//  FILE* out = (void*)0, * in = (void*)0;
//
//  printf("enter col and row : ");
//  scanf("%d %d", &col, &row);
//
//  int picture[row][col];
//  char converted_picture[row][col + 1];
//
//  if ((out = fopen("picture.txt", "w")) == NULL) {
//    fprintf(stderr, "cant open file");
//    exit(EXIT_FAILURE);
//  }
//
//  int i = 0, j = 0;
//  for (i = 0; i < row; i++) {
//    for (j = 0; j < col; j++) {
//      fprintf(out, "%d", gen_rand_value());
//    }
//    fprintf(out, "\n");
//  }
//  if (fclose(out) != 0) {
//    fprintf(stderr, "cant close file");
//    exit(EXIT_FAILURE);
//  }
//
//  if ((in = fopen("picture.txt", "r")) == NULL) {
//    fprintf(stderr, "cant open file");
//    exit(EXIT_FAILURE);
//  }
//
//  char input_char = 0;
//
//  for (i = 0; i < row; i++) {
//    for (j = 0; j < col + 1; j++) {
//      if ((input_char = fgetc(in)) == '\n') {
//        continue;
//      }
//      picture[i][j] = input_char - 48;
//    }
//  }
//
//  for (i = 0; i < row; i++) {
//    for (j = 0; j < col; j++) {
//      printf("%d", picture[i][j]);
//    }
//    printf("\n");
//  }
//
//  if (fclose(in) != 0) {
//    fprintf(stderr, "cant close file");
//    exit(EXIT_FAILURE);
//  }
//
//  if ((out = fopen("converted_picture.txt", "w")) == NULL) {
//    fprintf(stderr, "cant open file");
//    exit(EXIT_FAILURE);
//  }
//
//  for (i = 0; i < row; i++) {
//    for (j = 0; j < col; j++) {
//      converted_picture[i][j] = convert_int(picture[i][j]);
//      fprintf(out, "%c", converted_picture[i][j]);
//    }
//    converted_picture[i][row] = '\0';
//  }
//
//  for (i = 0; i < row; i++) {
//    for (j = 0; j < col; j++) {
//      printf("%c", converted_picture[i][j]);
//    }
//    printf("\n");
//  }
//
//  if (fclose(out) != 0) {
//    fprintf(stderr, "cant close file");
//    exit(EXIT_FAILURE);
//  }
//  return 0;
//}