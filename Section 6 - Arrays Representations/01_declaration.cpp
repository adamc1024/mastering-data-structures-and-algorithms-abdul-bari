#include <iostream>

using namespace std;

void print_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            cout<<arr[i]<<", ";
        }
        else {
            cout<<arr[i]<<endl;
        }
    }
}

void print_arr_address(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            cout<<&arr[i]<<", ";
        }
        else {
            cout<<&arr[i]<<endl;
        }
    }
}

int main() {
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int C[5] = {2, 4, 6};
    int D[5] = {0};
    int E[] = {1, 2, 3, 4, 5, 6};
    print_arr(&*A, 5);
    print_arr_address(&*A, 5);
    print_arr(&*B, 5);
    print_arr_address(&*B, 5);
    print_arr(&*C, 5);
    print_arr_address(&*C, 5);
    print_arr(&*D, 5);
    print_arr_address(&*D, 5);
    print_arr(&*E, 6);
    print_arr_address(&*E, 6);
    return 0;
}