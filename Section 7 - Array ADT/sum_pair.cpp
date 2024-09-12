#include <iostream>
using namespace std;

int main() {
    int A[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    int i, j, n = sizeof(A)/sizeof(*A);
    // for (i = 0; i < n - 1; i++) {
    //     j = i + 1;
    //     while (j < n) {
    //         if (A[i] + A[j] == 10) {
    //             cout<<A[i]<<" + "<<A[j]<<" = "<<10<<endl;
    //         }
    //         j++;
    //     }
    // }
    int min_val, max_val;
    min_val = max_val = A[0];
    for (i = 0; i < n; i++) {
        if (A[i] < min_val) {
            min_val = A[i];
        }
        else if (A[i] > max_val) {
            max_val = A[i];
        }
    }
    int h_size = max_val + 1;
    int * H;
    H = new int[h_size];
    for (i = 0; i < h_size; i++) {
        H[i] = 0;
    }
    int target = 10;
    // for (i = 0; i < n; i++) {
    //     if (H[target - A[i]]) {
    //         cout<<A[i]<<" + "<<10 - A[i]<<" = 10\n";
    //     }
    //     H[A[i]]++;
    // }
    i = 0, j = n - 1;
    while (i < j) {
        if (A[i] + A[j] == target) {
            cout<<A[i]<<" + "<<A[j]<<" = 10\n";
            i++;
            j--;
        }
        else if (A[i] + A[j] > target) {
            j--;
        }
        else {
            i++;
        }
    } 
    delete []H;
    return 0;
}