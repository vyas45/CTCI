/*
 * Palindrome permutation
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*
 * Only one character can occur odd number of times
 */
bool isPermPalin(char* str) {
  int i = 0;
  int countArr[256] = {0};
  bool flag = true;

  while(*str) {
    if(!isspace(*str)) {
      countArr[*str]++;
    }
    str++;
  }

  for(i=0; i<256; i++) {
    if(countArr[i] %2 != 0) {
      if(!flag)
        return flag; //Second odd
       else
        flag = false;
    }
  }
  return true;//All good
}

int main() {
  char* str = malloc(sizeof(char) * 20);

  while(1) {
    fgets(str, 20, stdin);
    if(isPermPalin(str))
      printf("Is a perm of palin\n");
    else
      printf("Not a perm of palin\n");
  }

  return 0;
}
