#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int arr_1[6] = {5, 2, 9, 1, 7, 3};
    LL ll_1 = newLLFromArray(2, arr_1, 6);
    llDisplay(ll_1);
    printf("Length: %d\n", llLength(ll_1));
    printf("Sum: %d\n", llSum(ll_1));
    printf("Average: %.2f\n", llAverage(ll_1));
    printf("Min: %d\n", llMin(ll_1));
    printf("Max: %d\n", llMax(ll_1));
    llInsert(&ll_1, 3, 25);
    llDisplay(ll_1);
    // printf("Popped element: %d\n", llPop(&ll_1, 6));
    // llDisplay(ll_1)
    // llSort(&ll_1, true);
    // llDisplay(ll_1);
    // printf("Sorted ascending: %d\n", llIsSorted(ll_1, true));
    // llSort(&ll_1, false);
    // llDisplay(ll_1);
    // printf("Sorted descending: %d\n", llIsSorted(ll_1, false));
    // llAppend(&ll_1, 5);
    // llAppend(&ll_1, 25);
    // llDisplay(ll_1);
    // llDeleteDuplicates(&ll_1);
    // llDisplay(ll_1);
    // llReverse(&ll_1);
    // llDisplay(ll_1);
    // int arr_2[3] = {9, 3, 67};
    // LL ll_2 = newllFromArray(arr_2, 3);
    // llConcatenate(&ll_1, &ll_2);
    // llDisplay(ll_1);
    // llDisplay(ll_2);
    // int arr_3[8] = {3, 19, 45, 8, 5, 2, 1, 90};
    // LL ll_3 = newllFromArray(arr_3, 8);
    // llMerge(&ll_1, &ll_3, true);
    // llDisplay(ll_1);
    // llDisplay(ll_3);
    llDestruct(&ll_1);
    return 0;
}