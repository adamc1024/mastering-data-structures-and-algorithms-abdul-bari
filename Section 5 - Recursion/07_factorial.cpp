#include <iostream>

using namespace std;

int factorial_1(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n < 0) {
        return -1;
    }
    else {
        return factorial_1(n - 1) * n;
    }
}

int factorial_2(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return -1;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int factorial_3(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return -1;
    }
    int result = 1;
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

int main() {
    printf("%d\n", factorial_1(10));
    printf("%d\n", factorial_2(9));
    printf("%d\n", factorial_3(8));
    return 0;
}