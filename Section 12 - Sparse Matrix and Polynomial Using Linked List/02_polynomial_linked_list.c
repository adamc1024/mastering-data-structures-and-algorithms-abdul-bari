#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *CreateNode() {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    return t;
}

void InitNode(struct Node *t, int coeff, int exp) {
    t->coeff = coeff;
    t->exp = exp;
    t->next = NULL;
}

struct SinglyLinkedList {
    struct Node *head;
    struct Node *tail;
};

void InitSinglyLinkedList(struct SinglyLinkedList *sll) {
    sll->head = NULL;
    sll->tail = NULL;
}

void Destruct(struct SinglyLinkedList *sll) {
    struct Node *p = sll->head;
    struct Node *q;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
}

void Append(struct SinglyLinkedList *sll, int coeff, int exp) {
    struct Node *t = CreateNode();
    InitNode(t, coeff, exp);
    if (sll->head == NULL && sll->tail == NULL) {
        sll->head = sll->tail = t;
    }
    else {
        sll->tail->next = t;
        sll->tail = t;
    }
}

void ArrayToSLL(struct SinglyLinkedList *sll, int arr[][2], int m) {
    int coeff, exp;
    for (int i = 0; i < m; i++) {
        coeff = arr[i][0];
        exp = arr[i][1];
        Append(sll, coeff, exp);
    }
}

int Power(int x, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= x;
    }
    return result;
}

void Term(int coeff, int exp) {
    if (coeff == 1 && exp != 0) {
        printf("x^%d", exp);
    }
    else if (exp == 0) {
        printf("%d", coeff);
    }
    else if (exp == 1) {
        printf("%dx", coeff);
    }
    else {
        printf("%dx^%d", coeff, exp);
    }
}

void Display(struct SinglyLinkedList sll) {
    struct Node *p = sll.head;
    Term(p->coeff, p->exp);
    p = p->next;
    while (p) {
        if (p->coeff < 0) {
            printf(" - ");
            Term(p->coeff * -1, p->exp);
        }
        else {
            printf(" + ");
            Term(p->coeff, p->exp);
        }
        p = p->next;
    }
    printf("\n");
}

int Evaluate(struct SinglyLinkedList sll, int x) {
    struct Node *p = sll.head;
    int result = 0;
    while (p) {
        result += p->coeff * (Power(x, p->exp));
        p = p->next;
    }
    return result;
}

struct SinglyLinkedList Combine(struct SinglyLinkedList sll_1, struct SinglyLinkedList sll_2) {
    struct SinglyLinkedList sll_3;
    InitSinglyLinkedList(&sll_3);
    sll_3.head = sll_1.head;
    sll_1.tail->next = sll_2.head;
    sll_3.tail = sll_2.tail;
    return sll_3;
}

bool isSorted(struct SinglyLinkedList *sll, bool ascending) {
    struct Node *p = sll->head;
    int exp;
    while (p->next) {
        exp = p->exp;
        p = p->next;
        if (ascending && exp > p->exp) {
            break;
        }
        if (!ascending && exp < p->exp) {
            break;
        }
    }
    if (p->next == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void Sort(struct SinglyLinkedList *sll, bool ascending) {
    struct Node *p, *q, *r;
    while (!isSorted(sll, ascending)) {
        q = sll->head;
        r = q->next;
        p = NULL;
        while (r) {
            if ((ascending && q->exp > r->exp) || (!ascending && q->exp < r->exp)) {
                q->next = r->next;
                r->next = q;
                if (q == sll->head) {
                    sll->head = r;
                }
                if (r == sll->tail) {
                    sll->tail = q;
                }
                if (p) {
                    p->next = r;
                }
                p = r;
                r = q;
                q = p;
                q = q->next;
                r = r->next;
            }
            else {
                p = q;
                q = r;
                r = r->next;
            }
        }
    }
}

void Simplify(struct SinglyLinkedList *sll, bool ascending) {
    if (isSorted(sll, ascending)) {
        struct Node *p, *q;
        p = sll->head;
        q = p->next;
        while (q) {
            if (p->exp == q->exp) {
                p->coeff += q->coeff;
                p->next = q->next;
                free(q);
                q = p->next;
            }
            else {
                p = p->next;
                q = q->next;
            }
        }
    }
}

int main() {
    struct SinglyLinkedList sll_1, sll_2;
    InitSinglyLinkedList(&sll_1);
    InitSinglyLinkedList(&sll_2);
    int arr_1[3][2] = {{3, 4},
                      {4, 3},
                      {2, 1}};
    int arr_2[4][2] = {{1, 5},
                      {-3, 3},
                      {8, 0},
                      {1, 2}};
    int x = 2;
    ArrayToSLL(&sll_1, arr_1, 3);
    ArrayToSLL(&sll_2, arr_2, 4);
    printf("x = %d\nf(x) = ", x);
    Display(sll_1);
    printf("%d\n", Evaluate(sll_1, x));
    printf("x = %d\nf(x) = ", x);
    Display(sll_2);
    printf("%d\n", Evaluate(sll_2, x));
    struct SinglyLinkedList sll_3 = Combine(sll_1, sll_2);
    Sort(&sll_3, false);
    Simplify(&sll_3, false);
    printf("x = %d\nf(x) = ", x);
    Display(sll_3);
    printf("%d\n", Evaluate(sll_3, x));
    Destruct(&sll_3);
    return 0;
}