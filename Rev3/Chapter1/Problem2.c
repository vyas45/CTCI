/* Check if a string is permutation of another */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPerm(char* str1, char* str2) {
  int i = 0;
  int countArr[256] = {0};

  if(strlen(str1) != strlen(str2))
    return false; //Different lengths
  while(*str1) {
    countArr[*str1]++;
    str1++;
  }
  while(*str2) {
    countArr[*str2]--;
    str2++;
  }
  for(i=0; i<256; i++) {
    if(countArr[i] != 0)
      return false; //No good
  }
  return true; //All good
}

int main() {
  char* str1 = malloc(sizeof(char) * 20);
  char* str2 = malloc(sizeof(char) * 20);

  while(1) {
    scanf("%s", str1);
    scanf("%s", str2);

    if(isPerm(str1, str2))
      printf("Permutations\n");
    else
      printf("Not permuatitions\n");
  }
  return 0;
}
