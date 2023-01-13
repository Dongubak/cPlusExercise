//#include <stdio.h>
//
//void copy_9(int n, int m, double target[n][m], const double source[n][m]);
//void display_arr(int n, int m, double(*target)[m]);
//
//int main10_9(void) {
//	int n = 5, m = 3;
//	double arr[5][3] = { {1.2, 2.2, 3.2}, {4.1, 5.1, 2.1}, {6.1, 7.4, 6.2}, {8.1, 2.2, 4.8}, {6.3, 4.2, 6.2} };
//	double arr1[n][m];
//
//	copy_9(n, m, arr1, arr);
//	display_arr(n, m, arr1);
//
//	return 0;
//}
//void copy_9(int n, int m, double target[n][m], const double source[n][m]) {
//	int outer_iter, inner_iter;
//
//	for (outer_iter = 0; outer_iter < m; outer_iter++) {
//		for (inner_iter = 0; inner_iter < n; inner_iter++) {
//			*(*(target + outer_iter) + inner_iter) = *(*(source + outer_iter) + inner_iter);
//		}
//	}
//}
//
//void display_arr(int n, int m, double(*target)[m]) {
//	int outer_iter, inner_iter;
//	for (outer_iter = 0; outer_iter < m; outer_iter++) {
//		for (inner_iter = 0; inner_iter < n; inner_iter++) {
//			printf("arr1[%d][%d] : %.1f\n", outer_iter, inner_iter, *(*(target + outer_iter) + inner_iter));
//		}
//	}
//}

//arr1[0][0] : 1.2
//arr1[0][1] : 2.2
//arr1[0][2] : 3.2
//arr1[0][3] : 4.1
//arr1[0][4] : 5.1
//arr1[1][0] : 4.1
//arr1[1][1] : 5.1
//arr1[1][2] : 2.1
//arr1[1][3] : 6.1
//arr1[1][4] : 7.4
//arr1[2][0] : 6.1
//arr1[2][1] : 7.4
//arr1[2][2] : 6.2
//arr1[2][3] : 8.1
//arr1[2][4] : 2.2
//
//--------------------------------
//Process exited after 0.04492 seconds with return value 0
//계속하려면 아무 키나 누르십시오 . . .