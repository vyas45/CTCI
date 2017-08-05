/*
 * Check if two strings are one edit away
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool OneAddRemove(char* str1, char* str2) {
  bool flag = false;
  while(*str2) {
    if(*str1 != *str2) {
      if(flag) return false;
      flag = true;
      str1++;
    }
    str1++;
    str2++;
  }
  return true;
}

bool OneEdit(char* str1, char* str2) {
  bool flag = false;
  while(*str1) {
    if(*str1 != *str2) {
      if(flag) return false;
      flag = true;
    }
    str1++;
    str2++;
  }
  return true;
}

bool isOneEditAway(char* str1, char* str2) {
  int len1 = 0;
  int len2 = 0;

  char* s1 = str1;
  char* s2 = str2;

  while(*s1) {
    len1++;
    s1++;
  }
  while(*s2) {
    len2++;
    s2++;
  }
  if(abs(len1-len2)>1) return false;
  else {
    if(len1 == len2)
      return(OneEdit(str1, str2));
    else if(len1 > len2)
      return(OneAddRemove(str1, str2));
    else
      return(OneAddRemove(str2, str1));
  }
}

int main() {
  char str1[20] = {0};
  char str2[20] = {0};

  while(1) {
    scanf("%s", str1);
    scanf("%s", str2);
    if(isOneEditAway(str1, str2)) {
      printf("The strings are one edit away\n");
    }
    else {
    printf("The strings are more than an edit away\n");
    }
  }
  return 0;
}
