#include <iostream>

using namespace std;

int call_count = 0;

int sum_1(int n) {
    // f(n) = n + 1
    // Time complexity: O(n)
    // Space complexity: O(n)
    call_count++;
    if (n == 0) {
        return 0;
    }
    else {
        return sum_1(n - 1) + n;
    }
}

int sum_2(int n) {
    // Time complexity: O(1)
    // Space complexity: O(1)
    return (n * (n + 1))/2;
}

int sum_3(int n) {
    // Time complexity: O(n)
    // Space complexity: O(1)
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    return result;
}

int sum_4(int n) {
    // Time complexity: O(n)
    // Space complexity: O(1)
    int result = 0;
    int i = 1;
    while (i <= n) {
        result += i;
        i++;
    }
    return result;
}

int main() {
    printf("%d\n", sum_1(6));
    printf("Call count: %d\n", call_count);
    printf("%d\n", sum_2(6));
    printf("%d\n", sum_3(6));
    printf("%d\n", sum_4(6));
    return 0;
}