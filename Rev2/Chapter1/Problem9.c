/*
 * Check if a string is a rotation of another
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isRotation(char* str1, char* str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  if(len1!=len2) return false;
  else {
    char* temp = (char*)malloc(sizeof(char) * 2 * len1);
    void* subptr = NULL;

    /* make temp with 2*str1 */
    strcat(temp, str1);
    strcat(temp, str1);

    /* Check if there is a substring */
    subptr = strstr(temp, str2);

    if(subptr!=NULL)
      return true;
    else
      return false;
  }
}

int main() {
  char str1[20], str2[20];
  while(1) {
    scanf("%s", str1);
    scanf("%s", str2);

    if(isRotation(str1, str2))
      printf("They are rotations\n");
    else
      printf("They are not rotations\n");

    return 0;
  }
}
