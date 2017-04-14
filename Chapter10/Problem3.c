/*
 * Find the index of the element if the array has been rotataed "n" times
 */
#include <stdio.h>

int findX(int arr[], int low, int high, int x) {
  int mid = (low+high)/2;
  if(arr[mid] == x)
      return mid;
  if(low>high)
      return -1;

  /* One of the sub-arrays has to be sorted
   * Check which one
   */
  /* Left is sorted */
  if(arr[low]<arr[mid]) {
    if(arr[low] <= x && x<= arr[mid])
      return(findX(arr, low, mid-1, x));
    return(findX(arr, mid+1, high, x));
  }
  else {
    if(arr[mid+1]<=x && x<=arr[high])
      return(findX(arr, mid+1, high, x));
    return(findX(arr, low, mid-1, x));
  }
}

int main() {
  int arr[] = {15, 16, 19, 20, 25, 28, 1, 3, 4, 5, 7, 10, 14};
  int size = 0;
  int x = 0;
  int index = 0;

  size = sizeof(arr)/sizeof(int);

  while(1) {
    scanf("%d", &x);
    index = findX(arr, 0, size-1, x);
    if(index>=0) {
      printf("The index is %d\n", index);
    }
    else {
      printf("Element not found\n");
    }
  }

  return 0;
}
