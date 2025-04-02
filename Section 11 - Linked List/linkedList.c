#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

nodeSll *newNodeSll() {
    nodeSll *t = (nodeSll *) malloc(sizeof(nodeSll));
    return t;
}

void nodeSllInit(nodeSll *node, int data, nodeSll *next) {
    node->data = data;
    node->next = next;
}

void sllInit(sll *sll) {
    sll->head = NULL;
    sll->tail = NULL;
}

void sllAppend(sll *sll, int data) {
    nodeSll *t = newNodeSll();
    nodeSllInit(t, data, NULL);
    if (sll->head == NULL && sll->tail == NULL) {
        sll->head = sll->tail = t;
    }
    else {
        sll->tail->next = t;
        sll->tail = t;
    }
}

sll newSLLFromArray(int *arr, int n) {
    sll sll;
    sllInit(&sll);
    for (int i = 0; i < n; i++) {
        sllAppend(&sll, arr[i]);
    }
    return sll;
}

void sllDisplay(sll sll) {
    nodeSll *p = sll.head;
    printf("[");
    bool comma = false;
    while (p) {
        if (comma) {
            printf(", ");
        }
        printf("%d", p->data);
        p = p->next;
        comma = true;
    }
    printf("]\n");
}

void sllDestruct(sll *sll) {
    nodeSll *p = sll->head;
    nodeSll *q;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    printf("deallocated sll\n");
}

int sllLength(sll sll) {
    int result = 0;
    nodeSll *p = sll.head;
    while (p) {
        result++;
        p = p->next;
    }
    return result;
}

int sllSum(sll sll) {
    int result = 0;
    nodeSll *p = sll.head;
    while (p) {
        result += p->data;
        p = p->next;
    }
    return result;
}

float sllAverage(sll sll) {
    return (float) sllSum(sll)/sllLength(sll);
}

int sllMin(sll sll) {
    nodeSll *p = sll.head;
    int result = p->data;
    while (p) {
        if (p->data < result) {
            result = p->data;
        }
        p = p->next;
    }
    return result;
}

int sllMax(sll sll) {
    nodeSll *p = sll.head;
    int result = p->data;
    while (p) {
        if (p->data > result) {
            result = p->data;
        }
        p = p->next;
    }
    return result;
}

void sllInsert(sll *sll, int pos, int data) {
    nodeSll *p = sll->head;
    nodeSll *q;
    int n = sllLength(*sll);
    if (pos == n) {
        sllAppend(sll, data);
    }
    else if (pos >= 0 && pos < n) {
        nodeSll *t = newNodeSll();
        if (pos == 0) {
            nodeSllInit(t, data, p);
            sll->head = t;
        }
        else {
            for (int i = 0; i < pos; i++) {
                q = p;
                p = p->next;
            }
            nodeSllInit(t, data, p);
            q->next = t;
        }
    }
}

int sllPop(sll *sll, int pos) {
    int data, n;
    data = -1;
    n = sllLength(*sll);
    if (n && pos >= 0 && pos < n) {
        nodeSll *p = sll->head;
        if (pos == 0) {
            data = p->data;
            sll->head = p->next;
            free(p);
        }
        else {
            nodeSll *q;
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

bool sllIsSorted(sll sll, bool ascending) {
    nodeSll *p = sll.head;
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

void sllSort(sll *sll, bool ascending) {
    nodeSll *p, *q, *r;
    while (!sllIsSorted(*sll, ascending)) {
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

void sllDeleteDuplicates(sll *sll) {
    int max = sllMax(*sll);
    int min = sllMin(*sll);
    int n = max - min + 1;
    int H[n];
    for (int i = 0; i < n; i++) {
        H[i] = 0;
    }
    nodeSll *p = sll->head;
    nodeSll *q;
    while (p) {
        if (H[p->data - min] == 0) {
            H[p->data - min]++;
            q = p;
            p = p->next;
        }
        else if (H[p->data - min] > 0) {
            q->next = p->next;
            printf("Deleted duplicate: %d\n", p->data);
            free(p);
            p = q->next;
        }
    }
}

void sllReverse(sll *sll) {
    nodeSll *p, *q, *r;
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

bool sllIsLooped(sll sll) {
    nodeSll *p, *q;
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

void sllConcatenate(sll *sll_1, sll *sll_2) {
    sll_1->tail->next = sll_2->head;
    sll_1->tail = sll_2->tail;
    sll_2->head = sll_2->tail = NULL;
}

void sllMerge(sll *sll_1, sll *sll_2, bool ascending) {
    sllConcatenate(sll_1, sll_2);
    sllSort(sll_1, ascending);
}
