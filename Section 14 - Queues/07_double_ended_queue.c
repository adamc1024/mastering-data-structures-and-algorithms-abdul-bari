#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Deque {
    int size;
    int front;
    int rear;
    int *Q;
};

void dequeInit(struct Deque *deq, int size) {
    deq->size = size;
    deq->front = -1;
    deq->rear = -1;
    deq->Q = (int *) malloc(size * sizeof(int));
}

void dequeDestruct(struct Deque *deq) {
    free(deq->Q);
}

void dequeDisplay(struct Deque deq) {
    printf("[");
    for (int i = deq.front + 1; i <= deq.rear; i++) {
        printf("%d", deq.Q[i]);
        if (i < deq.rear) {
            printf(", ");
        }
    }
    printf("]\n");
}

bool dequeIsEmpty(struct Deque deq) {
    if (deq.front == deq.rear) {
        return true;
    }
    return false;
}

bool dequeIsFull(struct Deque deq) {
    if (deq.rear == deq.size -1) {
        return true;
    }
    return false;
}

void dequeEnqueueFront(struct Deque *deq, int data) {
    if (deq->front == -1) {
        printf("Deque Overflow\n");
    }
    else {
        deq->Q[deq->front] = data;
        deq->front--;
    }
}

void dequeEnqueueRear(struct Deque *deq, int data) {
    if (dequeIsFull(*deq)) {
        printf("Deque Overflow\n");
    }
    else {
        deq->rear++;
        deq->Q[deq->rear] = data;
    }
}

int dequeDequeueFront(struct Deque *deq) {
    int x = -1;
    if (dequeIsEmpty(*deq)) {
        printf("Deque Underflow\n");
    }
    else {
        deq->front++;
        x = deq->Q[deq->front];
        if (dequeIsEmpty(*deq)) {
            deq->front = deq->rear = -1;
        }
    }
    return x;
}

int dequeDequeueRear(struct Deque *deq) {
    int x = -1;
    if (dequeIsEmpty(*deq)) {
        printf("Deque Underflow\n");
    }
    else {
        x = deq->Q[deq->rear];
        deq->rear--;
        if (dequeIsEmpty(*deq)) {
            deq->front = deq->rear = -1;
        }
    }
    return x;
}

int main() {
    struct Deque deq;
    dequeInit(&deq, 4);
    dequeEnqueueRear(&deq, 3);
    dequeEnqueueRear(&deq, 5);
    dequeEnqueueRear(&deq, 7);
    dequeEnqueueRear(&deq, 9);
    dequeEnqueueRear(&deq, 11);
    dequeDisplay(deq);
    dequeDequeueRear(&deq);
    dequeDisplay(deq);
    dequeDequeueFront(&deq);
    dequeDisplay(deq);
    dequeEnqueueFront(&deq, 8);
    dequeDisplay(deq);
    dequeDequeueFront(&deq);
    dequeDisplay(deq);
    dequeDequeueFront(&deq);
    dequeDisplay(deq);
    dequeDequeueRear(&deq);
    dequeDisplay(deq);
    printf("%d %d\n", deq.front, deq.rear);
    dequeDestruct(&deq);
    return 0;
}