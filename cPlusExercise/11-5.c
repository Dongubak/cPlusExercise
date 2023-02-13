#include <stdio.h>
#include <string.h>

//문자열 arr에서 find라는 문자 찾는 함수
//리턴값 : find가 있는 경우 그 문자의 포인터, 없는 경우 null pointer
char* c_find(char* arr, char find);

int main(void) {

  char *arr = "Picture perfect, you don't need no filter";
  printf("주어진 문자열 : %s\n", arr);
  printf("주어진 문자열의 첫 원소의 주소 : %p\n", arr);

  char chas[] = { 'a', 'b', 'c', 'd' };
  char* pt;
  int i;

  for (i = 0; i < 4; i++) {
    printf("---------------------------------------------\n");
    printf("주어진 문자 : %c\n", chas[i]);
    if (pt = c_find(arr, chas[i]))
      printf("%c의 주어진 문자열에서의 포인터 : %p\n", chas[i], pt);
    else 
      printf("주어진 문자열에 %c가 존재하지 않습니다\n", chas[i]);
  }


  return 0;
}

char* c_find(char* arr, char find) {
  char* result = (void*)0;
  int i = 0;

  for (i = 0; i < strlen(arr); i++) {
    if (arr[i] == find) {
      result = &arr[i];
      break;
    }
  }

  return result;
}