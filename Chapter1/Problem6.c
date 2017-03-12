/*
 * String Compression:
 * Given the string aabbbcdd -> a2b3c1d2
 * Return the length of the new string 
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Method 1 involves returning a new string 
 */
char* strCompress1(char str[]) {
  char *dest = malloc(sizeof(char) * 10); //Basically need the maxomum length before hand
  char *curr = str;
  int count = 0;
  char *destRet = dest;

  while(*str) {
    count = 1;
    curr = str+1;
    while(*curr == *str) {
      curr++;
      count++;
        //printf("Count of %c is %d\n", *str, count);
    }
    *dest = *str;
    *(dest+1) = '0' + count; //IMPORTANT: Need to get the equaivalen ASCII representation
    dest = dest+2;
    printf("Count for %c is %d\n", *str, count);
    str  = curr;
  }
  *dest = '\0';
  return destRet;
}

int main() {
  char str[] = "aabbbcdd";
  char *newStr = NULL;

  newStr = strCompress1(str);

  while(*newStr) {
    printf("%c", *newStr);
    newStr++;
  }

  return 0;
}
