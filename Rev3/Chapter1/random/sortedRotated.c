/*
 * Given an array which is sorted but rotated
 * find the number
 * 4, 5, 6, 1, 2, 3
 */
#include <stdio.h>

void bs(int arr[], int x, int low, int high) {
  if(low>high) {
    return;
  }
  else {
    int mid = (low+high)/2;
    if(arr[mid] == x) {
      printf("Found %d @ %d", x, mid);
      return;
    }
    else if(arr[mid] > x)
      bs(arr, x, low, mid-1);
    else
      bs(arr, x, mid+1, high);
  }
}

void findX(int arr[], int x, int low, int high) {
  int i = 0;
  int pivot = 0;
  for(i=0; i<high; i++) {
    if(arr[i+1] < arr[i]) {
      pivot = i;
      break;
    }
  }
  if (x == arr[pivot])
    printf("Found element @ %d\n", pivot);
  else if( x > arr[pivot])
    printf("element absent\n");
  else if(x >= arr[low] && x < arr[pivot])
    bs(arr, x, low, pivot);
  else
    bs(arr, x, pivot+1, high);
}



int main() {
  int arr[] = {4, 5, 6, 1, 2, 3};
  int size = sizeof(arr)/sizeof(int);
  int x = 0;

  while(1) {
    scanf("%d", &x);
    findX(arr, x, 0, size-1);
  }

  return 0;
}
