/*
 * Find if a string has all unique characters
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Swapper */
void swap(char *a, char *b) {
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

/*
 * Partition routine to line-up items in the array
 */
int Partition(char arr[], int low, int high) {
  int i = low-1;
  int j = 0;
  char pivot = arr[high]; //Choosing the last element as the pivot element

  for(j=low; j<=high-1; j++) {
    if(arr[j] <= pivot) {
      i++;
      swap(&arr[j], &arr[i]); //Making sure that the smaller element is behind
    }
  }
  swap(&arr[i+1], &arr[high]); //Swap the pivot at the right position
  return (i+1);
}


/* Quick Sort Implementation */
void QuickSort(char arr[], int low, int high) {
  int pi = 0;

  if(low<high) {
    pi = Partition(arr, low, high);
    QuickSort(arr, low, pi-1);
    QuickSort(arr, pi+1, high);
  }
}

/*
 * This method would base of Sorting
 * Step1: Sort the string
 * Step2: Iterate over the string to check if anything
 * is getting repeated
 *
 * Time Complexity: Depends on the soring algorithm.
 * QuickSort would be a good in-place option with
 * complexity = O(nlogn)
 *
 */
bool isUnique3(char str[]) {
  /* No point if the string is longer than the
   * character set */
  if(strlen(str) > 256)
    return false;

  /* First sort the array */
  QuickSort(str, 0, strlen(str)-1);

  /* Iterate to check if there are repeaters */
  char *strp = str;

  while(*strp && *(strp+1)) {
    if(*strp == *(strp+1))
      return false;
    strp++;
  }
  return true; //Made through, is unique
}

/*
 * This is an iterative method
 * Time complexity : O(n^2)
 */
bool isUnique2(char str[]) {
  char *first = str;
  char *second = str;

  /* No point if the string is longer than the
   * character set */
  if(strlen(str) > 256)
    return false;

  while(*first) {
    second = first+1; //Always start at the next char
    while(*second) {
      if(*second == *first)
        return false;
      second++;
    }
    first++;
  }
  return true; //Reaching here means we got out clean
}

/*
 * This method uses an extra array
 * Time complexity -> O(n)
 * Space complexity -> O(1) but extra memory required
 */
bool isUnique(char str[]) {
  char *strp = str;
  int arr[256] = {0};

  /*
   * So here , the input size is limited
   * but is good logical check as anything
   * over 256 is going to be repeated string
   */
  if(strlen(str) > 256)
    return false;

  /* Walk over the string */
  while(*strp) {
    /* Already visited the character */
    if(arr[*strp]>0)
      return false;
    arr[*strp]++;
    strp++;
  }
  return true;
}

int main() {
  char str[20] = "";
  while(true) {
    printf("Enter the string to check\n");
    scanf("%s", str); //Get the string from user

    /* Call the method to check */
    if(isUnique3(str))
      printf("unique\n");
    else
      printf("Not unique\n");
  }
  return 0;
}
