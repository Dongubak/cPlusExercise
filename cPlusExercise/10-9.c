//VLA는 vs에서 실행이 안됨
//#include <stdio.h>
//
//void copy_9(int n, int m, double target[n][m], double source[n][m]);
//void display_arr(int n, int m, double(*target)[m]);
//
//int main(void) {
//	int n = 5, m = 3;
//	double arr[5][3] = { {1.2, 2.2, 3.2}, {4.1, 5.1, 2.1}, {6.1, 7.4, 6.2}, {8.1, 2.2, 4.8}, {6.3, 4.2, 6.2} };
//	double arr1[5][3];
//
//	copy_9(n, m, arr1, arr);
//	display_arr(n, m, arr1);
//
//	return 0;
//}
//void copy_9(int n, int m, double(*target)[m], double(*source)[m]) {
//	int outer_iter, inner_iter;
//
//	for (outer_iter = 0; outer_iter < n; outer_iter++) {
//		for (inner_iter = 0; inner_iter < m; inner_iter++) {
//			*(*(target + outer_iter) + inner_iter) = *(*(source + outer_iter) + inner_iter);
//		}
//	}
//}
//
//void display_arr(int n, int m, double(*target)[m]) {
//	int outer_iter, inner_iter;
//	for (outer_iter = 0; outer_iter < n; outer_iter++) {
//		for (inner_iter = 0; inner_iter < m; inner_iter++) {
//			printf("arr1[%d][%d] : %.1f\n", outer_iter, inner_iter, *(*(target + outer_iter) + inner_iter));
//		}
//	}
//}