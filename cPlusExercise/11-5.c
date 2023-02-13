#include <stdio.h>
#include <string.h>

//���ڿ� arr���� find��� ���� ã�� �Լ�
//���ϰ� : find�� �ִ� ��� �� ������ ������, ���� ��� null pointer
char* c_find(char* arr, char find);

int main(void) {

  char *arr = "Picture perfect, you don't need no filter";
  printf("�־��� ���ڿ� : %s\n", arr);
  printf("�־��� ���ڿ��� ù ������ �ּ� : %p\n", arr);

  char chas[] = { 'a', 'b', 'c', 'd' };
  char* pt;
  int i;

  for (i = 0; i < 4; i++) {
    printf("---------------------------------------------\n");
    printf("�־��� ���� : %c\n", chas[i]);
    if (pt = c_find(arr, chas[i]))
      printf("%c�� �־��� ���ڿ������� ������ : %p\n", chas[i], pt);
    else 
      printf("�־��� ���ڿ��� %c�� �������� �ʽ��ϴ�\n", chas[i]);
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