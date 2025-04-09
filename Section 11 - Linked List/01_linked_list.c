#include <linkedListClang.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int arr_1[14] = {5, 2, 9, 1, 7, 3, 6, 3, 34, 56, 34, 89, 65, 43};
    LL ll_1 = newLLFromArray(DOUBLY_LINKED, arr_1, 14);
    llDisplay(&ll_1);
    printf("Length: %d\n", llLength(&ll_1));
    printf("Sum: %d\n", llSum(&ll_1));
    printf("Average: %.2f\n", llAverage(&ll_1));
    printf("Min: %d\n", llMin(&ll_1));
    printf("Max: %d\n", llMax(&ll_1));
    llInsert(&ll_1, 3, 25);
    llDisplay(&ll_1);
    printf("Popped element: %d\n", llPop(&ll_1, 7));
    llDisplay(&ll_1);
    printf("Is Sorted Ascending: %d\n", llIsSorted(&ll_1, true));
    llSort(&ll_1, true);
    llDisplay(&ll_1);
    printf("Is Sorted Ascending: %d\n", llIsSorted(&ll_1, true));
    printf("Head: %d\nTail: %d\n", getDataByType(ll_1.head, 
        ll_1.typeLL), getDataByType(ll_1.tail, ll_1.typeLL));
    llSort(&ll_1, false);
    llDisplay(&ll_1);
    printf("Is Sorted Descending: %d\n", llIsSorted(&ll_1, false));
    printf("Head: %d\nTail: %d\n", getDataByType(ll_1.head, 
        ll_1.typeLL), getDataByType(ll_1.tail, ll_1.typeLL));
    llAppend(&ll_1, 5);
    llAppend(&ll_1, 25);
    llDisplay(&ll_1);
    llPrintHeadAndTail(&ll_1);
    llDeleteDuplicates(&ll_1);
    llDisplay(&ll_1);
    llPrintHeadAndTail(&ll_1);
    llReverse(&ll_1);
    llDisplay(&ll_1);
    llPrintHeadAndTail(&ll_1);
    printf("Is Looped: %d\n", llIsLooped(&ll_1));
    int arr_2[3] = {11, 73, 67};
    LL ll_2 = newLLFromArray(DOUBLY_LINKED, arr_2, 3);
    llConcatenate(&ll_1, &ll_2);
    llDisplay(&ll_1);
    llDisplay(&ll_2);
    int arr_3[8] = {1024, 19, 45, 8, 6, 254, 104, 90};
    LL ll_3 = newLLFromArray(DOUBLY_LINKED, arr_3, 8);
    llMerge(&ll_1, &ll_3, true);
    llDisplay(&ll_1);
    llDisplay(&ll_3);
    llDestruct(&ll_1);
    return 0;
}