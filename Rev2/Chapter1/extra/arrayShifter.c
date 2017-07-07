/*
 * Shift the array
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moveZeros(int arr[], int size) {
  int i, j = 0;

  for(i=0; i<size-2; i++) {
    if(arr[i] == 0) {
      for(j=i; j<size-1; j++) {
        arr[j] = arr[j+1];
      }
      arr[j-1] = 0;
    }
  }
}

void moveZerosf1(int* nums, int numsSize) {
	int i = 0;
	int count  = 0;

	/* Take care of the starting zeros */
	for(i=0; i<numsSize;i++) {
		if(nums[i]!=0) {
			nums[count] = nums[i];
			count++;
		}
	}
	/* Fill the remaining positions with 0 */
	for(i=count; i<numsSize;i++)
		nums[i] = 0;
}


void moveZerosf2(int* nums, int numsSize) {
	int i = 0;
	int count  = 0;

	/* Take care of the starting zeros */
	for(i=0; i<numsSize;i++) {
		if(nums[i]!=0) {
			nums[count++] = nums[i];
		}
	}
	/* Fill the remaining positions with 0 */
		while(count<numsSize)
			nums[count++] = 0;
}

void printer(int arr[], int size, double time) {
  int i  = 0;
  for(i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }
	printf("Time taken was %f\n", time);

}

int main() {
  int arr[] = {0, 1, 0, 3, 12};
  int size = sizeof(arr)/sizeof(int);
	clock_t t;
	clock_t tf1;
	clock_t tf2;
	
	/* Slow */
	t = clock();
	moveZerosf2(arr, size);
	t = clock() - t;
	double t1 = ((double)t)/CLOCKS_PER_SEC; // in seconds

	printer(arr, size, t);


	/* Faster */
  tf2 = clock();
  moveZerosf2(arr, size);
	tf2 = clock() - tf2;
	double t2 = ((double)tf2)/CLOCKS_PER_SEC; // in seconds
  printer(arr, size, t2);

	/* Fastest */
	tf1 = clock();
	moveZerosf1(arr, size);
	tf1 = clock() - tf1;
	double t3 = ((double)tf1)/CLOCKS_PER_SEC; // in seconds
	printer(arr, size, t3);

  return 0;
}
