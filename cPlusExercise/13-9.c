/* addaword.c -- uses fprintf(), fscanf(), and rewind() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX 41

int main13_9(void)
{
  FILE* fp;
  char words[MAX];
  char buf[100];
  int count = 0;
  if ((fp = fopen("wordy.txt", "a+")) == NULL)
  {
    fprintf(stdout, "Can't open \"wordy\" file.\n");
    exit(EXIT_FAILURE);
  }

  while (fscanf(fp, "%[^\n]%*c", buf) == 1) {
    count++;
  }
  rewind(fp);           /* go back to beginning of file */

  puts("Enter words to add to the file; press the #");
  puts("key at the beginning of a line to terminate.");
  while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    fprintf(fp, "%d : %s\n", count++, words);

  puts("File contents:");
  rewind(fp);           /* go back to beginning of file */
  while (fscanf(fp, "%[^\n]%*c", words) == 1)
    puts(words);
  puts("Done!");
  if (fclose(fp) != 0)
    fprintf(stderr, "Error closing file\n");

  return 0;
}