#include <iostream>

using namespace std;

int call_count = 0;

int fun(int n) {
    call_count++;
    printf("%d\n", n);
    if (n > 100) {
        return n - 10;
    }
    else {
        return fun(fun(n + 11));
    }
}

int main() {
    printf("%d\n", fun(1));
    printf("Call count: %d\n", call_count);
    return 0;
}