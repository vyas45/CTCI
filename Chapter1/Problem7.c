#include <stdio.h>

void printer(int arr[][3]) {
  int i = 0;
  int j = 0;

  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      printf("%d  ", arr[i][j]);
    }
    printf("\n");
  }
}

void rotate2d(int arr[][3]) {
  int i = 0;
  int j = 0;

  for(i=0; i<3; i++) {
   for(j=0; j<3; j++){ 
      arr[i][j] = arr[2-j][i];
    }
  }
  printer(arr);
}

int main() {
  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  printer(arr);
  printf("\n");
  rotate2d(arr);

  return 0;
}
