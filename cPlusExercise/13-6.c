// reducto.c -- reduces your files by two-thirds!
#include <stdio.h>
#include <stdlib.h>    // for exit()
#include <string.h>    // for strcpy(), strcat()
#pragma warning(disable : 4996)
#define LEN 40

int main13_6() {
  FILE* in, * out;   // declare two FILE pointers
  int ch;
  char name[LEN];// storage for output filename
  char input_filename[LEN] = { 0 };
  int count = 0;
  /*1st argument => source file*/
  // check for command-line arguments

  printf("enter the name of source file : ");
  scanf("%s", input_filename);

  // set up input
  if ((in = fopen(input_filename, "r")) == NULL)
  {
    fprintf(stderr, "I couldn't open the file \"%s\"\n",
      input_filename);
    exit(EXIT_FAILURE);
  }


  // set up output
  strncpy(name, input_filename, LEN - 5); // copy filename
  name[LEN - 5] = '\0';
  strcat(name, ".red");            // append .red


  if ((out = fopen(name, "w")) == NULL)
  {                       // open file for writing
    fprintf(stderr, "Can't create output file.\n");
    exit(3);
  }
  // copy data

  while ((ch = getc(in)) != EOF)
    if (count++ % 3 == 0)
      putc(ch, out);  // print every 3rd char
  // clean up
  if (fclose(in) != 0 || fclose(out) != 0)
    fprintf(stderr, "Error in closing files\n");

  return 0;
}