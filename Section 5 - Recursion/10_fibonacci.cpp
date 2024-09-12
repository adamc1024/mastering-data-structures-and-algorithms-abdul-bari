#include <iostream>

using namespace std;

int calls = 0;

int fib_1(int n) {
    static int a = 0, b = 1, temp = 0;
    if (n > 1) {
        fib_1(n - 1);
        temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int fib_2(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_2(n - 2) + fib_2(n - 1);
}

int fib_3(int n) {
    int a = 0, b = 1, temp = 0;
    if (n >= 0) {
        if (n == 0) {
            return 0;
        }
        else {
            for (int i = 1; i < n; i++) {
                temp = b;
                b = a + b;
                a = temp;
            }
            return b;
        }
    }
    return -1;
}


//Memoization
int F[10];
int fib_4(int n) {
    calls++;
    if  (n <= 1) {
        F[n] = n;
        return n;
    }
    else {
        if (F[n - 2] == -1) {
            F[n - 2] = fib_4(n - 2);
        }
        if (F[n - 1] == -1) {
            F[n - 1] = fib_4(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        F[i] = -1;
    }
    cout<<fib_4(10)<<endl<<"calls: "<<calls<<endl;
    for (int i = 0; i < 10; i++) {
        cout<<F[i]<<endl;
    }
    return 0;
}