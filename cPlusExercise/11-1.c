#include <stdio.h>
#include "custom.h"

void s_gets_a(char* st, int n);

int main(void) {

	int input_number = 0;

	printf("enter N : ");
	scanf("%d", &input_number);

	clear_buf();

	char* arr = (char*)malloc(sizeof(char) * input_number);
	
	s_gets_a(arr, input_number);

	free(arr);

	return 0;
}

void s_gets_a(char* st, int n) {

	int i = 0;
	char tmp = 0;

	while (i < n && (tmp = getchar()) != EOF) {
		st[i] = tmp;
		i++;
	}

	clear_buf();
}