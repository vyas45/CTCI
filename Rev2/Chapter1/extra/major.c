/*
 * Find the majority element if any in an array
 * A manjority element is something that occurs > n/2 times
 * where n is the number of elements in the array
 * This is caled "Moore's Voting Algorithm"
 */
#include <stdio.h>
#include <stdlib.h>

int* isMajority(int arr[], int size) {
    int *retArr = malloc(sizeof(int) * 2); //allocate the return array
    if(retArr == NULL) {
        printf("Couldn't allocate return array!\n");
        return retArr;
    }
    /* Moore's voting algorithm */
    int max_index = 0;
    int count = 1;
    int i;
    for(i=1; i<size; i++) {
        /* If same element increment count */
        if(arr[max_index] == arr[i]) count++;
        /* else reduce count */
        else count--;
        /* Update the major element if count reaches 0 */
        if(count == 0) {
            max_index = i;
            count = 1;
        }
    }
    /* Check if there exists a major element
     * We know the max_index, check if the max_index
     * count is > n/2
     */
    count = 0;
    int max = arr[max_index];
    for(i=0; i<size; i++) {
        if(arr[i] == max) count++;
    }
    if(count>size/2) {
        /* It is the max element */
        *(retArr) = 1;
        *(retArr+1) = max;
    }
    else {
        /* Not the max element */
        *(retArr) = 0;
        *(retArr+1) = -1;
    }
    return retArr; //Return the retArr
}
/* Check major function */
void checkMajor(int arr[], int size) {
    //We get back a return Array of the form ([1/0, major elemnt])
    int *retArr = isMajority(arr, size);
    if(*retArr) {
        printf("The majoirty element is %d\n", *(retArr+1));
    }
    else {
        printf("The majority element doesn't exist\n");
    }
    free(retArr); //free the return Array
}

int main() {
    int arr[] = {2, 3, 1, 1, 4, 2, 1, 1, 1, 1}; //1 is the majority element 
    int arr2[] = {1, 2, 3, 1, 1, 2, 2}; //There is no majority element
    int size = 0;

    printf("Case 1:\n");
    size = sizeof(arr)/sizeof(int);
    checkMajor(arr, size);

    printf("\nCase 2:\n");
    size = sizeof(arr2)/sizeof(int);
    checkMajor(arr, size);

    return 0;
}

