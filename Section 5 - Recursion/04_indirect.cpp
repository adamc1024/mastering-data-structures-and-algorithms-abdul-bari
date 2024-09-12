#include <iostream>

using namespace std;

void fun_B(int n);
int call_count = 0;

void fun_A(int n) {
    call_count++;
    if (n > 0) {
        printf("%d\n", n);
        fun_B(n - 1);
    }
}

void fun_B(int n) {
    call_count++;
    if (n > 0) {
        printf("%d\n", n);
        fun_A(n/2);
    }
}

int main() {
    fun_A(20);
    printf("Call count: %d\n", call_count);
    return 0;
}