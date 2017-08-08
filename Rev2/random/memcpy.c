/*
 * Implement own memcpy() and memove()
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imemcpy(char* dest, char* src, int size) {
  char* dest1 = (char*)dest;
  char* src1 = (char*)src;
  int i = 0;
  for(i=0; i<size; i++) {
    *dest1++ = *src1++;
  }
}

/* My memove() */
void imemmove(void* dest, void* src, int size) {
  char* source = (char*) src;
  char* destin = (char*) dest;

  char* temp = malloc(sizeof(char) * size);
  int  i = 0;
  for(i=0; i<size; i++)
    temp[i] = source[i];
  
  for(i=0; i<size; i++)
    destin[i] = temp[i];
}


int main() {
  char src[20] = "Aniket";
  char dest[10];

  //memcpy(dest, src, strlen(src));

  /* My memcpy() */
  imemmove(dest, src, strlen(src));

  printf("Destinition is %s", dest);


  return 0;
}
