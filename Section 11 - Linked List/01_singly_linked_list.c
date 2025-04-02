#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int arr_1[6] = {5, 2, 9, 1, 7, 3};
    sll sll_1 = newSLLFromArray(arr_1, 6);
    sllDisplay(sll_1);
    printf("Length: %d\n", sllLength(sll_1));
    printf("Sum: %d\n", sllSum(sll_1));
    printf("Average: %.2f\n", sllAverage(sll_1));
    printf("Min: %d\n", sllMin(sll_1));
    printf("Max: %d\n", sllMax(sll_1));
    sllInsert(&sll_1, 3, 25);
    sllDisplay(sll_1);
    printf("Popped element: %d\n", sllPop(&sll_1, 6));
    sllDisplay(sll_1);
    sllSort(&sll_1, true);
    sllDisplay(sll_1);
    printf("Sorted ascending: %d\n", sllIsSorted(sll_1, true));
    sllSort(&sll_1, false);
    sllDisplay(sll_1);
    printf("Sorted descending: %d\n", sllIsSorted(sll_1, false));
    sllAppend(&sll_1, 5);
    sllAppend(&sll_1, 25);
    sllDisplay(sll_1);
    sllDeleteDuplicates(&sll_1);
    sllDisplay(sll_1);
    sllReverse(&sll_1);
    sllDisplay(sll_1);
    int arr_2[3] = {9, 3, 67};
    sll sll_2 = newSLLFromArray(arr_2, 3);
    sllConcatenate(&sll_1, &sll_2);
    sllDisplay(sll_1);
    sllDisplay(sll_2);
    int arr_3[8] = {3, 19, 45, 8, 5, 2, 1, 90};
    sll sll_3 = newSLLFromArray(arr_3, 8);
    sllMerge(&sll_1, &sll_3, true);
    sllDisplay(sll_1);
    sllDisplay(sll_3);
    sllDestruct(&sll_1);
    return 0;
}