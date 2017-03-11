/* Routine to perform QuickSort */
#include <stdio.h>

/*
 * Array Printer
 */
void printer(int arr[], int size) {
    int i = 0;
    for(i=0; i<=size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

/*
 * Swap two integers
 */
void swap(int *a, int *b) {
  int temp = 0;
  temp = *a;
  *a = *b;
  *b = temp;
}

/*
 * This method basically takes a pivot, in our
 * case pivot is the last element. It then 
 * arranges all elements of the array around the 
 * pivot element (smaller - > pivot - > greater)
 * The left and right sub-arrays need not be sorted
 */
int Partition(int arr[], int low, int high) {
  int i, j = 0;
  int pivot = arr[high];

  i = low - 1;
  for(j=low; j<=high-1;j++) {
      if(arr[j] <= pivot) {
        i++;
        swap(&arr[i], &arr[j]);
      }
  }
  swap(&arr[i+1], &arr[high]);
  return i+1;
}

/*
 * Top level method to perform quick Sort
 * QuickSort uses divide and conquer approach
 * RunTime Complexity : O(n^2) (worst case) , O(nlgn) (average case)
 * Space Complexity : O(1)
 */
void QuickSort(int arr[], int low, int high) {
    if(low<high) {
      /*
       * Partition the array to have the 
       * correct order on elements on left
       * and right side of the pivot
       */
      int q = Partition(arr, low, high);

      /*
       * Call Quick Sort recursively for left
       * and right sub-arrays
       */
      QuickSort(arr, low, q-1);
      QuickSort(arr, q+1, high);
    }
}

int main() {
  int arr[] = {10, 80, 30, 90, 40, 50, 70};
  int size  = sizeof(arr)/sizeof(int);

  QuickSort(arr, 0, size-1);

  printf("The sorted array is \n\n");
  printer(arr, size);
  //Partition(arr, 0, size-1);

  return 0 ;
}
