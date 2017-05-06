/*
 * Check if a string has unique characters
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * Maintain a sort-of hash table
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 */
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

void swap(char* x, char* y) {
    char temp = *x;
    *x  = *y;
    *y = temp;
}

/*
 * What if we cannot use extra memory ?
 * Quick Sort -> In place 
 * And then O(n) to go through
 * O(nlogn) + O(n) = O(nlogn)
 */
int Partition(char arr[], int low, int high) {
    int  i = low-1;
    int j;

    int pivot = arr[high];

    for(j=low; j<=high-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return(i+1);
}

void QuickSort(char arr[], int low, int high) {
    int pi = 0;
    if(low<high) {
        pi = Partition(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}

/* String printer */
void printer(char str[], int len) {
    printf("Printing the string\n");
    char *strp = str;
    while(*str) {
        printf("%c", *str);
        str++;
    }
    printf("\n");
}

/* isUnique2 on a sorted string */
bool isUnique2(char str[]) {
    char *slow = str;
    char *fast = str;

    while(*slow && *fast && *(fast+1)) {
        fast = slow+1;
        if(*slow == *fast)
            return false;
        slow++;
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

        /* Sorting method */
        int len = strlen(str);
        QuickSort(str, 0, len-1);

        printer(str, len);

         if(isUnique2(str))
            printf("The string has unique characters\n");
        else
            printf("The string has repeating characters\n");


    }

    return 0;
}
