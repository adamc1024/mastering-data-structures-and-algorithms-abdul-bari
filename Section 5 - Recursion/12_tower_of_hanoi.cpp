#include <iostream>

using namespace std;

int step = 0;
int calls = 0;

void toh(int n, int A, int B, int C) {
    calls++;
    if (n > 0) {
        toh(n - 1, A, C, B);
        step++;
        cout<<"Step "<<step<<": from "<<A<<" to "<<C<<endl;
        toh(n - 1, B, A, C);
    }
}

int main() {
    toh(3, 1, 2, 3);
    cout<<calls<<endl;
    return 0;
}