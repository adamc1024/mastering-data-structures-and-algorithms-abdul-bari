#include <stdio.h>
#include <stdlib.h>

struct Element {
    int i;
    int j;
    int el;
};

struct Sparse {
    int m;
    int n;
    int E_size;
    struct Element * E;
};

void create(struct Sparse * S) {
    int i;
    printf("Enter Dimensions (m x n): ");
    scanf("%d%d", &S->m, &S->n);
    printf("Enter amount of non-zero elements: ");
    scanf("%d", &S->E_size);
    S->E = (struct Element *) malloc(S->E_size * sizeof(struct Element));
    printf("Enter all elements\n");
    for (i = 0; i < S->E_size; i++) {
        printf("Element %d (i j el): ", i);
        scanf("%d%d%d", &S->E[i].i, &S->E[i].j, &S->E[i].el);
    } 
}

void display(struct Sparse S) {
    int i, j, k;
    k = 0;
    for (i = 0; i < S.m; i++) {
        for (j = 0; j < S.n; j++) {
            if (i == S.E[k].i && j == S.E[k].j) {
                printf("%d", S.E[k].el);
                k++;
              }
            else {
                printf("0");
            }
            if (j < S.n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

struct Sparse * sum_of_matrices(struct Sparse S1, struct Sparse S2) {
    int i, j, k;
    i = j = k = 0;
    struct Sparse * sum = (struct Sparse *) malloc(sizeof(struct Sparse));
    if (S1.m != S2.m || S1.n != S2.n) {
        sum->m = 1, sum->n = 1, sum->E_size = 1;
        sum->E = (struct Element *) malloc(1 * sizeof(struct Element));
        sum->E->i = 0, sum->E->j = 0, sum->E->el = -1;
        return sum;
    }
    else {
        sum->m = S1.m, sum->n = S1.n;
        sum->E = (struct Element *) malloc(S1.E_size + S2.E_size * sizeof(struct Element));
        while (i < S1.E_size || j < S2.E_size) {
            if (i < S1.E_size && j < S2.E_size) {
                if (S1.E[i].i < S2.E[j].i) {
                    sum->E[k] = S1.E[i];
                    i++;
                    k++;
                }
                else if (S1.E[i].i > S2.E[j].i) {
                    sum->E[k] = S2.E[j];
                    j++;
                    k++;
                }
                else if (S1.E[i].i == S2.E[j].i && S1.E[i].j < S2.E[j].j) {
                    sum->E[k] = S1.E[i];
                    i++;
                    k++;
                }
                else if (S1.E[i].i == S2.E[j].i && S1.E[i].j > S2.E[j].j) {
                    sum->E[k] = S2.E[j];
                    j++;
                    k++;
                }
                else {
                    sum->E[k] = S1.E[i];
                    sum->E[k].el = S1.E[i].el + S2.E[j].el; 
                    i++;
                    j++;
                    k++;
                }
            }
            else if (i == S1.E_size || j == S2.E_size) {
              sum->E[k] = (i == S1.E_size) ? S2.E[j++] : S1.E[i++];
              k++;
            } 
          }
    }
    return sum;
}

int main() {
    struct Sparse S1, S2, * sum;

    printf("--------\nMatrix 1\n--------\n");
    create(&S1);
    printf("--------\nMatrix 2\n--------\n");
    create(&S2);

    // S1.m = 2, S1.n = 2, S1.E_size = 2;
    // S1.E = (struct Element *) malloc(S1.E_size * sizeof(struct Element)); 
    // S1.E[0].i = 0, S1.E[0].j = 0, S1.E[0].el = 1;
    // S1.E[1].i = 1, S1.E[1].j = 1, S1.E[1].el = 1;

    // S2.m = 2, S2.n = 2, S2.E_size = 2;
    // S2.E = (struct Element *) malloc(S2.E_size * sizeof(struct Element)); 
    // S2.E[0].i = 0, S2.E[0].j = 0, S2.E[0].el = 1;
    // S2.E[1].i = 1, S2.E[1].j = 0, S2.E[1].el = 1;

    sum = sum_of_matrices(S1, S2);
    
    printf("--------\nMatrix 1\n--------\n");
    display(S1);
    printf("--------\nMatrix 2\n--------\n");
    display(S2);
    printf("--------\n");
    printf("Sum of Matrices 1 and 2\n");
    printf("--------\n");
    display(*sum);

    free(S1.E);
    free(S2.E);
    free(sum->E);
    free(sum);

    return 0;
}