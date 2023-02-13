/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
char* s_gets(char* st, int n);
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100              /* maximum number of books  */

struct book {                     /* set up book template     */
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};

typedef struct book BOOK;

int main14_3(void)
{
  BOOK library[MAXBKS]; /* array of book structures */
  int count = 0;
  int index;

  printf("Please enter the book title.\n");
  printf("Press [enter] at the start of a line to stop.\n");
  while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
    && library[count].title[0] != '\0')
  {
    printf("Now enter the author.\n");
    s_gets(library[count].author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library[count++].value);
    while (getchar() != '\n')
      continue;          /* clear input line         */
    if (count < MAXBKS)
      printf("Enter the next title.\n");
  }
  printf("입력된 순서\n");

  if (count > 0)
  {
    printf("Here is the list of your books:\n");
    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", library[index].title,
        library[index].author, library[index].value);
  }
  else
    printf("No books? Too bad.\n");
  printf("타이틀의 알파벳 순서\n");

  if (count > 0)
  {
    BOOK** fp = (BOOK**)malloc(sizeof(BOOK*) * count);
    printf("count : %d\n", count);
    int i, j;
    for (i = 0; i < count; i++) {
      fp[i] = &library[i];
    }
    /*for (i = 0; i < count; i++) {
      printf("%s", (*fp[i]).title);
    }*/
    for (i = 0; i < count - 1; i++) {
      for (j = i + 1; j < count; j++) {
        BOOK* tmp;
        int cmpResult = strcmp((*fp[i]).title, (*fp[j]).title);
        switch (cmpResult) {
          case 1:
            tmp = fp[i];
            fp[i] = fp[j];
            fp[j] = tmp;
            break;
          default:
            NULL;
        }
      }
    }
    

    printf("Here is the list of your books:\n");

    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", (*fp[index]).title,
        (*fp[index]).author, (*fp[index]).value);

    free(fp);
  }
  else
    printf("No books? Too bad.\n");

  printf("가격이 높은 순서\n");

  if (count > 0)
  {
    BOOK** fp = (BOOK**)malloc(sizeof(BOOK*) * count);
    printf("count : %d\n", count);
    int i, j;
    for (i = 0; i < count; i++) {
      fp[i] = &library[i];
    }
    /*for (i = 0; i < count; i++) {
      printf("%s", (*fp[i]).title);
    }*/
    for (i = 0; i < count - 1; i++) {
      for (j = i + 1; j < count; j++) {
        BOOK* tmp;
        int cmpResult = (*fp[i]).value > (*fp[j]).value ? 1 : 0;
        switch (cmpResult) {
        case 1:
          tmp = fp[i];
          fp[i] = fp[j];
          fp[j] = tmp;
          break;
        default:
          NULL;
        }
      }
    }


    printf("Here is the list of your books:\n");

    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", (*fp[index]).title,
        (*fp[index]).author, (*fp[index]).value);

    free(fp);
  }
  else
    printf("No books? Too bad.\n");

  return 0;
}

char* s_gets(char* st, int n)
{
  char* ret_val;
  char* find;

  ret_val = fgets(st, n, stdin);
  if (ret_val) 
  {
    find = strchr(st, '\n');   // look for newline
    if (find)                  // if the address is not NULL,
      *find = '\0';          // place a null character there
    else
      while (getchar() != '\n')
        continue;          // dispose of rest of line
  }
  return ret_val;
}