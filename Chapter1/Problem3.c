/*
 * URLify: Write a method to replace all the spaces in the string with '%20'
 *
 * Input: "Mr John Smith    ", 13
 * Output: "Mr%20John%20Smith"
 */

#include <stdio.h>
#include <string.h>

void URLify(char str[], int true_len) {
  char *curr = str;
  int i = true_len;
  int num_spaces = 0;
  int j = 0;
  int full_len = 0;

  while(i-- && *curr) {
    if(*curr == ' ')
      num_spaces++;
      curr++;
  }

  full_len = true_len + (num_spaces *2);
  printf("Full Len is %d\n", full_len);

  i = true_len;
  j = full_len;

  str[j] = '\0';
  j = j-1;

  for (i = true_len-1; i>=0; i--) {
    printf(" i and str[i] are %d and %c \n", i, str[i]);
    if(str[i] == ' ') {
      printf("\tj is %d\n", j); 
      str[j] = '0';
      str[j-1] = '2';
      str[j-2] = '%';
      j = j-3;
    }
    else {
      str[j] = str[i];
      printf("\tj is %d\n", j); 
      j = j-1;
    }
  }
  curr = str;

  while(*curr) {
      printf("%c ", *curr);
      curr++;
  }
}

int main() {
  char str[] = "Mr John Smith      ";
  printf("string len of main str is %lu\n", strlen(str));
  int true_len = 13;

  URLify(str, true_len);

  return 0;
}
