//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning(disable: 4996)
//
//int main(void) {
// 
//
//  FILE* in = (void*)0;
//  char input_string[20];
//  if ((in = fopen("wordy.txt", "r")) == NULL) {
//    fprintf(stderr, "file cant open");
//    exit(EXIT_FAILURE);
//  }
//
//  while (fscanf(in,"%s", input_string) == 1) {
//    printf("%s", input_string);
//  }
//
//  if (fclose(in) != 0) {
//    fprintf(stderr, "file cant close");
//    exit(EXIT_FAILURE);
//  }
// 
//  return 0;
//}