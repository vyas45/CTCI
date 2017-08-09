/*
 * Given an array rotate it by d units
 */
#include <stdio.h>

void printer(int arr[], int size) {
  int i = 0;
  for(i=0; i<size; i++)
    printf("%d ", arr[i]);
}

void leftbyone(int arr[], int size) {
  int temp = arr[0];
  int i = 0;
  for(i=0; i<size-1; i++) {
    arr[i] = arr[i+1];
  }
  arr[i] = temp;
}

void rotate(int arr[], int size, int units) {
  int i = 0;
  for(i=0; i<units; i++)
    leftbyone(arr, size);
  printer(arr, size);
}

int main() {

  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr)/sizeof(int);

  rotate(arr, size, 1);

  return 0;
}
