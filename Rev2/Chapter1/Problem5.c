/*
 * Check if the 2 strings are one edit away
 *
 * pale, ple -> True
 * pales, plae -> True
 * pale, bale -> True
 * pale, bake -> True
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* If the lengths are different then no edit is allowed
 * starting from the shorter string */
bool addOrRemove(char str1[], char str2[]) {
  char *strp1 = str1;
  char *strp2 = str2;

  /* Walk over starting at the shorter string to check
   * if there is any change */
  while(*strp1) {
    if(*strp1 != *strp2)
      return false; /* Not allowed for one edit only */
    strp1++;
    strp2++;
  }
  return true; //No edits except for the last one
}

/*
 * If the lengths are same then
 * only one change allowed
 */
bool replace(char str1[], char str2[]) {
  printf("Lengths are same, can have only one replace\n");
  char *strp1 = str1;
  char *strp2 = str2;
  bool flag = false;

  while(*strp1 && *strp2) {
    if(*strp1 != *strp2) {
      if(!flag)
        flag = true; /* Saw the first change */
      else
        return false; /* Second Edit! */
    }
    strp1++;
    strp2++;
  }
  /* Reached here, must be only one edit */
  return true;
}

/*
 * Method to check if the two strings are more than
 * an edit away
 */
bool isOneEditAway(char str1[], char str2[]){
  bool ret = false;
  /* Can disregard if the lengths are more than
   * one off */
  //if(abs(strlen(str1) - strlen(str2)) > 1)
  //  ret = false;
  if(strlen(str1) == strlen(str2))
    ret = replace(str1, str2);
  else if(strlen(str1)>strlen(str2))
    ret = addOrRemove(str2, str1);
  else
    ret = addOrRemove(str1, str2);

  return ret;
}

int main() {
  char str1[20], str2[20];

  while(1) {

    printf("Enter the two strings\n");
    scanf("%s", str1);
    scanf("%s", str2);

    if(isOneEditAway(str1, str2))
      printf("They are an edit away\n");
    else
      printf("They are more than an edit away\n");

  }
  return 0;
}
