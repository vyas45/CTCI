/*
 * One away: Identify if a string is one edit away
 * An edit can be add, edit or replace
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * Function to check if there is one insert/delete
 */
bool isInsert(char str1[], char str2[]) {
  char *curr1, *curr2 = NULL;
  int index1 = 0;
  int index2 = 0;

  curr1 = str1;
  curr2 = str2;
  while(*str1 && *str2) {
    if(*str1!=*str2) {
      if(index1!=index2) {
        return false;
      }
      index2++;
      str2++;
    }
    else {
      index1++;
      index2++;
      str1++;
      str2++;
    }
  }
  return true;
}

/*
 * Function to check if there is one
 * and only one replacement in the 2 strings
 */
bool isReplace(char str1[], char str2[]) {
  char *curr1, *curr2 = NULL;
  bool flag = false;

  curr1 = str1;
  curr2 = str2;

  while(*curr1 && *curr2) {
    if(*curr1 != *curr2) {
      if(flag)  return false;
      flag = true;
    }
    curr1++;
    curr2++;
  }
  return true; //Has one or less edits :)
}

/*
 * Function to check if the strings are
 * One Edit Away
 */
bool isOneEditAway(char str1[], char str2[]) {
  int len1 = 0;
  int len2 = 0; //Holding string lengths
  char *curr1, *curr2 = NULL;
  int count = 0; //Flag to track the change
  bool retFlag = false;

  curr1 = str1;
  curr2 = str2;

  /*Compute the lengths */
  while(*curr1) {
    len1++;
    curr1++;
  }
  while(*curr2) {
    len2++;
    curr2++;
  }
  /*
   * If the lengths differ by more than 1
   * then more than one edit for sure
   * Call the appropriate methods
   */
   if(len1 == len2)
     return(isReplace(str1, str2));
   else if(len1+1 == len2)
     return(isInsert(str1, str2));
   else if(len1 == len2+1)
     return(isInsert(str2, str1));
   else
     return false;//Everything else has more than one edits
}

int main() {
  char str1[]  = "pale";
  char str2[] = "palea";

  if(isOneEditAway(str1, str2))
    printf("The string is one edit away\n");
  else
    printf("The string is more than an edit away\n");

}
