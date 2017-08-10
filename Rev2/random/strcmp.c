/*
 * Implement string compare
 */
#include <stdio.h>
#include <stdbool.h>

bool mystrcmp(char* str1, char *str2) {
  char* s1 = str1;
  char* s2 = str2;
  int len1, len2 = 0;

  while(*s1) {
    len1++;
  }
  while(*s2) {
    len2++;
  }
  if(len1!=len2) return false;
  else {
    while(*str1)
      return(*str1++ == *str2++);
  }
}

int main() {
  char str1[20], str2[20];

  while(1) {
    printf("Enter the strings to compare\n");
    scanf("%s", str1);
    scanf("%s", str2);

    if(mystrcmp(str1, str2))
      printf("strings are same\n");
    else
      printf("strings are not same\n");
  }
  return 0;
}
