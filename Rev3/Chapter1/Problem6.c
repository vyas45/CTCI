/* Compress a string */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_RLEN 50

char* strCompress(char* str) {
    char* dest;
    int len = strlen(str);
    char countArr[MAX_RLEN];
    int i = 0;
    int j = 0;

    dest = malloc(sizeof(char) * 2 * len);

    while(*str) {
      dest[j++] = *str;
      int count = 1;
      while(*(str+1) && (*str == *(str+1))) {
          count++;
          str++;
      }
      /* Copy the count to the count array */
      sprintf(countArr, "%d", count);
      str++;
    for(i=0; *(countArr+i); i++, j++)
      dest[j] = countArr[i];

    }
    dest[j] = '\0';
    return dest;
}

int main() {
  char* str = malloc(sizeof(char) * 20);
  char* dest = malloc(sizeof(char) * 40);

  while(1) {
    scanf("%s", str);
    dest = strCompress(str);
    if(strlen(dest) > strlen(str))
      printf("Compressed string is %s\n", str);
    else
      printf("Compressed string is %s\n", dest);
  }
  return 0;
}
