#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    cout<<"Enter Size: ";
    cin>>n;
    int A[n], A_len;
    for (int i = 0; i < n; i++) {
        A[i] = i * i;
        if (i == 0) {
            cout<<"[";
        }
        if (i < n - 1) {
            cout<<A[i]<<", ";
        }
        else {
            cout<<A[i]<<"]"<<endl;
        }
    }
    return 0;
}