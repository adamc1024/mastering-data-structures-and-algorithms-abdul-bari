#include <iostream>

using namespace std;

// generates triangular number
int fun_1(int n) {
    if (n > 0) {
        return fun_1(n - 1) + n;
    }
    return 0;
}

// global variable
// if function called twice
// same variable will be added to
// int x = 0;

int fun_2(int n) {
    // static variable
    // can also be achieved by being
    // declared outside of function
    // if function called twice
    // same variable will be added to
    static int x = 0;
    if (n > 0) {
        x++;
        return fun_2(n - 1) + x;
    }
    return 0;
}

int main() {
    int a = 5;
    printf("%d\n", fun_1(a));
    printf("%d\n", fun_2(a));
    printf("%d\n", fun_2(a));
    return 0;
}