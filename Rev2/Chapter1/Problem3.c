/*
 * URLify a string
 */
#include <stdio.h>
#include <string.h>

void URLify(char str[], int true_len) {
  int count = 0; //To hold the space count
  int max_len = 0;
  int i, j = 0;

  for(i=0; i<true_len; i++) {
    if(str[i] == ' ') 
      count++;
  }
  max_len = true_len + (2*count); //Calculate the max possible length with the additions
  i = true_len;
  j = max_len;

  str[j] = '\0';
  j = j-1;

  for(i=true_len-1; i>=0; i--) {
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
  char str[] = "Mr John Smith     ";
  int true_len = 13;

  URLify(str, true_len);

  /* Print the URLify'd string */
  char *strp = str;
  while(*strp) {
    printf("%c", *strp);
    strp++;
  }

  return 0;
}
