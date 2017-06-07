/* 
 * Check if a given string is permutation of another
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Swap the characters */
void swap(char *a, char* b) {
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

/* Partition algorithm */
int Partition(char str[], int low, int high) {
  int i = low-1;
  int j = 0;
  char pivot = str[high];

  /* Walk over the array to swap elements */
  for(j=low; j<=high-1; j++) {
    if(str[j] <= pivot) {
      i++;
      swap(&str[i], &str[j]);
    }
  }
  swap(&str[i+1], &str[high]);
  return (i+1);
}


/* Quick Sort Implementation */
void QuickSort(char str[], int low, int high) {
  int pi;
  if(low<high) {
    pi = Partition(str, low, high);
    QuickSort(str, low, pi-1);
    QuickSort(str, pi+1, high);
  }
}

/*
 * Sorting based method : This would invole sorting the strings
 * and then comparing the strings to check if they are the same
 */
bool isPerm2(char str1[], char str2[]) {
  /* Sort the two strings first using QuickSort */
  QuickSort(str1, 0, strlen(str1)-1);
  QuickSort(str2, 0, strlen(str2)-1);

  /* Now compare the strings element by element */
  char *str1p = str1;
  char *str2p = str2;

  while(*str1p) {
    if(*str1p != *str2p)
      return false;
    str1p++;
    str2p++;
  }
  /* Reached here! Should be true ! */
  return true;
}

/* Keep a count array to keep a track of characters visited
 * and take a call if the char count is same to judge perms
 */
bool isPerm(char str1[], char str2[]){
  int countArr[256] = {0};
  char *strp = str1;
  int i = 0;

  /* If lenghts aren't same, can't be perms */
  if(strlen(str1) != strlen(str2))
    return false;

  /* Populate the array */
  while(*strp) {
    countArr[*strp]++;
    strp++;
  }

  /*Get to the second array */
  strp = str2;
  while(*strp) {
    countArr[*strp]--;
    strp++;
  }

  /* Loop over to check if anything is non zero */
  for(i=0;i<256;i++) {
    if(countArr[i] != 0)
      return false;
  }

  /*Made it through should be a permutation */
  return true;
}

int main() {
  char str1[20], str2[20];

  while(true) {
    printf("Enter the strings\n");
    scanf("%s", str1);
    scanf("%s", str2);

    if(isPerm2(str1, str2))
      printf("They are permutations\n");
    else
      printf("They are not permutations\n");
  }

  return 0;
}
