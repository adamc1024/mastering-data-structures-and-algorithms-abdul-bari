#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term {
    int coeff;
    int exp;
};

struct Poly {
    int n;
    int x;
    struct Term * T;
};

void read(struct Poly * P) {
    int i;
    printf("Enter amount of non-zero terms: ");
    scanf("%d", &P->n);
    P->T = (struct Term *) malloc(P->n * sizeof(struct Term));
    for (i = 0; i < P->n; i++) {
        printf("Term %d (coefficient, exponent): ", i + 1);
        scanf("%d%d", &P->T[i].coeff, &P->T[i].exp);
    }
}

void display(struct Poly P) {
    int i, coeff, exp;
    printf("f(x) = ");
    for (i = 0; i < P.n; i++) {
        coeff = P.T[i].coeff >= 0 ? P.T[i].coeff : P.T[i].coeff * -1;
        exp = P.T[i].exp;
        if (i == 0 && P.T[i].coeff < 0) {
            printf("-");
        }
        if (i > 0) {
            if (P.T[i].coeff > 0) {
                printf(" + ");
            }
            else {
                printf(" - ");
            }
        }
        if (coeff > 1 || coeff == 1 && exp == 0) {
            printf("%d", coeff);
        }
        if (exp == 1) {
            printf("x");
        }
        if (exp < 0 || exp > 1) {
            printf("x^%d", exp);
        }
        if (i == P.n - 1) {
            printf("\n");
        }
    }
}

float evaluate(struct Poly P) {
    printf("Enter x: ");
    scanf("%d", &P.x);
    float result = 0, temp;
    int exp, i;
    for (i = 0; i < P.n; i++) {
        exp = P.T[i].exp >= 0 ? P.T[i].exp : P.T[i].exp * -1;
        temp = pow(P.x, exp);
        if (P.T[i].exp < 0) {
            temp = 1/temp;
        }
        result += P.T[i].coeff * temp;
        printf("%d x %.2f = %.2f\n", P.T[i].coeff, temp, P.T[i].coeff * temp);
    }
    printf("f(x) = %.2f\n", result);
    return result;
}

struct Poly add_poly(struct Poly P1, struct Poly P2) {
    struct Poly P3;
    P3.T = (struct Term *) malloc(P1.n + P2.n * sizeof(struct Term));
    int i, j, k;
    i = j = k = 0;
    while (i < P1.n || j < P2.n) {
        if (P1.T[i].exp == P2.T[j].exp) {
            P3.T[k].coeff = P1.T[i].coeff + P2.T[j].coeff;
            P3.T[k].exp = P1.T[i].exp;
            i++;
            j++;
            k++;
        }
        else if (P1.T[i].exp > P2.T[j].exp) {
            P3.T[k] = P1.T[i];
            i++;
            k++;
        }
        else if (P1.T[i].exp < P2.T[j].exp) {
            P3.T[k] = P2.T[j];
            j++;
            k++;
        }
        else if (i < P1.n && j == P2.n) {
            P3.T[k] = P2.T[i];
            i++;
            k++;
        } 
        else if (i == P1.n && j < P2.n) {
            P3.T[k] = P2.T[j];
            j++;
            k++;
        }
    }
    P3.n = k;
    printf("%d\n",k);
    return P3;
}

int main() {
    struct Poly P1, P2;
    printf("P1\n");
    read(&P1);
    display(P1);
    evaluate(P1);
    printf("P2\n");
    read(&P2);
    display(P2);
    evaluate(P2);
    printf("P3\n");
    struct Poly P3 = add_poly(P1, P2);
    evaluate(P3);
    display(P3);
    free(P1.T);
    free(P2.T);
    free(P3.T);
    return 0;
} 