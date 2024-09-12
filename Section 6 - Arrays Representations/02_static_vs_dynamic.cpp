#include <iostream>

using namespace std;

int main() {
    
    // Stack
    int A[5] = {2, 4, 6, 8, 10};
    
    // Heap

    // declare pointer
    int *P;

    // memory allocation
    // clang
    // P = (int *)malloc(5 * sizeof(int));
    // c++
    P = new int[5];

    P[0] = 3;
    P[1] = 5;
    P[2] = 7;
    P[3] = 9;
    P[4] = 11;

    for (int i = 0; i < 5; i++) {
        cout<<A[i]<<endl;
    }

    cout<<'\n';

    for (int i = 0; i < 5; i++) {
        cout<<P[i]<<endl;
    }

    // memory deallocation
    // clang
    // free(P);
    // c++
    delete []P;
    
    return 0;
}