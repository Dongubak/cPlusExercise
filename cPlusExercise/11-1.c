//#include <stdio.h>
//
//void sol1(char* pt, int n);
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
//	sol1(pt, input_number + 1);
//
//	printf("%s", pt);
//
//
//	return 0;
//}
//
//void sol1(char* pt, int n) {
//	while (getchar() != '\n') {
//		continue;
//	}
//	int iter;
//	for (iter = 0; iter < n; iter++) {
//		*(pt + iter) = getchar();
//		if (iter == n - 1) {
//			*(pt + iter) = '\0';
//		}
//	}
//}