#include <stdio.h>

void swap(char *a, char *b) {
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {

  char arr[] = "Aniket";
  int len = 6;
  int i, j = 0;

  for(i=0;i<len;i++) 
    swap(&arr[i], &arr[len-1]);

  for(i=0; i<len;i++)
    printf("%c ", arr[i]);

  return 0;
}
