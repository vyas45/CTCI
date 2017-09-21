/*
 * Given a triplet find if the sum is X
 */
#include <stdio.h>

void swap(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int Partition(int arr[], int low, int high) {
  int pivot  = arr[high];
  int i = low-1;
  int j = 0;
  for(j=low; j<high; j++) {
    if(arr[j] <= pivot) {
      i = i+1;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return (i+1);
}

void quickSort(int arr[], int low, int high) {
  if(low<high) {
    int pi = Partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}

void findTriplet(int arr[], int size, int x) {
  int i, j, k = 0;
  int sum = 0;

  quickSort(arr, 0, size-1);

  printf("Sorted array is\n");
  for(i=0; i<size; i++)
    printf("%d ", arr[i]);
  printf("\n");

  for(i=0; i<size-2; i++) {
    j = i+1;
    k = size-1;
    while(j<k) {
      sum = arr[i] + arr[j] + arr[k];
      if(sum == x) {
        printf("Triplets \b: %d, %d, %d\n", arr[i], arr[j], arr[k]);
        break;
      }
      else if(sum < x)
        j++;
      else
        k--;
    }
  }
}

int main() {
  int arr[]  = {12, 3, 4, 1, 6, 9};
  int size = sizeof(arr)/sizeof(int);
  int X = 0;

  while(1) {
    scanf("%d", &X);
    findTriplet(arr, size, X);
  }
  return 0;
}
