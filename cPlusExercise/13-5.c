///* append.c -- appends files to a file */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define BUFSIZE 4096
//#define SLEN 81
//#pragma warning(disable: 4996)
//void append(FILE* source, FILE* dest);
//char* s_gets(char* st, int n);
//
//int main13_5(int argc, char *argv[])
//{
//  if (argc < 3) {
//    printf("전달인자 중 첫 번째 전달인자는 destination fail name이며"
//      "두번째 전달인자부터 source file들의 name이 전달된다");
//    exit(EXIT_FAILURE);
//  }
//
//  FILE* fa, * fs;	// fa for append file, fs for source file
//  int files = 0;  // number of files appended
//  //char file_app[SLEN];  // name of append file
//  //char file_src[SLEN];  // name of source file
//  int ch;
//
//  if ((fa = fopen(argv[1], "a+")) == NULL)
//  {
//    fprintf(stderr, "Can't open %s\n", argv[1]);
//    exit(EXIT_FAILURE);
//  }
//  if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
//  {
//    fputs("Can't create output buffer\n", stderr);
//    exit(EXIT_FAILURE);
//  }
//
//
//  puts("Enter name of first source file (empty line to quit):");
//
//  int i;
//  for (i = 2; i < argc; i++) {
//    if (strcmp(argv[1], argv[i]) == 0)
//      fputs("Can't append file to itself\n", stderr);
//    ///소스파일의 이름과 추가하려는 파일의 이름이 같은 경우 에러
//    else if ((fs = fopen(argv[1], "r")) == NULL)
//      fprintf(stderr, "Can't open %s\n", argv[i]);
//    ///입력한 소스파일이 열리지 않는 경우 에러처리
//    else
//    {
//      if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
//      {
//        fputs("Can't create input buffer\n", stderr);
//        continue;
//      }
//      ///소스파일포인터에 대한 버퍼 설정이 안 된 경우 에러 처리
//      append(fs, fa);
//      ///fa에 fs추가
//      if (ferror(fs) != 0)
//        fprintf(stderr, "Error in reading file %s.\n",
//          argv[i]);
//      if (ferror(fa) != 0)
//        fprintf(stderr, "Error in writing file %s.\n",
//          argv[1]);
//      fclose(fs);
//      files++;
//      printf("File %s appended.\n", argv[i]);
//      puts("Next file (empty line to quit):");
//    }
//  }
//
//
//  printf("Done appending. %d files appended.\n", files);
//  rewind(fa);
//  printf("%s contents:\n", argv[1]);
//  while ((ch = getc(fa)) != EOF)
//    putchar(ch);
//  puts("Done displaying.");
//  fclose(fa);
//
//  return 0;
//}
//
//void append(FILE* source, FILE* dest)
//{
//  size_t bytes;
//  static char temp[BUFSIZE]; // allocate once
//
//  while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
//    fwrite(temp, sizeof(char), bytes, dest);
//}
//
//char* s_gets(char* st, int n)
//{
//  char* ret_val;
//  char* find;
//
//  ret_val = fgets(st, n, stdin);
//  if (ret_val)
//  {
//    find = strchr(st, '\n');   // look for newline
//    if (find)                  // if the address is not NULL,
//      *find = '\0';          // place a null character there
//    else
//      while (getchar() != '\n')
//        continue;
//  }
//  return ret_val;
//}
