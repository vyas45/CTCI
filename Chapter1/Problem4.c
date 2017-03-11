/*
 * Palindrome Permutation: Check if the given string is a permutation of palindrom
 */
#include <stdio.h>
#include <stdbool.h>

/* Can have atmost 1 character with count as 1 */
bool isPalinPerm(char* str) {
  int i = 0;
  if(str == NULL) return true;
  int arr[256] = {0};
  bool flag = false;
  char* curr = str;

  while(*curr) {
    if(*curr!= ' ') {
      arr[*curr]++;
    }
    curr++;
  }
  for(i=0; i<256; i++) {
    if(arr[i] > 2) return false;
    if(arr[i] == 1) {
      if(flag) return false;
      else flag = true;
    }
  }
  return true;
}

int main() {
  char *str = "tact coa";

  if(isPalinPerm(str))
      printf("Is a palin perm\n");
  else
      printf("Not a palin perm\n");

  return 0;
}
