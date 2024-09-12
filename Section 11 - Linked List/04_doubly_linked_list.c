#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct DoublyLinkedList {
    struct Node *head;
    struct Node *tail;
};

void Initialize(struct DoublyLinkedList *dll) {
    dll->head = NULL;
    dll->tail = NULL;
}

void Append(struct DoublyLinkedList *dll, int data) {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = data;
    if (dll->head == NULL) {
        dll->head = t;
        dll->tail = t;
        t->prev = NULL;
        t->next = NULL;
    }
    else {
        dll->tail->next = t;
        t->prev = dll->tail;
        t->next = NULL;
        dll->tail = t;
    }
}

void Create(struct DoublyLinkedList *dll, int *arr, int n) {
    Initialize(dll);
    for (int i = 0; i < n; i++) {
        Append(dll, arr[i]);
    }
}

int Length(struct DoublyLinkedList dll) {
    struct Node *p = dll.head;
    int result = 0;
    while (p) {
        result++;
        p = p->next;
    }
    return result;
}

void Insert(struct DoublyLinkedList *dll, int pos, int data) {
    if (dll->head == NULL & pos == 0) {
        Append(dll, data);
    }
    else {
        int n = Length(*dll);
        if (pos == n) {
            Append(dll, data);
        }
        else if (pos >= 0 && pos < n) {
            struct Node *t = (struct Node *) malloc(sizeof(struct Node));
            t->data = data;
            if (pos == 0) {
                t->next = dll->head;
                t->prev = NULL;
                dll->head->prev = t;
                dll->head = t;
            }
            else {
                struct Node *p = dll->head;
                for (int i = 0; i < pos - 1; i++) {
                    p = p->next;
                }
                t->next = p->next;
                t->prev = p;
                p->next = t;
            }
        }
    }
}

void Display(struct DoublyLinkedList dll) {
    struct Node *p = dll.head;
    printf("[");
    while (p) {
        if (p->prev) {
            printf(", ");
        }
        printf("%d", p->data);
        p = p->next;
    }
    printf("]\n");
}

int Sum(struct DoublyLinkedList dll) {
    struct Node *p = dll.head;
    int result = 0;
    while (p) {
        result += p->data;
        p = p->next;
    }
    return result;
}

int Max(struct DoublyLinkedList dll) {
    struct Node *p = dll.head;
    int result = p->data;
    while (p) {
        if (p->data > result) {
            result = p->data;
        }
        p = p->next;
    }
    return result;
}

int Min(struct DoublyLinkedList dll) {
    struct Node *p = dll.head;
    int result = p->data;
    while (p) {
        if (p->data < result) {
            result = p->data;
        }
        p = p->next;
    }
    return result;
}

float Avg(struct DoublyLinkedList dll) {
    int n = Length(dll);
    struct Node *p = dll.head;
    float result = p->data;
    while (p) {
        result += p->data;
        p = p->next;
    }
    return result/n;
}

void Reverse(struct DoublyLinkedList *dll) {
    // struct Node *p = dll->tail;
    // struct Node *q = NULL;
    // dll->head = p;
    // while (p) {
    //     p->next = p->prev;
    //     p->prev = q;
    //     q = p;
    //     p = p->next;
    // }
    // dll->tail = q;
    struct Node *p = dll->head;
    struct Node *t;
    dll->tail = p;
    while (p) {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if (p && p->next == NULL) {
            dll->head = p;
        }
    }
}

int Pop(struct DoublyLinkedList *dll, int pos) {
    int data = -1;
    if (dll->head == NULL) {
        return data;
    }
    else {
        int n = Length(*dll);
        if (pos >= 0 && pos < n) {
            if (pos < n - 1) {
                struct Node *p = dll->head;
                if (pos == 0) {
                    data = p->data;
                    dll->head = p->next;
                    dll->head->prev = NULL;
                    free(p);
                    return data;
                }
                else {
                    for (int i = 0; i < pos; i++) {
                        p = p->next;
                    }
                    data = p->data;
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    free(p);
                    return data;
                }

            }
            else {
                struct Node *p = dll->tail;
                data = p->data;
                dll->tail = p->prev;
                dll->tail->next = NULL;
                free(p);
                return data;
            }
        }
    }
    return data;
}

int main() {
    struct DoublyLinkedList dll;
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    Create(&dll, arr, n);
    // Initialize(&dll);
    // for (int i = 0; i < n; i++) {
    //     Append(&dll, arr[i]);
    //     Display(dll);
    // }
    Display(dll);
    printf("%d\n", Length(dll));
    printf("%d\n", Sum(dll));
    printf("%.2f\n", Avg(dll));
    Reverse(&dll);
    Display(dll);
    Insert(&dll, 0, 56);
    Display(dll);
    printf("%d\n", Pop(&dll, 5));
    Display(dll);
    return 0;
}