#include <iostream>

using namespace std;

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return fact(n - 1) * n;
}

int nCr1(int n, int r) {
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1 / (t2 * t3);
}

int calls = 0; 

int nCr2(int n, int r) {
    calls++;
    if (n == r || r == 0) {
        cout<<n<<"C"<<r<<" = "<<1<<endl;
        return 1;
    }
    int t1 = nCr2(n - 1, r - 1);
    int t2 = nCr2(n - 1, r);
    cout<<n<<"C"<<r<<" = "<<t1+t2<<endl;
    return t1 + t2;
}

int main() {
    // cout<<nCr1(5, 3)<<endl;
    cout<<nCr2(5, 2)<<endl;
    cout<<"Calls: "<<calls<<endl;
    return 0;
}