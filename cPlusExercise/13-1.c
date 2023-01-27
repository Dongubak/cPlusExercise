/* count.c -- using standard I/O */
#include <stdio.h>
#include <stdlib.h> // exit() prototype
#pragma warning(disable: 4996)

int main13_1(void)
{
  int ch = 0;         // place to store each character as read
  char input_filename[10] = {0};
  FILE* fp = (void *)0;       // "file pointer"
  unsigned long count = 0;
  
  printf("enter the name of file: ");
  scanf("%s", input_filename);

  if ((fp = fopen(input_filename, "r")) == NULL) {
    fprintf(stderr, "cant open file");
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp)) != EOF)
  {
    putc(ch, stdout);  // same as putchar(ch);
    count++;
  }
  fclose(fp);
  printf("File %s has %lu characters\n", input_filename, count);

  return 0;
}