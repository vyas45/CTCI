/*
 * Check if the string has all unique characters
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isUnique1(char* str) {
  int countArr[256] = {0};
  int i = 0;
  while(*str) {
    if(countArr[*str] > 0)
      return false; //Saw something from earlier
    countArr[*str]++;
    str++;
  }
  return true; //All good
}

int main() {
  char str[20];

  while(1) {
    printf("Enter the string to check for\n");
    scanf("%s", str);

    //Check using extra space
    if(isUnique1(str))
      printf("String has unique characters\n");
    else
      printf("String doesn't have unique characters\n");
  }

  return 0;
}
