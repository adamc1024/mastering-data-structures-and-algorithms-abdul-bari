#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

NodeSll *newNodeSll() {
    NodeSll *t = (NodeSll *) malloc(sizeof(NodeSll));
    return t;
}

void nodeSllInit(NodeSll *node, int data, NodeSll *next) {
    node->data = data;
    node->next = next;
}

NodeDll *newNodeDll() {
    NodeDll *t = (NodeDll *) malloc(sizeof(NodeDll));
    return t;
}

void nodeDllInit(NodeDll *node, NodeDll *prev, int data, NodeDll *next) {
    node->prev = prev;
    node->data = data;
    node->next = next;
}

void llInit(LL *ll, uint8_t typeLL) {
    if (typeLL == 1 || typeLL == 2) {
        ll->typeLL = typeLL;
    }
    else {
        ll->typeLL = 1;
    }
    ll->head = NULL;
    ll->tail = NULL;
}

void *nextNodeByType(void *p, uint8_t typeLL) {
    if (typeLL == 1) {
        p = ((NodeSll *)p)->next;
    }
    else if (typeLL == 2) {
        p = ((NodeDll *)p)->next;
    }
    return p;
}

int getDataByType(void *p, uint8_t typeLL) {
    int data;
    if (typeLL == 1) {
        data = ((NodeSll *)p)->data;
    }
    else if (typeLL == 2) {
        data = ((NodeDll *)p)->data;
    }
    return data;
}

void *newNodeByType(uint8_t typeLL) {
    if (typeLL == 1) {
        return newNodeSll();
    }
    else if (typeLL == 2) {
        return newNodeDll();
    }
}

void llAppend(LL *ll, int data) {
    void *t;
    if (ll->typeLL == 1) {
        t = newNodeSll();
        nodeSllInit(t, data, NULL);
    }
    else if (ll->typeLL == 2) {
        t = newNodeDll();
        nodeDllInit(t, NULL, data, NULL);
    }
    if (ll->head == NULL && ll->tail == NULL) {
        ll->head = ll->tail = t;
    }
    else {
        if (ll->typeLL == 1) {
            NodeSll *p;
            p = ll->tail;
            p->next = t;
            ll->tail = t;
        }
        else if (ll->typeLL == 2) {
            NodeDll *p;
            p = ll->tail;
            p->next = t;
            ((NodeDll *)t)->prev = p;
            ll->tail = t;
        }
    }
}

LL newLLFromArray(uint8_t typeLL, int *arr, int n) {
    LL ll;
    llInit(&ll, typeLL);
    if (typeLL == 1) {
        printf("Singly Linked List\n");
    }
    else if (typeLL == 2) {
        printf("Doubly Linked List\n");
    }
    for (int i = 0; i < n; i++) {
        llAppend(&ll, arr[i]);
    }
    return ll;
}

void llDisplay(LL ll)
{
    void *p = ll.head;
    printf("[");
    bool comma = false;
    while (p) {
        if (comma) {
            printf(", ");
        }
        if (ll.typeLL == 1) {
            printf("%d", ((NodeSll *)p)->data);
            p = ((NodeSll *)p)->next;
        }
        else if (ll.typeLL == 2) {
            printf("%d", ((NodeDll *)p)->data);
            p = ((NodeDll *)p)->next;
        }
        comma = true;
    }
    printf("]\n");
}

void llDestruct(LL *ll) {
    void *p = ll->head;
    void *q;
    while (p != NULL) {
        q = p;
        p = nextNodeByType(p, ll->typeLL);
        free(q);
    }
    printf("LL Deallocated\n");
}

int llLength(LL ll) {
    int result = 0;
    void *p = ll.head;
    while (p) {
        result++;
        p = nextNodeByType(p, ll.typeLL);
    }
    return result;
}

int llSum(LL ll) {
    int result = 0;
    void *p = ll.head;
    while (p) {
        result += getDataByType(p, ll.typeLL);
        p = nextNodeByType(p, ll.typeLL);
    }
    return result;
}

float llAverage(LL ll) {
    return (float)llSum(ll)/llLength(ll);
}

int llMin(LL ll) {
    void *p = ll.head;
    int result = getDataByType(p, ll.typeLL);
    int pData;
    while (p) {
        pData = getDataByType(p, ll.typeLL);
        if (pData < result) {
            result = pData;
        }
        p = nextNodeByType(p, ll.typeLL);
    }
    return result;
}

int llMax(LL ll) {
    void *p = ll.head;
    int result = getDataByType(p, ll.typeLL);
    int pData;
    while (p) {
        pData = getDataByType(p, ll.typeLL);
        if (pData > result) {
            result = pData;
        }
        p = nextNodeByType(p, ll.typeLL);
    }
    return result;
}

