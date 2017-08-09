/*
 * Run length encoding
 * aabbccddd =  a2b2c2d3
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Run length encoder
 * idea is to keep a new array
 * and keep filling up as we see
 * occurances
 */
void runEncoder(char str[]) {
  int len = strlen(str);
  char* dest = (char*)malloc(sizeof(char) * len);
  char count[9] = {0}; //Count array
  int i = 0;
  int j = 0;
  int k = 0;

  for(i=0; i<len; i++) {
    int rcount = 1;

    dest[j++] = str[i];

    while(i<len && str[i] == str[i+1]) {
      i++;
      rcount++;
    }
    sprintf(count, "%d", rcount);
    /* Copy over the count to the destinition array */
    for(k=0; *(count+k); k++, j++)
      dest[j] = count[k];
  }
  dest[j] = '\0';
  printf("%s", dest);
}


int main() {
  char str[20];
  while(1) {
    printf("Enter the string to encode\n");
    scanf("%s", str);
    runEncoder(str);
  }
  return 0;
}
