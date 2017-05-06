/*
 * Check if a string is permutation of another 
 */
#include <stdio.h>
#include <stdbool.h>


bool isPerm(char* str1, char* str2) {
    int arr[256] = {0};
    while(*str1) {
        arr[*str1]++;
        str1++;
    }
    while(*str2) {
        arr[*str2]--;
        if(arr[*str2] <0)
            return false;
        str2++;
    }
    return true;
}

int main() {
    char *str1 = "Aniket";
    char *str2 = "Aniktei";

    if(isPerm(str1, str2))
        printf("The strings are permutations\n");
    else
        printf("Not permutations\n");

    return 0;
}
