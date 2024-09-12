#include <iostream>
using namespace std;

int main() {
    int A[10] = {3, 6, 8, 6, 12, 15, 15, 8, 15, 6};
    int i = 0, j, n = sizeof(A)/sizeof(*A);
    // while (i < n - 1) {
    //     if (A[i] == A[i + 1]) {
    //         j = i + 1;
    //         while (A[i] == A[j]) {
    //             j++;
    //         }
    //         cout<<A[i]<<" appears "<<j - i<<" times\n";
    //         i = j - 1;
    //     }
    //     else {
    //         i++;
    //     }
    // }
    int max_val, min_val;
    max_val = min_val = A[0]; 
    for (i = 0; i < n; i ++) {
        if (A[i] < min_val) {
            min_val = A[i];
        }
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }
    int m = max_val + 1;
    int * H = new int[m];
    for (i = 0; i < m; i ++) {
        H[i] = 0;
    }
    for (i = 0; i < n; i ++) {
        H[A[i]]++;
    }
    for (i = min_val; i < m; i ++) {
        if (H[i] > 1) {
            cout<<i<<" appears "<<H[i]<<" times\n";
        }
    }
    delete []H;
    return 0;
}