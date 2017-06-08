/*
 * Check if a given string is a permutation of a palindrome
 */
#include <stdio.h>
#include <stdbool.h>

bool isPalinPerm(char str[]) {
  int arr[256] = {0}; //Maintain a count array to count the characters
  char *strp = str;
  bool flag = false;
  int i = 0;

  while(*strp) {
    arr[*strp]++;
    strp++;
  }

  /*
   * Iterate over the count array to see if there are >1 characters with odd count
   */
  for(i=0; i<256; i++) {
    if(arr[i]%2!=0) {
      if(flag)
        return false;
      flag = true;
    }
  }
  return true; //Have all even or only one max odd
}

int main() {
  char str[20];

  while(true) {
    printf("Enter a string\n");
    scanf("%s", str);

    if(isPalinPerm(str))
      printf("Is a permutation of a palindrome\n");
    else
      printf("Not a permutation\n");
  }
  return 0;
}
