#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lenner(char* str) {
  int len  =  strlen(str);
  printf("Length is %d\n", len);
}

int main() {
  char* str = malloc(sizeof(char) * 20);
  scanf("%s", str);
  printf("%s\n", str);

  lenner(str);

  return 0;
}
