/*
 * Check Permutation: Given two strings, write a method to decide if one
 * is a permutation of other
 */

 #include <stdio.h>

void isPermutation(char* str1, char *str2) {
  int arr[256] = {0};
  int i = 0;

  while(*str1) {
    arr[*str1]++;
    str1++;
  }
  while(*str2) {
    arr[*str2]--;
    str2++;
  }

  /* Status Quo Needs to be maintained */
  for(i=0; i<256; i++) {
    if(arr[i] >=1 || arr[i]<0) {
      printf("The strings are not a permutation\n");
      return;
    }
  }
  printf("The strings are a permutation of each other\n");
}

 int main() {
  char *str1 = "Aniket";
  char *str2 = "Antkie";

  isPermutation(str1, str2);

  return 0;
}
