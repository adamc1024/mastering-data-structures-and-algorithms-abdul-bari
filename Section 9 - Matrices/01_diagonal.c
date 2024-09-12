#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int A[10];
    int n;
};

void set(struct Matrix * M, int i, int j, int el) {
    if (i == j) {
        M->A[i] = el;
    }
}

int get(struct Matrix * M, int i, int j) {
    if (i == j) {
        return M->A[i];
    }
    else {
        return 0;
    }
}

void display(struct Matrix M) {
    int i, j;
    for (i = 0; i < M.n; i++) {
        for (j = 0; j < M.n; j++) {
            if (i == j) {
                printf("%d ", M.A[i]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Matrix M;
    M.n = 4;
    for (int i = 0; i < M.n; i++) {
        set(&M, i, i, 1 + i * i);
    }
    display(M);
    printf("%d\n", get(&M, 2, 2));
    return 0;
}