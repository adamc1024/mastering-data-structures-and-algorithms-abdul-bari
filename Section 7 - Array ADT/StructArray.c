#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array *arr) {
    int i;
    printf("Elements are\n");
    for (i = 0; i < arr->length; i++) {
        if (i == arr->length - 1) {
            printf("%d\n", arr->A[i]);
        }
        else {
            printf("%d ", arr->A[i]);
        }

    }
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void Insert(struct Array *arr, int index, int x) {
    if (arr->length < arr->size) {
        if (index >= 0 && index <= arr->length && index < arr->size) {
            for (int i = arr->length; i > index; i--) {
                arr->A[i] = arr->A[i - 1];
            }
            arr->A[index] = x;
            arr->length++;
        }
    }
}

int Delete(struct Array *arr, int index) {
    int x;
    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (int i = index; i < arr->length-1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            // if (i > 0) {
            //     // Transposition
            //     swap(&arr->A[i], &arr->A[i - 1]);
            //     // // Move to head
            //     // swap(&arr->A[i], &arr->A[0]);
            // }
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key) {
    int l, m, h;
    l = 0;
    h = arr.length;
    while (l <= h) {
        m = (l + h) / 2;
        if (key == arr.A[m]) {
            return m;
        }
        else if (key < arr.A[m]) {
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

int RBinarySearch(int arr[], int l, int h, int key) {
    int m;
    if (l <= h) {
        m = (l + h) / 2;
        if (key == arr[m]) {
            return m;
        }
        else if (key < arr[m]) {
            return RBinarySearch(arr, l, m - 1, key);
        }
        else {
            return RBinarySearch(arr, m + 1, h, key);
        }
    }
    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)  {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length)  {
        arr->A[index] = x;
    }
}

int Max(struct Array arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr) {
    int sum = 0;
    for (int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
    }
    return sum;
}

int RSum(int arr[], int n) {
    if (n < 0) {
        return 0;
    }
    else {
        return RSum(arr, n - 1) + arr[n];
    }
}

float Avg(struct Array arr) {
    return (float) Sum(arr) / arr.length;
}

void Reverse(struct Array *arr) {
    for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void Shift(struct Array *arr, bool shiftedLeft) {
    if (shiftedLeft) {
        for (int i = 0; i < arr->length; i++) {
            if (i < arr->length - 1) {
                arr->A[i] = arr->A[i + 1];
            }
            else {
                arr->A[i] = 0;
            }
        }
    }
    else if (! shiftedLeft) {
        for (int i = arr->length - 1; i >= 0; i--) {
            if (i > 0) {
                arr->A[i] = arr->A[i - 1];
            }
            else {
                arr->A[i] = 0;
            }
        }
    }
}

void Rotate(struct Array *arr, bool shiftedLeft) {
    int head = arr->A[0];
    int tail = arr->A[arr->length - 1];
    Shift(arr, shiftedLeft);
    if (shiftedLeft) {
        arr->A[arr->length - 1] = head;
    }
    else if (! shiftedLeft) {
        arr->A[0] = tail;  
    }
}

bool isSorted(struct Array *arr) {
    bool isAscending = arr->A[0] < arr->A[arr->length - 1]; 
    for (int i = 0; i < arr->length - 1; i++) {
        if (isAscending) {
            if (arr->A[i] > arr->A[i + 1]) {
                return false;
            }
        }
        else if (! isAscending) {
            if (arr->A[i] < arr->A[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

void Sort(struct Array *arr, bool ascending) {
    int count;
    while (count < arr->length - 1) {
        Display(arr);
        count = 0;
        for (int i = 0; i < arr->length - 1; i++) {
            if (ascending) {
                if (arr->A[i] > arr->A[i + 1]) {
                    swap(&arr->A[i], &arr->A[i + 1]);
                }
                else {
                    count++;
                }
            }
            else if (! ascending) {
                if (arr->A[i] < arr->A[i + 1]) {
                    swap(&arr->A[i], &arr->A[i + 1]);
                }
                else {
                    count++;
                }
            }
        }
    }
}

void SortedInsert(struct Array *arr, int x) {
    bool ascending;
    if (isSorted(arr) && arr->length < arr->size) {
        ascending = arr->A[0] < arr->A[1];
        for (int i = arr->length; i >= 0; i--) {
            if (i > 0) {
                if (x >= arr->A[i - 1] && ascending || x <= arr->A[i - 1] && ! ascending) {
                    arr->A[i] = x;
                    break;
                }
                else {
                    arr->A[i] = arr->A[i - 1]; 
                }
            }
            else {
                arr->A[i] = x;
            }
        }
        arr->length++;
    }
    else {
        return;
    }
}

void NegativePositive(struct Array *arr) {
    int i = 0;
    int j = arr->length - 1;
    while (i < j) {
        while (arr->A[i] < 0 && i < j) {
            i++;
        }
        while (arr->A[j] >= 0 && i < j) {
            j--;
        }
        swap(&arr->A[i], &arr->A[j]);
    } 
}

// void Merge(int *arr1, int *arr2, int *arr3, int m, int n) {
//     int i = 0, j = 0, k = 0;
//     while (k < m + n) {
//         if (arr1[i] < arr2[j] || j == n) {
//             arr3[k] = arr1[i];
//             i++;
//             k++;
//         }
//         else if (arr1[i] >= arr2[j] || i == m) {
//             arr3[k] = arr2[j];
//             j++;
//             k++;
//         }
//     }
// }

struct Array * Merge(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    while (k < arr1->length + arr2->length) {
        if (arr1->A[i] < arr2->A[j] && i < arr1->length || j == arr2->length) {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if (arr1->A[i] >= arr2->A[j] && j != arr2->length || i == arr1->length) {
            arr3->A[k] = arr2->A[j];
            j++;
            k++;
        }
    }
    return arr3;
}

struct Array * Merge2(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else {
            arr3->A[k] = arr2->A[j];
            j++;
            k++;
        }
    }
    while (i < arr1->length) {
        arr3->A[k] = arr1->A[i];
        i++;
        k++;
    }
    while (j < arr2->length) {
        arr3->A[k] = arr2->A[j];
        j++;
        k++;
    }
    arr3->length = k;
    return arr3;
}

struct Array * Union(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;
    while (i < arr1->length || j < arr2->length) {
        if (arr1->A[i] < arr2->A[j] && i < arr1->length && j < arr2->length || j == arr2->length) {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if (arr1->A[i] > arr2->A[j] && i < arr1->length && j < arr2->length || i == arr1->length) {
            arr3->A[k] = arr2->A[j];
            j++;
            k++;
        }
        else if (arr1->A[i] == arr2->A[j] && i < arr1->length && j < arr2->length) {
            arr3->A[k] = arr2->A[j];
            i++;
            j++;
            k++;
        }
    }
    arr3->length = k;
    return arr3;
}

struct Array * Union2(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if (arr1->A[i] > arr2->A[j]) {
            arr3->A[k] = arr2->A[j];
            j++;
            k++;
        }
        else {
            arr3->A[k] = arr1->A[i];
            i++;
            j++;
            k++;
        }
    }
    while (i < arr1->length) {
        arr3->A[k] = arr1->A[i];
        i++;
        k++;
    }
    while (j < arr2->length) {
        arr3->A[k] = arr2->A[j];
        j++;
        k++;
    }
    arr3->length = k;
    return arr3;
}

struct Array * Intersection(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;
    while (i < arr1->length || j < arr2->length) {
        if (arr1->A[i] == arr2->A[j]) {
            arr3->A[k] = arr1->A[i];
            i++;
            j++;
            k++;
        }
        else if (arr1->A[i] < arr2->A[j] && i < arr1->length || j == arr2->length) {
            i++;
        }
        else if (arr1->A[i] > arr2->A[j] && j < arr2->length || i == arr1->length) {
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

struct Array * Intersection2(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        }
        else if (arr1->A[i] == arr2->A[j]) {
            arr3->A[k] = arr1->A[i];
            i++;
            j++;
            k++;
        }
        else {
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

struct Array * Difference(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;
    while (i < arr1->length || j < arr2->length) {
        if (arr1->A[i] == arr2->A[j]  && i < arr1->length && j < arr2->length) {
            i++;
            j++;
        }
        else if (arr1->A[i] < arr2->A[j]  && i < arr1->length || j == arr2->length) {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if (arr1->A[i] > arr2->A[j] && j < arr2->length || i == arr1->length) {
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

struct Array * Difference2(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = 10;
    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if (arr1->A[i] == arr2->A[j]) {
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    while (i < arr1->length) {
        arr3->A[k] = arr1->A[i];
        k++;
        i++;
    }
    arr3->length = k;
    return arr3;
}

int main() {
    struct Array arr1 = {{1, 6, 9, 10, 11, 15}, 10, 6};
    struct Array arr2 = {{1, 3, 10, 20}, 10, 4};
    struct Array *arr3;
    arr3 = Difference2(&arr1, &arr2);
    Display(arr3);
    printf("%d\n", arr3->length);
    // int B[4] = {1, 3, 6, 9};
    // int C[6] = {0, 2, 5, 7, 8, 10};
    // int D[10] = {0};
    // Merge(&B[0], &C[0], &D[0], 4, 6);
    // for (int i = 0; i < 10; i++) {
    //     printf("%d\n", D[i]);
    // }
    // struct Array arr = {{3, 2, 2, -10, -6}, 10, 5};
    // printf("Append\n");
    // Append(&arr, 9);
    // Display(&arr);
    // printf("Insert\n");
    // Insert(&arr, 5, -5);
    // Display(&arr);
    // printf("Set\n");
    // Set(&arr, 2, 89);
    // Display(&arr);
    // printf("Delete\n");
    // Delete(&arr, 2);
    // Display(&arr);
    // printf("Reverse\n");
    // Reverse(&arr);
    // Display(&arr);
    // printf("Shift\n");
    // Shift(&arr, true);
    // Display(&arr);
    // printf("Rotate\n");
    // Rotate(&arr, true);
    // Display(&arr);
    // printf("Negative Positive\n");
    // NegativePositive(&arr);
    // Display(&arr);
    // printf("Sort\n");
    // Sort(&arr, true);
    // printf("Sorted Insert\n");
    // SortedInsert(&arr, 7);
    // Display(&arr);
    // printf("%d\n", BinarySearch(arr, 6));
    // printf("%d\n", RBinarySearch(arr.A, 0, arr.length - 1, 6));
    // printf("%d\n", Get(arr, 5));
    // printf("Max: %d\n", Max(arr));
    // printf("Min: %d\n", Min(arr));
    // printf("Sum: %d\n", Sum(arr));
    // printf("RSum: %d\n", RSum(arr.A, arr.length - 1));
    // printf("Avg: %.2f\n", Avg(arr));
    return 0;
}