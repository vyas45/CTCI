/*
 * is substring
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/* is str2 a substring of str1 */
void isStrStr(char* str1, char* str2) {
  int m = strlen(str1);
  int n = strlen(str2);
  int i = 0;

  char *fast = str2;
  char *slow = str1;
  for(i=0; i<(m); i++) {
    if(*fast == *(str1+i)) {
        slow = str1+i;
        fast = str2;
        while(*slow && *fast && *slow==*fast) {
          slow++;
          fast++;
        }
        if(!(*fast)) {
          printf("Is a substring\n");
          return;
        }
    }
  }
  printf("Not a substring\n");
}

int main() {
  char str1[20], str2[20];

  while(1) {
    //fgets(str1, 20, stdin);
    //fgets(str2, 20, stdin);
    scanf("%s", str1);
    scanf("%s", str2);

    isStrStr(str1, str2);
  }
}
