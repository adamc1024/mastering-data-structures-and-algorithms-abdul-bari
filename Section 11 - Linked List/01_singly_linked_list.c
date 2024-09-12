#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
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

void InitNode(struct Node *node, int data, struct Node *next) {
    node->data = data;
    node->next = next;
}

void Append(struct SinglyLinkedList *sll, int data) {
    struct Node *t = CreateNode();
    InitNode(t, data, NULL);
    if (sll->head == NULL && sll->tail == NULL) {
        sll->head = sll->tail = t;
    }
    else {
        sll->tail->next = t;
        sll->tail = t;
    }
}

void CreateSLL(struct SinglyLinkedList *sll, int *arr, int n) {
    InitSLL(sll);
    for (int i = 0; i < n; i++) {
        Append(sll, arr[i]);
    }
}

void Display(struct SinglyLinkedList sll) {
    struct Node *p = sll.head;
    printf("[");
    bool comma = false;
    while (p) {
        if (comma) {
            printf(", ");
        }
        else {
            comma = true;
        }
        printf("%d", p->data);
        p = p->next;
    }
    printf("]\n");
}

void Destruct(struct SinglyLinkedList *sll) {
    struct Node *p = sll->head;
    struct Node *q;
    while (p) {
        q = p;
        free(q);
        p = p->next;
    }
}

int Length(struct SinglyLinkedList sll) {
    int result = 0;
    struct Node *p = sll.head;
    while (p) {
        result++;
        p = p->next;
    }
    return result;
}

int Sum(struct SinglyLinkedList sll) {
    int result = 0;
    struct Node *p = sll.head;
    while (p) {
        result += p->data;
        p = p->next;
    }
    return result;
}

float Average(struct SinglyLinkedList sll) {
    return (float) Sum(sll)/Length(sll);
}

int Min(struct SinglyLinkedList sll) {
    struct Node *p = sll.head;
    int result = p->data;
    while (p) {
        if (p->data < result) {
            result = p->data;
        }
        p = p->next;
    }
    return result;
}

int Max(struct SinglyLinkedList sll) {
    struct Node *p = sll.head;
    int result = p->data;
    while (p) {
        if (p->data > result) {
            result = p->data;
        }
        p = p->next;
    }
    return result;
}

void Insert(struct SinglyLinkedList *sll, int pos, int data) {
    struct Node *p = sll->head;
    struct Node *q;
    int n = Length(*sll);
    if (pos == n) {
        Append(sll, data);
    }
    else if (pos >= 0 && pos < n) {
        struct Node *t = CreateNode();
        if (pos == 0) {
            InitNode(t, data, p);
            sll->head = t;
        }
        else {
            for (int i = 0; i < pos; i++) {
                q = p;
                p = p->next;
            }
            InitNode(t, data, p);
            q->next = t;
        }
    }
}

int Pop(struct SinglyLinkedList *sll, int pos) {
    int data, n;
    data = -1;
    n = Length(*sll);
    if (n && pos >= 0 && pos < n) {
        struct Node *p = sll->head;
        if (pos == 0) {
            data = p->data;
            sll->head = p->next;
            free(p);
        }
        else {
            struct Node *q;
            for (int i = 0; i < pos; i++) {
                q = p;
                p = p->next;
            }
            data = p->data;
            q->next = p->next;
            free(p);
            if (pos == n - 1) {
                sll->tail = q;
            }
        }
    }
    return data;
}

bool isSorted(struct SinglyLinkedList sll, bool ascending) {
    struct Node *p = sll.head;
    int data;
    while (p->next) {
        data = p->data;
        p = p->next;
        if (ascending && data > p->data) {
            break;
        }
        if (!ascending && data < p->data) {
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
    while (!isSorted(*sll, ascending)) {
        p = NULL;
        q = sll->head;
        r = q->next;
        while (r) {
            if (ascending && q->data > r->data || !ascending && q->data < r->data) {
                q->next = r->next;
                r->next = q;
                q = r;
                r = q->next;
                if (p) {
                    p->next = q;
                }
                else {
                    sll->head = q;
                }
            }
            p = q;
            q = q->next;
            r = r->next;
        }
    }
    sll->tail = q;
}

void Unique(struct SinglyLinkedList *sll) {
    int max = Max(*sll);
    int min = Min(*sll);
    int n = max - min + 1;
    int H[n];
    for (int i = 0; i < n; i++) {
        H[i] = 0;
    }
    struct Node *p = sll->head;
    struct Node *q;
    while (p) {
        if (H[p->data - min] == 0) {
            H[p->data - min]++;
            q = p;
            p = p->next;
        }
        else if (H[p->data - min] > 0) {
            q->next = p->next;
            free(p);
            p = q->next;
        }
    }
}

void Reverse(struct SinglyLinkedList *sll) {
    struct Node *p, *q, *r;
    p = sll->head;
    q = r = NULL;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    sll->tail = sll->head;
    sll->head = q;
}

bool isLooped(struct SinglyLinkedList sll) {
    struct Node *p, *q;
    p = q = sll.head;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q) {
        return true;
    } 
    else {
        return false;
    }
}

struct SinglyLinkedList *Concatenate(struct SinglyLinkedList *sll_1, struct SinglyLinkedList *sll_2) {
    struct SinglyLinkedList *sll_3 = (struct SinglyLinkedList *) malloc(sizeof(struct SinglyLinkedList));
    sll_1->tail->next = sll_2->head;
    sll_3->head = sll_1->head;
    sll_3->tail = sll_2->tail;
    sll_1->head = sll_1->tail = sll_2->head = sll_2->tail = NULL;
    return sll_3;
}

struct SinglyLinkedList *Merge(struct SinglyLinkedList *sll_1, struct SinglyLinkedList *sll_2, bool ascending) {
    struct SinglyLinkedList *sll_3 = Concatenate(sll_1, sll_2);
    Sort(sll_3, ascending);
    return sll_3;
}

int main() {
    int arr_1[] = {1, 3, 5, 7, 9};
    int arr_2[] = {0, 1, 2, 4, 6, 8};
    struct SinglyLinkedList sll_1, sll_2;
    CreateSLL(&sll_1, arr_1, sizeof(arr_1)/sizeof(int));
    CreateSLL(&sll_2, arr_2, sizeof(arr_2)/sizeof(int));
    Display(sll_1);
    Display(sll_2);
    struct SinglyLinkedList *sll_3 = Merge(&sll_1, &sll_2, true);
    Display(*sll_3);
    Unique(sll_3);
    Display(*sll_3);
    Destruct(sll_3);
    return 0;
}