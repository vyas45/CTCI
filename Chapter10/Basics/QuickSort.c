/*
 * Implementation of quick sort algorithm
 * Average case complexity : O(nlogn)
 * Worst case : O(n^2)
 * Space complexity : O(1)
 */
#include <stdio.h>

/* Print the array */
void printarr(int arr[], int size) {
  int i = 0;
  for(i=0; i<size; i++)
    printf("%d ", arr[i]);
}

/*
 * Swap routine
 */
void swap(int* a, int* b) {
  int temp = 0;
  temp = *a;
  *a = *b;
  *b = temp;
}

/* Partition the array
 * The idea is to make the array sorted on left and
 * right side of the partition element
 */
int Partition(int arr[], int start, int end) {
  int  i = 0;

  /* We choose the pivot element to be the last element */
  int pivot = arr[end];
  int pindex = start;

  /* Perform the pivot sort logic */
  for(i=start; i<=end-1; i++) {
    if(arr[i]<=pivot) {
      swap(&arr[i], &arr[pindex]);
      pindex++;
    }
  }
  /* Everything seems sorted, place the pivot correctly */
  swap(&arr[end], &arr[pindex]);

  /* return the pivot index */
  return pindex;
}

/* Quick Sort Implementation */
void QuickSort(int arr[], int start, int end) {
  int pi = -1; //pivot Index
  if(start<end) {
    /* Partition the array */
    pi = Partition(arr, start, end);
    /* Sort left and right sub-arrays in-place */
    QuickSort(arr, start, pi-1);
    QuickSort(arr, pi+1, end);
  }
}


int main() {
  int arr[] = {2, 7, 1, 6, 8, 5, 3, 4};
  int size = sizeof(arr)/sizeof(int);

  QuickSort(arr, 0, size-1);

  printarr(arr, size);

  return 0;
}
