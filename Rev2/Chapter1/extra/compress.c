/* Compress a string 
 * aabbbcdddd => a2b3c1d4
 * abcd => abcd
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void compressString(char* str) {
  char* s = str;
  int count[256] = {0};
  bool flag = false;
  int i = 0;

  while(*s) {
    count[*s]++;
    if(count[*s] > 1) {
      flag = true;
    }
    s++;
  }
  if(!flag) {
    printf("%s", str);
    return;
  }
  for(i=0; i<256; i++) {
    if(count[i] > 0)
      printf("%c%d", i, count[i]);
  }

}

void compressStr(char* str) {
  int i, j = 0;
  int k = 0;
  char count[256];
  int len  = strlen(str);
  int rcount = 0;
  //destinition array
  char* dest = (char*)malloc(sizeof(char) * len);
  for(i=0; i<len; i++) {
    dest[j++] = str[i];
    rcount = 1;
    while(i<len && str[i] == str[i+1]) {
      rcount++;
      i++;
    }
    /* Copy the count to the destinition */
   sprintf(count, "%d", rcount);
   for(k=0;*(count+k); k++,j++)
     printf("Here");
     dest[j] = count[k];
  }
  dest[j] = '\0';
  printf("%s\n", dest);
}

int main() {
  char str[20] ={0};

  while(1) {
    scanf("%s", str);
    //compressString(str);
    compressStr(str);
  }
  return 0;
}
