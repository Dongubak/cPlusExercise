//#include <stdio.h>
//#include <string.h>
//
//void sol2(char* pt, int n);
//
//int main(void) {
//
//	int input_number;
//
//	printf("n���� �Է��Ͻÿ� : ");
//	scanf("%d", &input_number);
//
//	char pt[input_number + 1];
//	printf("n���� ���ڸ� �Է��Ͻÿ�");
//	sol2(pt, input_number + 1);
//
//	printf("%s", pt);
//
//
//	return 0;
//}
//
//void sol2(char* pt, int n) {
//	while (getchar() != '\n') {
//		continue;
//	}
//	int iter;
//	for (iter = 0; iter < n; iter++) {
//		char tmp;
//		tmp = getchar();
//		if (isspace(tmp)) {
//			*(pt + iter) = '\0';
//			break;
//		}
//		*(pt + iter) = tmp;
//		if (iter == n - 1) {
//			*(pt + iter) = '\0';
//		}
//	}
//}