/*
 * Print all possible permutations of a string
 */
#include <stdio.h>
#include <string.h>

void swap(char* a, char* b) {
  printf("Swapping %c and %c\n", *a, *b);
  char temp = *a;
  *a = *b;
  *b = temp;
}

void printPerm(char* arr, int low, int high) {
  int i = 0;
  if(low == high) printf("%s\n", arr);
  else {
    for(i=low; i<=high; i++) {
      swap((arr+low), (arr + i));
      printPerm(arr, low+1, high);
      swap((arr+low), (arr + i));
    }
  }
}

int main() {
  char str[] = "ABC";
  int len = strlen(str);

  printPerm(str, 0, len-1);

  return 0;
}
