/* 
 * Check if a given string is permutation of another
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPerm(char str1[], char str2[]){
  int countArr[256] = {0};
  char *strp = str1;
  int i = 0;

  /* If lenghts aren't same, can't be perms */
  if(strlen(str1) != strlen(str2))
    return false;

  /* Populate the array */
  while(*strp) {
    countArr[*strp]++;
    strp++;
  }

  /*Get to the second array */
  strp = str2;
  while(*strp) {
    countArr[*strp]--;
    strp++;
  }

  /* Loop over to check if anything is non zero */
  for(i=0;i<256;i++) {
    if(countArr[i] != 0)
      return false;
  }

  /*Made it through should be a permutation */
  return true;
}

int main() {
  char str1[20], str2[20];

  while(true) {
    printf("Enter the strings\n");
    scanf("%s", str1);
    scanf("%s", str2);

    if(isPerm(str1, str2))
      printf("They are permutations\n");
    else
      printf("They are not permutations\n");
  }

  return 0;
}
