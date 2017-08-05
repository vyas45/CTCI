/* Compress a string 
 * aabbbcdddd => a2b3c1d4
 * abcd => abcd
 */
#include <stdio.h>
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

int main() {
  char str[20] ={0};

  while(1) {
    scanf("%s", str);
    compressString(str);
  }
  return 0;
}
