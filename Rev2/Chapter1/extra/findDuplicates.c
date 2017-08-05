#include <stdio.h>


/* Get dups/merge dups */
void getDups(int arr1[], int arr2[], int size1, int size2) {


}

void printer(int arr[], int size) {
  int i = 0;
  for(i=0; i<size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr1[] = {1, 2, 3, 5, 6, 7};
  int arr2[] = {3, 6, 7, 8, 20};

  int size1 = sizeof(arr1)/sizeof(int);
  int size2 = sizeof(arr2)/sizeof(int);

  if(size1>=size2) {
    getDups(arr1, arr2, size1, size2);
  }
  else {
    getDups(arr2, arr1, size2, size1);
  }
  printer(arr1, size1);
  return 0;
}
