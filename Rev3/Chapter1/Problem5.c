/*
 * One edit away
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * One add or remove
 */
bool OneAddAway(char* str1, char* str2) {
  bool flag = true;
  while(*str1) {
    if(*str1 != *str2) {
      if(!flag)
        return flag;
      str2++;
      flag = false;
    }
    str1++;
    str2++;
  }
  return true;
}

/*
 * Only one char can differ
 */
bool ReplaceAway(char* str1, char* str2) {
  bool flag  = true;
  while(*str1) {
    if(*str1 != *str2) {
      if(!flag)
        return flag;
      flag = false;
    }
    str1++;
    str2++;
  }
  return true;
}

bool isOneEdit(char* str1, char* str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  if(abs(len1-len2) > 1)
    return false; //The lengths differ by more than one
  else {
    if(len1 == len2)
      return(ReplaceAway(str1, str2));
    else if(len1>len2)
      return(OneAddAway(str2, str1));
    else
      return(OneAddAway(str1, str2));
  }
}

int main() {
  char* str1  = malloc(sizeof(char) * 20);
  char* str2  = malloc(sizeof(char) * 20);

  while(1) {
    scanf("%s", str1);
    scanf("%s", str2);

    if(isOneEdit(str1, str2))
      printf("Is One edit away\n");
    else
      printf("Is more than an edit away\n");
  }
  return 0;
}
