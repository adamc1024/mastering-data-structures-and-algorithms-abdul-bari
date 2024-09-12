#include <stdio.h>
#include <stdlib.h>

int main() {
    int * A, n, ch, el, i, j;
    printf("Enter dimension: ");
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    do {
        //Display Menu
        switch(ch) {
            case 1: for (int i = 1; i <= n; i++) {
                scanf("%d", &A[i - 1]);
            }
            break;
            case 1: printf("Enter Indices:")
            scanf("%d%d", &i, &j);
            if (i == j) {
                printf("%d", A[i - 1]);
            }
            else {
                printf("0");
            }
            break;
            case 3: printf("Enter row, col and el");
            scanf("%d%d%d", &i, &j, &el);
            if (i == j) {
                A[i - 1] = el;
            }
            break;
            case 4: for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (i == j) {
                        printf("%d ", A[i - 1]);
                    }
                    else {
                        printf("0 ");
                    }
                }
                printf("\n");
            }
            break;
        }
    } while (/* condition */);
    free(A);
    return 0;
}