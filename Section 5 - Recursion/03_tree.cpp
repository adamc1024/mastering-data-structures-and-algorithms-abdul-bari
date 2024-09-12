#include <iostream>

using namespace std;

// time complexity O(2^n)
// space complexity O(n)

int call_count = 0;

void fun_1(int n) {
    call_count++;
    if (n > 0) {
        printf("%d\n", n);
        fun_1(n - 1);
        fun_1(n - 1);
    }
}

// output is palindrome
void fun_2(int n) {
    if (n > 0) {
        fun_2(n - 1);
        printf("%d\n", n);
        fun_2(n - 1);
    }
}

void fun_3(int n) {
    if (n > 0) {
        fun_3(n - 1);
        fun_3(n - 1);
        printf("%d\n", n);
    }
}

int main() {
    printf("-------------\n");
    fun_1(3);
    printf("-------------\n");
    fun_2(3);
    printf("-------------\n");
    fun_3(3);
    printf("Call count: %d\n", call_count);
    return 0;
}