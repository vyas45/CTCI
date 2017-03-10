/*
 * Is Unique: Implement an algorithm to determine if a string has all
 * unique characters. What if you cannot use additional data structures
 */
#include <stdio.h>

/*
 * Determine if the characters are unique
 * Uses an extra data structure
 * RunTime Complexity : O(n)
 * SpaceTime Complexity : O(n)
 */
void isUnique1(char* str) {
  char *curr = str;
  int arr[256] = {0};

  while(*str) {
    if(arr[*str] >= 1) {
      printf("The characters in the string are not unique\n");
      return;
    }
    arr[*str]++;
    str++;
  }
  printf("The string has unique characters\n");
}

/*
 * Determine if the characters are unique
 * Doesn't use extra data structure
 * RunTime Complexity : O(n^2)
 * Space Complexity : O(1)
 */
void isUnique2(char* str) {
  char *slow  = str;
  char * fast =  str;

  while(*slow) {
    fast = slow + 1;
    while(*fast) {
      if(*slow == *fast) {
       printf("The characters in the string are not unique\n");
      return;
      }
      fast++;
    }
    slow++;
  }
  printf("The string has unique characters\n");
}

/*
 * Another method could be to sort the strings in place
 * Then go over and see if there are repitions
 * RunTime Complexity : O(nlogn) -- Quick Sort
 * Space Complexity: O(1)
 */
void isUnique3(char* str) {
  /* TODO */
}

int main() {
  char *str = "Aniket";

  /* Using extra data struct */
  isUnique1(str);

  /* Without using extra data struct */
  isUnique2(str);

  return 0;
}
