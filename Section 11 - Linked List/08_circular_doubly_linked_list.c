#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *nodeCreate() {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    return t;
}

void nodeInit(struct Node *t, int data, struct Node *prev, struct Node *next) {
    t->data = data;
    t->prev = prev;
    t->next = next;
}

struct CircularDoublyLinkedList {
    struct Node *head;
    struct Node *tail;
    int length;
};

void cdllInit(struct CircularDoublyLinkedList *cdll) {
    cdll->head = cdll->tail = NULL;
    cdll->length = 0;
}

void cdllDisplay(struct CircularDoublyLinkedList cdll) {
    struct Node *p = cdll.head;
    printf("[");
    if (p) {
        int i = 0;
        do
        {
            printf("%d", p->data);
            if (p != cdll.tail) {
                printf(", ");
            }
            p = p->next;
            i++;
        } while (p != cdll.head);
    }
    printf("]\n");
    
}

bool cdllIsEmpty(struct CircularDoublyLinkedList cdll) {
    if (cdll.length == 0) {
        return true;
    }
    return false;
}

void cdllAppend(struct CircularDoublyLinkedList *cdll, int data) {
    struct Node *t = nodeCreate();
    if (cdllIsEmpty(*cdll)) {
        nodeInit(t, data, t, t);
        cdll->head = cdll->tail = t;
    }
    else {
        nodeInit(t, data, cdll->tail, cdll->head);
        cdll->tail->next = t;
        cdll->tail = t;
        cdll->head->prev = cdll->tail;
    }
    cdll->length++;
}

void cdllInsert(struct CircularDoublyLinkedList *cdll, int pos, int data) {
    int length = cdll->length;
    if (pos >= 0 && pos <= length){
        if (pos == length) {
            cdllAppend(cdll, data);
        }
        else {
            struct Node *t = nodeCreate();
            if (pos == 0) {
                nodeInit(t, data, cdll->tail, cdll->head);
                cdll->head = t;
                cdll->head->next->prev = cdll->head;
                cdll->head->prev->next = cdll->head;

            }
            else {
                struct Node *p;
                if (((length - 1) - pos) < pos) {
                    p = cdll->tail;
                    for (int i = length - 1; i >= pos; i--) {
                        if (i != pos) {
                            p = p->prev;
                        }
                    }
                }
                else {
                    p = cdll->head;
                    for (int i = 0; i <= pos; i++) {
                        if (i != pos) {
                            p = p->next;
                        }
                    }
                }
                nodeInit(t, data, p->prev, p);
                p->prev->next = t;
                p->prev = t;
            }
            cdll->length++;
        }
    }
    else {
        printf("Invalid Index\n");
    }
}

