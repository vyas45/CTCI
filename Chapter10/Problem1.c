/*
 * Merge 2 sorted arrays
 */
#include <stdio.h>

void printer(int arr[], int size) {
  int i = 0;
  for(i=0; i<size; i++)
    printf("%d  ", arr[i]);
}

void mergeSorted(int A[], int B[], int sizeA, int sizeB) {
  int i = sizeA-sizeB-1;
  int j = sizeB-1;
  int k = sizeA-1;

  while(i>=0 && j>=0) {
    if(A[i] > B[j]) {
      A[k] = A[i];
      k--;
      i--;
    }
    else {
      A[k] = B[j];
      k--;
      j--;
    }
  }
  while(j>=0) {
    A[k] = B[j];
    k--;
    j--;
  }
}


int main() {
  int A[] = {4, 6, 8, 0, 0, 0, 0};
  int B[] = {0, 2, 3, 5};

  int sizeA = sizeof(A)/sizeof(int);
  int sizeB = sizeof(B)/sizeof(int);

  mergeSorted(A, B, sizeA, sizeB);

  printer(A, sizeA);

  return 0;
}
