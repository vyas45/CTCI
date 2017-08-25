/*
 * Implement string compare
 */
#include <stdio.h>
#include <stdbool.h>

bool mystrcmp(char* str1, char *str2) {
  char* s1 = str1;
  char* s2 = str2;
  int len1, len2 = 0;

  while(*s1 && *s2) {
    if(*s1 != *s2) return false;
    s1++;
    s2++;
  }
  if(*s2 || *s1) return false;

  return true; //Reached here , all good
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
