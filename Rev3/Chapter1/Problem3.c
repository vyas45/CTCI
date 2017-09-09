/*
 * Replace all spaces in the string with %20
 */
#include <string.h>
#include <stdio.h>

void URLify(char str[], int trueLen) {
  int  i = 0;
  int  j = 0;
  int numSpace = 0;
  int totalLen = 0;

  for(i=0; i<trueLen; i++) {
    if(str[i] == ' ')
      numSpace++;
  }
  totalLen = trueLen + (numSpace*2);
  j = totalLen;
  str[j] = '\0';
  j--;

  for(i=trueLen-1; i>=0; i--) {
    if(str[i] == ' ') {
      str[j] = '0';
      str[j-1] = '2';
      str[j-2] = '%';
      j = j-3;
    }
    else {
      str[j] = str[i];
      j = j-1;
    }
  }
}

int main() {
  char str[18] = "Mr John Smith     ";

  URLify(str, 13);

  printf("URLifyd string is %s\n", str);

  return 0;
}
