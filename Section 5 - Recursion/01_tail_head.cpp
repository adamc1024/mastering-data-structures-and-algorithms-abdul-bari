#include <iostream>
#include <stdio.h>

using namespace std;

// tail function
void fun_1(int n) {
    if (n > 0) {
        printf("%d\n", n);
        fun_1(n - 1);
    }
}

// head function
void fun_2(int n) {
    if (n > 0) {
        fun_2(n - 1);
        printf("%d\n", n);
    }
}

int main() {
    int x = 3;
    printf("fun_1 -> tail function\noutput\n");
    fun_1(x);
    printf("fun_2 -> head function\noutput\n");
    fun_2(x);
    return 0;
}
