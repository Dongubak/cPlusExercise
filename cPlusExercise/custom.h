#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable :4996)

///(buffer, maxCount) -> char* : maxCount이상의 문자는 폐기한다.
char* s_gets(char* st, int n);
///(buffer) -> void : 문자열 출력(개행x)
void put1(const char* string);
///(buffer, len) -> void : buffer + len에 널문자 넣어 길이를 맞춤
void fit(char* string, unsigned int size);
//(row, col, quit_string) -> 입력받은 문자열포인터 배열 : row개의 문자열을 입력받아 동적배열 생성
//입력종료시 개행입력, col개수초과문자는 폐기
char** s_gets_gets(int row, int col, const char* quit_string);
///(void) -> void : 버퍼 비우기
void clear_buf(void);