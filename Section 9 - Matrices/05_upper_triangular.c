#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int * A;
    int n;
};

int row_major(int i, int j, int n) {
        return (i * (2 * n - i - 1)) / 2 + j;
    }

int col_major(int i, int j) {
    return (j * (j + 1)) / 2 + i;
}

void rm_set(struct Matrix * M, int i, int j, int el) {
    if (i <= j) {
        M->A[row_major(i, j, M->n)] = el;
    }
}

int rm_get(struct Matrix M, int i, int j) {
    if (i <= j) {
        return M.A[row_major(i, j, M.n)];
    }
    else {
        return 0;
    }
}

void rm_display(struct Matrix M) {
    int i, j;
    for (i = 0; i < M.n; i++) {
        for (j = 0; j < M.n; j++) {
            if (i <= j) {
                printf("%d ", M.A[row_major(i, j, M.n)]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void cm_set(struct Matrix * M, int i, int j, int el) {
    if (i <= j) {
        M->A[col_major(i, j)] = el;
    }
}

int cm_get(struct Matrix M, int i, int j) {
    if (i <= j) {
        return M.A[col_major(i, j)];
    }
    else {
        return 0;
    }
}

void cm_display(struct Matrix M) {
    int i, j;
    for (i = 0; i < M.n; i++) {
        for (j = 0; j < M.n; j++) {
            if (i <= j) {
                printf("%d ", M.A[col_major(i, j)]);
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
    M.n = 5;
    M.A = (int *) malloc(((M.n * (M.n - 1)) / 2) * sizeof(int));
    for (int i = 0; i < M.n; i++) {
        for (int j = 0; j < M.n; j++) {
            cm_set(&M, i, j, 1 + i + j);
        }
    }
    cm_display(M);
    free(M.A);
    return 0;
}