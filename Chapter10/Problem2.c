/*
 * Sort an array of characters so that the anagrams are together
 * The idea is that we do the following:
 * Go over the strings one by one , sort the String S to SortedS
 * Now use "SortedS" as the hashtable key and the value is going to be
 * "S". As we walk the original array, collisions would have the anagrams
 * Finally we can populate an array by printing the whole hash table
 * Extra: If the final array needs to be sorted as well, then we need
 * to have an alpahabetical sorting of the final array
 */
#include <stdio.h>
#include <stdbool.h>


