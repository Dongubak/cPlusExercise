//#include <stdio.h>
//#include <string.h>
//#include "custom.h"
//#pragma warning(disable :4996)
//#define LIM 4
//#define SIZE 20
//#define STOP "quit"
//int main(void) {
//
//  char arr[LIM][SIZE];
//  char(*pt)[SIZE];
//  pt = arr;
//  printf("%zd , %zd\n", arr, pt);
//  while (pt < arr + LIM && c_gets(*pt, SIZE) && strcmp(*pt++, STOP)) {
//    printf("%zd , %zd\n", arr, pt);
//  }
//
//  char(*i)[SIZE];
//  for (i = arr; i < pt; i++) {
//    printf("%zd", i);
//    printf("%s", *i);
//  }
//    
//  return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include "custom.h"
//#pragma warning(disable :4996)
//#define LIM 5
//#define SIZE 40
//#define STOP "quit"
//int main(void) {
//
//  char arr[LIM][SIZE];
//  int i = 0;
//  char* pt[LIM];
//
//  while (i < LIM && c_gets(arr[i], LIM) && arr[i][0] != '\0') {
//    *(pt + i) = *(arr + i);
//    i++;
//  }
//
//  int m, n;
//  char* tmp;
//  for (m = 0; m < i - 1; m++) {
//    for (n = m + 1; n < i; n++) {
//      if (strcmp(pt[m], pt[n]) > 0) {
//        tmp = pt[n];
//        pt[n] = pt[m];
//        pt[m] = tmp;
//      }
//    }
//  }
//
//  int j;
//  for (j = 0; j < i; j++) {
//    puts(pt[j]);
//  }
//
//  return 0;
//}
//#include <stdio.h>
//#pragma warning(disable: 4996)
//int main(void) {
//
//	char name[4];
//
//	scanf("%4s", name);
//	printf("%s", name);
//
//	return 0;
//}
