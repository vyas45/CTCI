/*
 * Find the index at which the sum of two sides of the array are equal
 *
 */
#include <stdio.h>

void findEq(int arr[], int size) {
  int i = 0;
  int sum = 0;
  int lsum = 0;

  for(i=0; i<size; i++)
    sum += arr[i];

  for(i=0; i<size; i++) {
    sum -= arr[i];
    if(lsum==sum) {
      printf("Index is %d\n", i);
      return;
    }
    lsum += arr[i];
  }
  printf("Index is -1\n");
}

int main() {
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int size = sizeof(arr)/sizeof(int);

    findEq(arr, size);

    return 0;
}
