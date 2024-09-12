#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct CircularSinglyLinkedList {
    struct Node *head;
};

void Create(struct CircularSinglyLinkedList *csll, int arr[], int n) {
    csll->head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = csll->head;
    for (int i = 0; i < n; i++) {
        p->data = arr[i];
        if (i < n - 1) {
            p->next = (struct Node *) malloc(sizeof(struct Node));
            p = p->next;
        }
    }
    p->next = csll->head;
}

void Init(struct CircularSinglyLinkedList *csll) {
    csll->head = NULL;
}

int Count(struct CircularSinglyLinkedList csll) {
    struct Node *p = csll.head;
    int result = 0;
    if (p) {
        do {
            result++;
            p = p->next;
        } while (p != csll.head);
    }
    return result;
}

int Sum(struct CircularSinglyLinkedList csll) {
    struct Node *p = csll.head ? csll.head : NULL;
    int result = 0;
    if (p) {
        do {
            result += p->data;
            p = p->next;
        } while (p != csll.head);
    }
    return result;
}

int Min(struct CircularSinglyLinkedList csll) {
    struct Node *p = csll.head ? csll.head : NULL;
    int result = p->data;
    if (p) {
        do {
            if (p->data < result) {
                result = p->data;
            }
            p = p->next;
        } while (p != csll.head);
    }
    return result;
}

int Max(struct CircularSinglyLinkedList csll) {
    struct Node *p = csll.head ? csll.head : NULL;
    int result = p->data;
    if (p) {
        do {
            if (p->data > result) {
                result = p->data;
            }
            p = p->next;
        } while (p != csll.head);
    }
    return result;
}

bool isSorted(struct CircularSinglyLinkedList csll, bool ascending) {
    struct Node *p = csll.head ? csll.head : NULL;
    bool is_sorted = false; 
    if (p) {
        int result = 0;
        int n = Count(csll);
        int prev_data = p->data;
        do {
            if (p->data >= prev_data && ascending) {
                result++;
            }
            else if (p->data <= prev_data && ! ascending) {
                result++;
            }
            prev_data = p->data;
            p = p->next;
        } while (p != csll.head);
        is_sorted = result == n;
    }
    return is_sorted;
}

void Display(struct CircularSinglyLinkedList csll) {
    struct Node *p;
    p = csll.head;
    printf("[");
    do {
        if (p->next == csll.head) {
            printf("%d", p->data);
        }
        else {
            printf("%d, ", p->data);
        }
        p = p->next;
    } while (p != csll.head);
    printf("]\n");
}

void Append(struct CircularSinglyLinkedList *csll, int data) {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = data;
    if (csll->head == NULL) {
        csll->head = t;
        csll->head->next = csll->head;
    }
    else {
        struct Node *p = csll->head;
        while (p->next != csll->head) {
            p = p->next;
        }
        p->next = t;
        t->next = csll->head;
    }
}

void Insert(struct CircularSinglyLinkedList *csll, int pos, int data) {
    int n = Count(*csll);
    pos = pos == 0 ? n : pos;
    if (pos >= 0 && pos <= n) {
        struct Node *t = (struct Node *) malloc(sizeof(struct Node));
        t->data = data;
        if (csll->head == NULL) {
            csll->head = t;
            csll->head->next = csll->head;
        }
        else {
            struct Node *p = csll->head;
            for (int i = 0; i < pos - 1; i++) {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
}

int Pop(struct CircularSinglyLinkedList *csll, int pos) {
    int n = Count(*csll);
    int data;
    if (pos >= 0 && pos < n) {
        struct Node *p = csll->head;
        struct Node *q;
        if (pos == 0) {
            q = p;
            q = q->next;
            csll->head = q;
            while (q->next != p) {
                q = q->next;
            }
            data = p->data;
            q->next = csll->head;
        }
        else {
            for (int i = 0; i < pos; i++) {
                q = p;
                p = p->next;
            }
            data = p->data;
            q->next = p->next;
        }
        free(p);
        return data;
    }
    return -1;
}

void Sort(struct CircularSinglyLinkedList *csll, bool ascending) {
    struct Node *p, *q, *r;
    int i, n;
    n = Count(*csll);
    while (!isSorted(*csll, ascending)) {
        p = NULL;
        q = csll->head;
        r = q->next;
        for (i = 0; i < n - 1; i++) {
            if (ascending && q->data > r->data || !ascending && q->data < r->data) {
                q->next = r->next;
                r->next = q;
                q = r;
                r = q->next;
                if (p == NULL) {
                    csll->head = q;
                }
                else {
                    p->next = q;
                }    
            }
            if (i < n - 2) {
                p = q;
                q = r;
                r = r->next;
            }
        }
        r->next = csll->head;
    }   
}

void DeleteDuplicates(struct CircularSinglyLinkedList *csll) {
    struct Node *p, *q;
    p = csll->head;
    q = NULL;
    int min, max, n;
    min = Min(*csll);
    max = Max(*csll);
    n = max - min + 1;
    int *H = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        H[i] = 0;
    }
    do {
        if (!H[p->data]) {
            H[p->data]++;
        }
        else {
            q->next = p->next;
            free(p);
            p = q;
        }
        q = p;
        p = p->next;
    } while (p != csll->head);
    q->next = csll->head;
    free(H);
}

void Reverse(struct CircularSinglyLinkedList *csll) {
    struct Node *p, *q, *r;
    int n = Count(*csll);
    p = csll->head;
    q = r = NULL;
    for (int i = 0; i < n; i++) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    csll->head->next = q;
    csll->head = q;
}

bool isLooped(struct CircularSinglyLinkedList csll) {
    struct Node *p = csll.head;
    do {
        p = p->next;
    }   while(p != csll.head);
    return p == csll.head;
}

int main() {
    struct CircularSinglyLinkedList csll;
    int arr[] = {1, 1, 1, 5, 5, 2, 6, 3, 4, 4, 4};
    Create(&csll, arr, sizeof(arr)/sizeof(int));
    printf("Count: %d\n", Count(csll));
    printf("Sum: %d\n", Sum(csll));
    printf("Min: %d\n", Min(csll));
    printf("Max: %d\n", Max(csll));
    printf("Sorted: %d\n", isSorted(csll, true));
    printf("Looped: %d\n", isLooped(csll));
    DeleteDuplicates(&csll);
    Reverse(&csll);
    Sort(&csll, false);
    Display(csll);
    return 0;
}