void llInsert(LL *ll, int pos, int data) {
    void *p = ll->head;
    void *q;
    int n = llLength(*ll);
    if (pos == n) {
        llAppend(ll, data);
    }
    else if (pos >= 0 && pos < n) {
        void *t = newNodeByType(ll->typeLL);
        if (pos == 0) {
            if (ll->typeLL == 1) {
                nodeSllInit((NodeSll *)t, data, (NodeSll *)p);
            }
            else if (ll->typeLL == 2) {
                nodeDllInit((NodeDll *)t, NULL, data, (NodeDll *)p);
            }
            ll->head = t;
        }
        else {
            for (int i = 0; i < pos; i++) {
                q = p;
                p = nextNodeByType(p, ll->typeLL);
            }
            if (ll->typeLL == 1) {
                nodeSllInit((NodeSll *)t, data, (NodeSll *)p);
                ((NodeSll *)q)->next = t;
            }
            else if (ll->typeLL == 2) {
                nodeDllInit((NodeDll *)t, (NodeDll *)q, data, (NodeDll *)p);
                ((NodeDll *)q)->next = t;
                ((NodeDll *)p)->prev = t;
            }
        }
    }
}

// int sllPop(LL *ll, int pos) {
//     int data, n;
//     data = -1;
//     n = sllLength(*sll);
//     if (n && pos >= 0 && pos < n) {
//         nodeSll *p = sll->head;
//         if (pos == 0) {
//             data = p->data;
//             sll->head = p->next;
//             free(p);
//         }
//         else {
//             nodeSll *q;
//             for (int i = 0; i < pos; i++) {
//                 q = p;
//                 p = p->next;
//             }
//             data = p->data;
//             q->next = p->next;
//             free(p);
//             if (pos == n - 1) {
//                 sll->tail = q;
//             }
//         }
//     }
//     return data;
// }

// bool sllIsSorted(LL ll, bool ascending) {
//     nodeSll *p = sll.head;
//     int data;
//     while (p->next) {
//         data = p->data;
//         p = p->next;
//         if (ascending && data > p->data) {
//             break;
//         }
//         if (!ascending && data < p->data) {
//             break;
//         }
//     }
//     if (p->next == NULL) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }

// void sllSort(LL *ll, bool ascending) {
//     nodeSll *p, *q, *r;
//     while (!sllIsSorted(*sll, ascending)) {
//         p = NULL;
//         q = sll->head;
//         r = q->next;
//         while (r) {
//             if (ascending && q->data > r->data || !ascending && q->data < r->data) {
//                 q->next = r->next;
//                 r->next = q;
//                 q = r;
//                 r = q->next;
//                 if (p) {
//                     p->next = q;
//                 }
//                 else {
//                     sll->head = q;
//                 }
//             }
//             p = q;
//             q = q->next;
//             r = r->next;
//         }
//     }
//     sll->tail = q;
// }

// void sllDeleteDuplicates(LL *ll) {
//     int max = sllMax(*sll);
//     int min = sllMin(*sll);
//     int n = max - min + 1;
//     int H[n];
//     for (int i = 0; i < n; i++) {
//         H[i] = 0;
//     }
//     nodeSll *p = sll->head;
//     nodeSll *q;
//     while (p) {
//         if (H[p->data - min] == 0) {
//             H[p->data - min]++;
//             q = p;
//             p = p->next;
//         }
//         else if (H[p->data - min] > 0) {
//             q->next = p->next;
//             printf("Deleted duplicate: %d\n", p->data);
//             free(p);
//             p = q->next;
//         }
//     }
// }

// void sllReverse(LL *ll) {
//     nodeSll *p, *q, *r;
//     p = sll->head;
//     q = r = NULL;
//     while (p) {
//         r = q;
//         q = p;
//         p = p->next;
//         q->next = r;
//     }
//     sll->tail = sll->head;
//     sll->head = q;
// }

// bool sllIsLooped(LL ll) {
//     nodeSll *p, *q;
//     p = q = sll.head;
//     do {
//         p = p->next;
//         q = q->next;
//         q = q ? q->next : q;
//     } while (p && q && p != q);
//     if (p == q) {
//         return true;
//     } 
//     else {
//         return false;
//     }
// }

// void sllConcatenate(LL *ll_1, LL *ll_2) {
//     sll_1->tail->next = sll_2->head;
//     sll_1->tail = sll_2->tail;
//     sll_2->head = sll_2->tail = NULL;
// }

// void sllMerge(LL *ll_1, LL *ll_2, bool ascending) {
//     sllConcatenate(sll_1, sll_2);
//     sllSort(sll_1, ascending);
// }
