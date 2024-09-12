#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int *p;
    printf("%d\n", (int)sizeof(p));
    p = (int *)malloc(sizeof(int) * 5);
    printf("%d\n", (int)(sizeof(p[0]) * 5));
    delete []p;
    p = NULL;
    if (!p) {
        printf("DELETED\n");
    }
    return 0;
}