#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int arr[], int low, int high) {
  int i, j = 0;
  int pivot = arr[high];
  i = low-1;

  for(j=low; j<high; j++) {
    if(arr[j]<=pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return (i+1);
}

void sortArr(int arr[], int low, int high) {
  if(low<high) {
    int pi = Partition(arr, low, high);
    sortArr(arr, low, pi-1);
    sortArr(arr, pi+1, high);
  }
}

void findTriplet(int arr[], int size, int x) {
  int i = 0;
  int low, high = 0;
  int sum = 0;
  bool flag = false;

  /* Sort the array first */
  sortArr(arr, 0, size-1);

  /* Print the sorted array */
  for(i=0; i<size; i++)
    printf("%d  ", arr[i]);

  for(i=0; i<size-1;i++) {
    low = i+1;
    high = size-1;

    while(low<high) {
      sum = arr[i] + arr[low] + arr[high];
      if(sum == x) {
        printf("\n %d + %d + %d = %d\n", arr[i], arr[low], arr[high], x);
        flag = true;
        break;
      }
      else if(sum < x) {
        low++;
      }
      else {
        high--;
      }
    }
  }
  if(!flag)
    printf("No triplet\n");
}

int main() {
  int arr[]  = {-1, 0, 1, 2, -1, -4};
  int size = sizeof(arr)/sizeof(int);
  int X = 0;

  while(1) {
    scanf("%d", &X);
    findTriplet(arr, size, X);
  }

  return 0;
}
