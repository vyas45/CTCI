/*
 * QuickSort to sort an array
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int arr[], int low, int high) {
  int i, j = 0;
  int pivot = arr[high];

  i = low-1;
  for(j=low; j<high; j++) {
    if(arr[j] <= pivot) {
      printf("Here\n");
      i++;
      swap(&arr[j], &arr[i]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return (i+1);
}

void printer(int* arr, int size) {
  int i = 0;
  for(i=0; i<size; i++)
    printf("%d ", *(arr+i));

  printf("\n");

}

void QuickSort(int arr[], int low, int high) {
  if(low<high) {
    int pi  = Partition(arr, low, high);
    QuickSort(arr, low, pi-1);
    QuickSort(arr, pi+1, high);
  }
}

int main() {
  int arr[] = {10, 1, 5, 17, 9, 112, 2};
  int size = sizeof(arr)/sizeof(int);

  QuickSort(arr, 0, size-1);

  printer(arr, size);

  return 0;
}