int cdllPop(struct CircularDoublyLinkedList *cdll, int pos) {
    int x = -1;
    int length = cdll->length; 
    if (!cdllIsEmpty(*cdll) && pos >= 0 && pos <= length - 1) {
        struct Node *p;
        cdll->length--;
        if (length == 1 && pos == 0) {
            p = cdll->head;
            cdll->head = cdll->tail = NULL;
        }
        else if (length > 1 && pos == 0) {
            p = cdll->head;
            cdll->head = cdll->head->next;
            cdll->head->prev = cdll->tail;
            cdll->tail->next = cdll->head;
        }
        else if (length > 1 && pos == length - 1) {
            p = cdll->tail;
            cdll->tail = cdll->tail->prev;
            cdll->tail->next = cdll->head;
            cdll->head->prev = cdll->tail;
        }
        else {
            if (((length - 1) - pos) < pos) {
                p = cdll->tail;
                for (int i = length - 1; i >= pos; i--) {
                    if (i != pos) {
                        p = p->prev;
                    }
                }
            }
            else {
                p = cdll->head;
                for (int i = 0; i <= pos; i++) {
                    if (i != pos) {
                        p = p->next;
                    }
                }
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    else if (length == 0) {
        printf("List Underflow\n");
    }
    else {
        printf("Invalid Index\n");
    }
    return x;
}

int cdllSum(struct CircularDoublyLinkedList cdll) {
    int x = -1;
    struct Node *p = cdll.head;
    if (p) {
        x = 0;
        do
        {
            x += p->data;
            p = p->next;
        } while (p != cdll.head);
    }
    return x;
}

int cdllMax(struct CircularDoublyLinkedList cdll) {
    int x = -1;
    struct Node *p = cdll.head;
    if (p) {
        x = p->data;
        do
        {
            if (p->data > x) {
                x = p->data;
            }
            p = p->next;
        } while (p != cdll.head);
    }
    return x;
}

int cdllMin(struct CircularDoublyLinkedList cdll) {
    int x = -1;
    struct Node *p = cdll.head;
    if (p) {
        x = p->data;
        do
        {
            if (p->data < x) {
                x = p->data;
            }
            p = p->next;
        } while (p != cdll.head);
    }
    return x;
}

float cdllAvg(struct CircularDoublyLinkedList cdll) {
    float x = -1;
    struct Node *p = cdll.head;
    if (p) {
        x = 0;
        do
        {
            x += p->data;
            p = p->next;
        } while (p != cdll.head);
        x /= cdll.length;
    }
    return x;
}

bool cdllIsSorted(struct CircularDoublyLinkedList cdll, bool ascending) {
    struct Node *p = cdll.head;
    if (p) {
        int x = p->data;
        do
        {
            if (ascending && p->data < x) {
                return false;
            }
            else if (!ascending && p->data > x) {
                return false;
            }
            x = p->data;
            p = p->next;
        } while (p != cdll.head);
        return true;
    }
    printf("List Is Empty\n");
    return false;
}

void cdllSort(struct CircularDoublyLinkedList *cdll, bool ascending) {
    if (cdll->head != cdll->tail) {
        struct Node *p, *q;
        while (!cdllIsSorted(*cdll, ascending)) {
            p = cdll->head;
            q = p->next;
            while (p != cdll->tail) {
                if (ascending && p->data > q->data || !ascending && p->data < q->data) {
                    if (p == cdll->head) {
                        cdll->head = q;
                    }
                    if (q == cdll->tail) {
                        cdll->tail = p;
                    }
                    p->next = q->next;
                    p->next->prev = p;
                    q->prev = p->prev;
                    q->prev->next = q;
                    q->next = p;
                    p->prev = q;
                    q = p->next;
                }
                else {
                    p = p->next;
                    q = p->next;
                }
            }
        }
    }
    else {
        printf("List Is Empty\n");
    }
}

void cdllUnique(struct CircularDoublyLinkedList *cdll) {
    int min = cdllMin(*cdll);
    int max = cdllMax(*cdll);
    int n = max - min + 1;
    int H[n];
    for (int i = 0; i < n; i++) {
        H[i] = 0;
    }
    struct Node *p = cdll->head;
    struct Node *q = p->next;
    do
    {
        if (H[p->data - min] < 1) {
            H[p->data - min]++;
        }
        else {
            if (p == cdll->tail) {
                cdll->tail = p->prev;
            }
            p->prev->next = q;
            q->prev = p->prev;
            free(p);
        }
        p = q;
        q = q->next;
    } while (p != cdll->head);  
}

void cdllReverse(struct CircularDoublyLinkedList *cdll) {
    struct Node *p = cdll->head;
    struct Node *q;
    if (p) {
        do
        {
            q = p->prev;
            p->prev = p->next;
            p->next = q;
            p = q;
        } while (p != cdll->head);
        p = cdll->head;
        cdll->head = cdll->tail;
        cdll->tail = p;
    }
}
bool cdllIsLooped(struct CircularDoublyLinkedList cdll) {
    struct Node *p = cdll.head;
    if (p) {
        do
        {
            p = p->next;
        } while (p != cdll.head); 
        do
        {
            p = p->prev;
        } while (p != cdll.head);
        if (p == cdll.head) {
            return true;
        }
    }
    return false;
}


int main() {
    struct CircularDoublyLinkedList cdll;
    cdllInit(&cdll);
    cdllAppend(&cdll, 7);
    cdllAppend(&cdll, 3);
    cdllAppend(&cdll, 8);
    cdllAppend(&cdll, 16);
    cdllAppend(&cdll, 2);
    cdllDisplay(cdll);
    cdllPop(&cdll, 2);
    cdllDisplay(cdll);
    cdllInsert(&cdll, 1, 2);
    cdllDisplay(cdll);
    cdllReverse(&cdll);
    cdllDisplay(cdll);
    cdllSort(&cdll, true);
    cdllDisplay(cdll);
    cdllUnique(&cdll);
    cdllDisplay(cdll);
    cdllSort(&cdll, false);
    cdllDisplay(cdll);
    cdllSort(&cdll, true);
    cdllDisplay(cdll);
    printf("isLooped: %d\n", cdllIsLooped(cdll));
    return 0;
}