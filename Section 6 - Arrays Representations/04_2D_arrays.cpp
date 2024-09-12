#include <iostream>

using namespace std;

void print_2D_arr(int **arr, int i, int j) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (j < 3) {
                cout<<arr[i][j]<<' ';
            }
            else {
                cout<<arr[i][j]<<endl;
            }
        }
    }
}

int main() {
    
    int **A = new int *[3];
    
    for (int i = 0; i < 3; i++) {
        A[i] = new int[4];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            A[i][j] = i * j;
        }
    } 

    print_2D_arr(A, 3, 4);

    for (int i = 0; i < 3; i++) {
        delete []A[i];
    }
    
    delete []A;

    return 0;
}