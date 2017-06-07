/*
 * Find if a string has all unique characters
 */
#include <stdio.h>
#include <stdbool.h>

/*
 * This is an iterative method
 * Time complexity : O(n^2)
 */
bool isUnique2(char str[]) {
  char *first = str;
  char *second = str;

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
    if(isUnique(str))
      printf("unique\n");
    else
      printf("Not unique\n");
  }
  return 0;
}
