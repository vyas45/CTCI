/*
 * Sort a string using QuickSort
 */
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(char str[], int low, int high) {
  char pivot = str[high];
  int i, j = 0;
  i = low-1;
  for(j=low; j<high; j++) {
    if(str[j]<=pivot) {
      i++;
      swap(&str[j], &str[i]);
    }
  }
  swap(&str[i+1], &str[high]);
  return (i+1);
}

void QuickSort(char str[], int low, int high) {
  if(low<high) {
    int pi = Partition(str, low, high);
    QuickSort(str, low, pi-1);
    QuickSort(str, pi+1, high);
  }
}

int main() {
  char str[]="acdbjsl";
  int len = strlen(str);

  QuickSort(str, 0, len-1);

  printf("Sorted string is %s", str);

  return 0;
}
