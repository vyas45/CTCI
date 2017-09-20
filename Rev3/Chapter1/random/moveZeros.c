#include <stdio.h>

int main() {
  int i = 0;
  int j = 0;

  int arr[] = {1, 0, 2, 0, 4, 1, 5, 0};
  int len = sizeof(arr)/sizeof(int);
  for(i=0; i<len; i++) {
    if(arr[i]!=0) {
      arr[j] = arr[i];
      j++;
    }
  }
  for(i=j; i<len; i++)
    arr[i] = 0;


  for(i=0; i<len; i++)
    printf("%d", arr[i]);
}

