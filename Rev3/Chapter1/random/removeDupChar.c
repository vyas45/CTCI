/* Remove duplicate characters from a string */
#include <stdio.h>

void removeDups(char* str) {
  char *slow = str;
  char *fast = str;
  int countArr[256] = {0}; //Count array to keep track of dups
  while(*fast) {
    /* Repeater */
    if(countArr[*fast] > 0)
      fast++;
    else {
      countArr[*fast]++;
      *slow++ = *fast++;
    }
  }
  *slow = '\0';
  printf("%s\n", str);
}

int main() {
  char str[20];
  while(1) {
    printf("Enter a string\n");
    scanf("%s", str);
    removeDups(str);
  }
  return 0;
}
