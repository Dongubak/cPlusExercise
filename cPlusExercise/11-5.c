#include <stdio.h>
#include <string.h>

//문자열 arr에서 find라는 문자 찾는 함수
//리턴값 : find가 있는 경우 그 문자의 포인터, 없는 경우 null pointer
char* sol5(char* arr, char find);

int main11_5(void) {

  char arr[] = "Picture perfect, you don't need no filter";
  char chas[] = { 'a', 'b', 'c', 'd' };
  char* pt;
  int i;

  for (i = 0; i < 4; i++) {
    if (pt = sol5(arr, chas[i])) {
      printf("주어진 문자열 : %s, 대상 문자 : %c, 주어진 문자열의 첫 원소의 주소 : %zd, 대상 문자의 주어진 문자열에서의 포인터 : %zd\n", arr, chas[i], arr, pt);
    }
    else {
      printf("주어진 문자열 : %s, 대상 문자 : %c, 주어진 문자열의 첫 원소의 주소 : %zd, 주어진 문자열에 대상문자가 존재하지 않습니다\n", arr, chas[i], arr);
    }
  }

  return 0;
}

char* sol5(char* arr, char find) {
  char* result = NULL;
  int i;

  for (i = 0; i < strlen(arr); i++) {
    if (arr[i] == find) {
      result = &arr[i];
      break;
    }
  }

  return result;
}