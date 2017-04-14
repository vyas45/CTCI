/*
 * Find the index of the element if the array has been rotataed "n" times
 */
#include <stdio.h>

int findX(int arr[], int start, int end, int x) {
  if(start<=end) {
    int mid = (start+end)/2;
    printf("Mid is %d and the element is %d\n", mid, arr[mid]);
    /* try to get the flipping element */
    if(arr[mid-1]>=arr[mid]) return mid;
    findX(arr, start, x, mid-1);
    findX(arr, mid+1, x, end);
  }
  return -1;
}
int main() {
  int arr[] = {15, 16, 19, 20, 25, 28, 1};
  int size = 0;

  int x = 0;
  int index = 0;
  size = sizeof(arr)/sizeof(int);

  while(1) {
    scanf("%d", &x);
    index = findX(arr, 0, size-1, x);
    if(index) {
      printf("The index is %d\n", index);
    }
    else {
      printf("Element not found\n");
    }
  }

  return 0;
}
