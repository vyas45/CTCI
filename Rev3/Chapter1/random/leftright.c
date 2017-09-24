/* Find a point where the array is balanced */
#include <stdio.h>

void balanced(int arr[], int size) {
  int sum = 0;
  int lsum = 0;
  int rsum  = 0;
  int i  = 0;

  /* Compute the total sum */
  for(i=0; i<size; i++)
    sum += arr[i];

  for(i=0; i<size-1; i++) {
    sum = sum-arr[i];
    printf("Index = %d\n", i);
    printf("Left sum is %d\n", lsum);
    printf("Right sum is %d\n", sum);


    if(sum == lum) {
      printf("Array balanced at index %d element %d", i, arr[i]);
      return;
    }

    lsum += arr[i];
    printf("\n\n");
  }
  printf("Unabalanced array\n");
}

int main() {
  int arr[] = {-7, 1, 5, 2, -4, 3, 0};
  int size = sizeof(arr)/sizeof(int);

  balanced(arr, size);

  return 0;
}
