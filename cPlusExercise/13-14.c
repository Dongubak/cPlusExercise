#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iso646.h>
#include <math.h>
#include <windows.h>
#pragma warning(disable: 4996)

int gen_rand_value(void) {
  return rand() % 10;
}

char convert_int(int number) {
  char returnValue = 0;
  switch (number) {
  case 0:
    returnValue = ' ';
    break;
  case 1:
    returnValue = '.';
    break;
  case 2:
    returnValue = '\'';
    break;
  case 3:
    returnValue = ':';
    break;
  case 4:
    returnValue = '~';
    break;
  case 5:
    returnValue = '*';
    break;
  case 6:
    returnValue = '=';
    break;
  case 7:
    returnValue = '&';
    break;
  case 8:
    returnValue = '%';
    break;
  case 9:
    returnValue = '#';
    break;
  default:
    NULL;
  }
  return returnValue;
}

int main13_14(void) {
  srand((unsigned short)time(0));
  FILE* out = (void*)0, * in = (void*)0;
  int picture[20][30] = { {0} };
  char converted_picture[20][31] = { {0} };
  if ((out = fopen("picture.txt", "w")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }
  int i = 0, j = 0;
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 30; j++) {
      fprintf(out, "%d", gen_rand_value());
    }
    fprintf(out, "\n");
  }
  if (fclose(out) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }

  if ((in = fopen("picture.txt", "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  char input_char = 0;

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 31; j++) {
      if ((input_char = fgetc(in)) == '\n') {
        continue;
      }
      picture[i][j] = input_char - 48;
    }
  }

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 30; j++) {
      converted_picture[i][j] = convert_int(picture[i][j]);
      fprintf(out, "%c", converted_picture[i][j]);
    }
    converted_picture[i][30] = '\0';
  }

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 30; j++) {
      printf("%c", converted_picture[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 30; j++) {
      if (i == 0 or i == 19) {
        if (j == 0 or j == 29) {
          ///1번
          if (i == 0 and j == 0) {
            int avg = (int)round((picture[i][j] + picture[i][j + 1] + picture[i + 1][j]) / 3.);
            picture[i][j] = avg == picture[i][j] ? avg : avg;
          }
          else if (i == 0 and j == 29) {
            int avg = (int)round((picture[i][j] + picture[i][j - 1] + picture[i + 1][j]) / 3.);
            picture[i][j] = avg == picture[i][j] ? avg : avg;
          }
          else if (i == 19 and j == 0) {
            int avg = (int)round((picture[i][j] + picture[i][j + 1] + picture[i - 1][j]) / 3.);
            picture[i][j] = avg == picture[i][j] ? avg : avg;
          }
          else {
            int avg = (int)round((picture[i][j] + picture[i][j - 1] + picture[i - 1][j]) / 3.);
            picture[i][j] = avg == picture[i][j] ? avg : avg;
          }
        } else {
          ///2번
          if (i == 0) {
            int avg = (int)round((picture[i][j] + picture[i][j + 1] + picture[i][j - 1] + picture[i + 1][j]) / 4.);
            picture[i][j] = avg == picture[i][j] ? avg : avg;
          }
          else {
            int avg = (int)round((picture[i][j] + picture[i][j + 1] + picture[i][j - 1] + picture[i - 1][j]) / 4.);
            picture[i][j] = avg == picture[i][j] ? avg : avg;
          }
        }
      } else if (j == 0 or j == 29) {
        ///3번
        if (j == 0) {
          int avg = (int)round((picture[i][j] + picture[i][j + 1] + picture[i - 1][j] + picture[i + 1][j]) / 4.);
          picture[i][j] = avg == picture[i][j] ? avg : avg;
        }
        else {
          int avg = (int)round((picture[i][j] + picture[i][j - 1] + picture[i - 1][j] + picture[i + 1][j]) / 4.);
          picture[i][j] = avg == picture[i][j] ? avg : avg;
        }
      } else {
        ///4번
        int avg = (int)round((picture[i][j] + picture[i][j + 1] + picture[i][j - 1] + picture[i - 1][j] + picture[i + 1][j]) / 5.);
        picture[i][j] = avg == picture[i][j] ? avg : avg;
      }
    }
  }

  if (fclose(in) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }

  if ((out = fopen("converted_picture.txt", "w")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 30; j++) {
      converted_picture[i][j] = convert_int(picture[i][j]);
      fprintf(out, "%c", converted_picture[i][j]);
    }
    converted_picture[i][30] = '\0';
  }

  for (i = 0; i < 20; i++) {
    for (j = 0; j < 30; j++) {
      printf("%c", converted_picture[i][j]);
    }
    printf("\n");
  }

  if (fclose(out) != 0) {
    fprintf(stderr, "cant close file");
    exit(EXIT_FAILURE);
  }
  return 0;
}