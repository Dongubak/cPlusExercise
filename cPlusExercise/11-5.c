#include <stdio.h>
#include <string.h>

//���ڿ� arr���� find��� ���� ã�� �Լ�
//���ϰ� : find�� �ִ� ��� �� ������ ������, ���� ��� null pointer
char* sol5(char* arr, char find);

int main11_5(void) {

  char arr[] = "Picture perfect, you don't need no filter";
  char chas[] = { 'a', 'b', 'c', 'd' };
  char* pt;
  int i;

  for (i = 0; i < 4; i++) {
    if (pt = sol5(arr, chas[i])) {
      printf("�־��� ���ڿ� : %s, ��� ���� : %c, �־��� ���ڿ��� ù ������ �ּ� : %zd, ��� ������ �־��� ���ڿ������� ������ : %zd\n", arr, chas[i], arr, pt);
    }
    else {
      printf("�־��� ���ڿ� : %s, ��� ���� : %c, �־��� ���ڿ��� ù ������ �ּ� : %zd, �־��� ���ڿ��� ����ڰ� �������� �ʽ��ϴ�\n", arr, chas[i], arr);
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