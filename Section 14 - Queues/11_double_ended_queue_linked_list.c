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

struct Deque {
    struct Node *front;
    struct Node *rear;
};

void dequeInit(struct Deque *deq) {
    deq->front = deq->rear = NULL;
}

bool dequeIsEmpty(struct Deque *deq) {
    if (deq->front == NULL) {
        return true;
    }
    return false;
}

bool dequeIsFull() {
    struct Node *t = nodeCreate();
    if (t == NULL) {
        return true;
    }
    return false;
}

void dequeDestruct(struct Deque *deq) {
    if (!dequeIsEmpty(deq)) {
        struct Node *p = deq->front;
        while (deq->front) {
            deq->front = deq->front->next;
            free(p);
            p = deq->front;
        }
        deq->rear = NULL;
    }
}

void dequeDisplay(struct Deque deq) {
    printf("[");
    struct Node *p = deq.front;
    while (p) {
        printf("%d", p->data);
        if (p->next) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
}

void dequeEnqueueFront(struct Deque *deq, int data) {
    struct Node *t = nodeCreate();
    if (dequeIsEmpty(deq)) {
        nodeInit(t, data, NULL, NULL);
        deq->front = deq->rear = t;
    }
    else {
        if (dequeIsFull()) {
            printf("Deque Overflow\n");
        }
        else {
            nodeInit(t, data, NULL, deq->front);
            deq->front->prev = t;
            deq->front = t;
        }
    }
}

void dequeEnqueueRear(struct Deque *deq, int data) {
    struct Node *t = nodeCreate();
    if (dequeIsEmpty(deq)) {
        nodeInit(t, data, NULL, NULL);
        deq->front = deq->rear = t;
    }
    else {
        if (dequeIsFull()) {
            printf("Deque Overflow\n");
        }
        else {
            nodeInit(t, data, deq->rear, NULL);
            deq->rear->next = t;
            deq->rear = t;
        }
    }
}

int dequeDequeueFront(struct Deque *deq) {
    int x = -1;
    if (dequeIsEmpty(deq)) {
        printf("Deque Underflow\n");
    }
    else {
        struct Node *p = deq->front;
        x = p->data;
        deq->front = deq->front->next;
        free(p);
        deq->front->prev = NULL;
    }
    return x;
}

int dequeDequeueRear(struct Deque *deq) {
    int x = -1;
    if (dequeIsEmpty(deq)) {
        printf("Deque Underflow\n");
    }
    else {
        struct Node *p = deq->rear;
        x = p->data;
        deq->rear = deq->rear->prev;
        free(p);
        deq->rear->next = NULL;
    }
    return x;
}



int main() {
    struct Deque deq;
    dequeInit(&deq);
    dequeEnqueueRear(&deq, 0);
    dequeDisplay(deq);
    dequeEnqueueFront(&deq, -1);
    dequeDisplay(deq);
    dequeEnqueueRear(&deq, 1);
    dequeDisplay(deq);
    dequeDequeueFront(&deq);
    dequeDisplay(deq);
    dequeDequeueRear(&deq);
    dequeDisplay(deq);
    dequeDestruct(&deq);
    return 0;
}