/*
 * Implement the Merge Sort Function
 */
#include <stdio.h>


void printer(int arr[], int size) {
  int i = 0;
  for(i=0; i<size; i++)
    printf("%d ", arr[i]);
}

/* This method woudl preform the merging of the
 * arrays together into one big merged array */
void Merge(int arr[],  int low, int mid, int high) {
  int i = 0;
  int j = 0;
  int k = 0;
  int n1 = mid-low+1;
  int n2 = high-mid;

  /* Define the two subarrays to be merged */
  int arr1[n1];
  int arr2[n2];

  /* Populate the subarrays */
  for(i=0; i<n1; i++)
    arr1[i] = arr[i + low];
  for(j=0; j<n2; j++)
    arr2[j] = arr[j + mid +1];

  i = 0; //Initial index of first subarray
  j = 0; //Initial index of second subarray
  k = low; //Initial index of merged array

  while(i<n1 && j<n2) {
    if(arr1[i]<=arr2[j]) {
      arr[k] = arr1[i];
      i++;
      k++;
    }
    else {
      arr[k] = arr2[j];
      j++;
      k++;
    }
  }

  /* populdate the remaining items */
  while(i<n1) {
    arr[k] = arr1[i];
    i++;
    k++;
  }

  while(j<n2) {
    arr[k] = arr2[j];
    j++;
    k++;
  }
}

/* The process has to be that we first
 * divide the array into 2 halves and then
 * sort them individually and finally merge
 * everything together
 */
void MergeSort(int arr[], int low, int high) {
  if(low<high) {
    int mid = (low+high)/2;
    printf("Mid is %d\n", mid);
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);

    Merge(arr, low, mid, high);
  }
}

int main() {
  int arr[] = {10, 2, 4, 1, 0, 6};
  int size = sizeof(arr)/sizeof(int);

  MergeSort(arr, 0, size-1);

  printer(arr, size);

  return 0;
}
