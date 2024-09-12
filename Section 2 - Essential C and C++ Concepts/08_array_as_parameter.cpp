#include <iostream>
#include <unistd.h>
#include <stdio.h>
using namespace std;

// void fill_arr(int arr[], int len) {
//     srand(time(0));
//     for (int i = 0; i < len; i++) {
//         int r = rand() % 10;
//         arr[i] = r;
//     }
// }

void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (len == 1) {
            printf("[%d]\n", arr[i]);
        }
        else {
            if (i == 0) {
                printf("[%d, ", arr[i]);
            }
            else if (i > 0 && i < len - 1) {
                printf("%d, ", arr[i]);
            }
            else if (i == len - 1) {
                printf("%d]\n", arr[i]);
            }
        }
    }
}

// int main() {
//     int n;
//     printf("Enter array length: ");
//     scanf("%d", &n);
//     int arr_1[n];
//     fill_arr(arr_1, n);
//     print_arr(arr_1, n);
//     return 0;
// }

// void fun(int *A, int n) {
//     A[0] = 25;
//     // for (int i = 0; i < n; i++) {
//     //     printf("%d\n", A[i]);
//     // }
// }

// int main() {
//     int A[5] = {2, 4, 6, 8, 10};
//     fun(A, 5);
//     for (int i = 0; i < 5; i++) {
//         printf("%d\n", A[i]);
//     }
//     return 0;
// }

// int * fun(int n) {
//     int *p;
//     p = new int[5];
//     for (int i = 0; i < n; i++) {
//         p[i] = 0;
//     }
//     return(p);
// }

// int main() {
//     int * A; 
//     int * B;
//     int len = 10;
//     A = fun(len);
//     B = fun(len);
//     B[1] = 1;
//     print_arr(A, len);
//     return 0;
// }

// Call by address
// void fun(int *arr, int len) {
//     for (int i = 0; i < len; i++) {
//         cout<<arr[i]<<endl;
//     }
// }

// int main() {
//     int A[] = {2, 4, 6, 8, 10};
//     int n = 5;
//     fun(A, n);
//     return 0;
// }

int * fun(int len) {
    int *p;
    p = (int *)malloc(len*sizeof(int));
    for (int i = 0; i < len; i++) {
        p[i] = i + 1;
    }
    return p;
}

int main() {
    int A[] = {2, 4, 6, 8, 10};
    int n = 5;
    int *B = fun(n);
    for (int i = 0; i < n; i++) {
        cout<<B[i]<<endl;
    }
    return 0;
}