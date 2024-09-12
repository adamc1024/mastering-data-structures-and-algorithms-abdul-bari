#include <iostream>
using namespace std;

// int missing_element(int *arr, int n) {
//     int result = 0;
//     int tail = arr[n - 1];
//     int tri_num = (tail * (tail + 1)) / 2;
//     for (int i = 0; i < n; i++) {
//         result += arr[i];
//     }
//     return tri_num - result;
// }

int main() {
    // int A[5] = {1, 10, 11, 13, 15};
    // int diff = A[0];
    // int n = sizeof(A)/sizeof(*A);
    // int count = 0;
    // for (int i = 0; i < n; i++) {
    //     if (i > 0 && A[i] - A[i - 1] != 1) {
    //         for (int j = A[i - 1] + 1; j < A[i]; j++) {
    //             cout<<j<<endl;
    //         }
    //     }
    // }

    int i, n, max_val, min_val;
    int A[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    n = sizeof(A)/sizeof(*A);
    max_val = min_val = A[0];
    for (i = 0; i < n; i++) {
        if (A[i] > max_val) {
            max_val = A[i];
        }
        if (A[i] < min_val) {
            min_val = A[i];
        }
    }
    // HASH TABLE/ BITSET
    int * H = new int[max_val + 1];
    
    for (i = 0; i < max_val + 1; i++) {
        H[i] = 0;
        cout<<H[i];
    }
    cout<<'\n';
    for (i = 0; i < n; i++) {
        H[A[i]]++;
    }
    for (i = min_val; i < max_val + 1; i++) {
        if (H[i] == 0) {
            cout<<i<<endl;
        }
    }
    delete []H;
    return 0;
}