/*
 * Check if a string has unique characters
 */
#include <stdio.h>
#include <stdbool.h>

bool isUnique(char str[]) {
    int arr[256] = {0};
    char* strp = str;

    while(*str) {
        // If we have visited this char before
        if(arr[*str])
            return false;
        arr[*str]++;
        str++;
    }
    return true;
}

int main() {
    char str[20];

    while(1) {
        printf("Enter a string ...\n");
        scanf("%s", str);

        if(isUnique(str))
            printf("The string has unique characters\n");
        else
            printf("The string has repeating characters\n");
    }

    return 0;
}
