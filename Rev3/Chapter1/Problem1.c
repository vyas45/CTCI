/*
 * Check if the string has all unique characters
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//Swapper
void swap(char* x, char *y) {
  char temp = *x;
  *x = *y;
  *y = temp;
}

//Partition Method
int Partition(char* str, int low, int high) {
  int i, j;
  char pivot = *(str+high); //Choose pivot as the last element
  i = low-1;
  for(j=low; j<high; j++) {
    if(*(str+j) <= pivot) {
      i++;
      swap((str+i), (str+j));
    }
  }
  swap((str+i+1), (str+high));
  return(i+1);
}

//QuickSort Recursion
void QuickSort(char* str, int low, int high) {
  if(low<high) {
    int pi = 0;
    pi = Partition(str, low, high);
    QuickSort(str, low, pi-1);
    QuickSort(str, pi+1, high);
  }
}

/*
 * First Sort the string and then
 * walk over the string to check if
 * everything is unique
 */
bool isUnique2(char *str) {
  char* curr;
  int len = strlen(str);

  //Sort the string
  QuickSort(str, 0, len-1);

  curr = str;

  while(*curr && *(curr+1)) {
    if(*curr == *(curr+1))
      return false; //Repeat found
    curr++;
  }
  return true; //All good
}

bool isUnique1(char* str) {
  int countArr[256] = {0};
  int i = 0;
  while(*str) {
    if(countArr[*str] > 0)
      return false; //Saw something from earlier
    countArr[*str]++;
    str++;
  }
  return true; //All good
}

int main() {
  char *str;
  str = malloc(sizeof(char) * 20);

  while(1) {
    printf("Enter the string to check for\n");
    scanf("%s", str);

    //Unique method
    if(isUnique2(str))
      printf("String has unique characters\n");
    else
      printf("String doesn't have unique characters\n");
  }
  return 0;
}
