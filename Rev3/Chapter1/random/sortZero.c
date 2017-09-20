/*
 * Write a function to sort a list of integers that looks like this [5,2,0,3,0,1,6,0] -> [1,2,3,5,6,0,0,0] in the most efficient way.
 */
#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int Partition(int arr[], int low, int high) {
  int pivot  = arr[high];
  int i =  low-1;
  int j = 0;

  for(j=low; j<high; j++) {
    if(arr[j]<=pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return(i+1);
}

void quickSort(int arr[], int low, int high) {
  if(low<high) {
    int pi = Partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

void zeroSort(int arr[], int len) {
  int i = 0;
  int count = 0;
  /* First Sort the regular array */
  quickSort(arr, 0, len-1);

  int j = 0;
  for(i=0; i<len; i++) {
    if(arr[i]!=0) {
      arr[j] = arr[i];
      j++;
    }
  }
  for(i=j; i<len; i++)
    arr[i] = 0;
}

int main() {
  int arr[] = {5,2,0,3,0,1,6,0};
  int len = sizeof(arr)/sizeof(int);
  int i = 0;

  zeroSort(arr, len);
  for(i=0; i<len; i++)
    printf("%d", arr[i]);
  printf("\n");

  return 0;
}
