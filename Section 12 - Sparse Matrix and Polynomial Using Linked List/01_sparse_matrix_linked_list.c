#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int col;
    int val;
    struct Node *next;
};

struct SinglyLinkedList {
    struct Node *head;
    struct Node *tail;
};

void InitSLL(struct SinglyLinkedList *sll) {
    sll->head = NULL;
    sll->tail = NULL;
}

struct Node *CreateNode() {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    return t;
}

void InitNode(struct Node *node, int col, int val, struct Node *next) {
    node->col = col;
    node->val = val;
    node->next = next;
}

void Append(struct SinglyLinkedList *sll, int col, int val) {
    struct Node *t = CreateNode();
    InitNode(t, col, val, NULL);
    if (sll->head == NULL && sll->tail == NULL) {
        sll->head = sll->tail = t;
    }
    else {
        sll->tail->next = t;
        sll->tail = t;
    }
}

int main() {
    int mat_1[4][4] = {{0, 0, 3, 0},
                       {1, 0, 0, 0},
                       {0, 6, 0, 9},
                       {8, 0, 0, 0}};
    int mat_2[4][4] = {{0, 0, 8, 0},
                       {5, 0, 9, 0},
                       {1, 0, 0, 9},
                       {0, 0, 3, 0}};
    struct SinglyLinkedList *sll_mat_1[4], *sll_mat_2[4];
    for (int i = 0; i < 4; i++) {
        sll_mat_1[i] = (struct SinglyLinkedList *) malloc(sizeof(struct SinglyLinkedList));
        sll_mat_2[i] = (struct SinglyLinkedList *) malloc(sizeof(struct SinglyLinkedList));
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mat_1[i][j] != 0) {
                Append(sll_mat_1[i], j, mat_1[i][j]);
            }
            if (mat_2[i][j] != 0) {
                Append(sll_mat_2[i], j, mat_2[i][j]);
            }
        }
    }
    int val;
    for (int i = 0; i < 4; i++) {
        printf("[ ");
        struct Node *p = sll_mat_1[i]->head;
        struct Node *q = sll_mat_2[i]->head;
        for (int j = 0; j < 4; j++) {
            val = 0;
            if (p->col == j) {
                val += p->val;
                if (p->next) {
                    p = p->next;
                }
            }
            if (q->col == j) {
                val += q->val;
                if (q->next) {
                    q = q->next;
                }
            }
            printf("%d ", val);
        }
        printf("]\n");
    }
    return 0;
}