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
    deq->size = size + 1;
    deq->front = 0;
    deq->rear = 0;
    deq->Q = (int *) malloc(deq->size * sizeof(int));
}

void dequeDestruct(struct Deque *deq) {
    free(deq->Q);
}

void dequeDisplay(struct Deque deq) {
    printf("[");
    int i = (deq.front + 1) % deq.size;
    while (i != (deq.rear +1) % deq.size) {
        printf("%d", deq.Q[i]);
        if (i != deq.rear) {
            printf(", ");
        }
        i = (i + 1) % deq.size;
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
    if (deq.front == (deq.rear + 1) % deq.size) {
        return true;
    }
    else {
        return false;
    }
}

void dequeEnqueueFront(struct Deque *deq, int data) {
    if (deq->front == (deq->rear + 1) % deq->size) {
        printf("Deque Overflow\n");
    }
    else {
        deq->Q[deq->front] = data;
        deq->front = (deq->front - 1) % deq->size;
        if (deq->front < 0) {
            deq->front += deq->size;
        }
        printf("%d\n", deq->front);
    }
}

void dequeEnqueueRear(struct Deque *deq, int data) {
    if (dequeIsFull(*deq)) {
        printf("Deque Overflow\n");
    }
    else {
        deq->rear = (deq->rear + 1) % deq->size;
        deq->Q[deq->rear] = data;
    }
}

int dequeDequeueFront(struct Deque *deq) {
    int x = -1;
    if (dequeIsEmpty(*deq)) {
        printf("Deque Underflow\n");
    }
    else {
        deq->front = (deq->front + 1) % deq->size;
        x = deq->Q[deq->front];
        if (dequeIsEmpty(*deq)) {
            deq->front = deq->rear = 0;
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
        deq->rear = (deq->rear - 1) % deq->size;
        if (deq->rear < 0) {
            deq->rear += deq->size;
        }
        if (dequeIsEmpty(*deq)) {
            deq->front = deq->rear = 0;
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
    dequeDequeueFront(&deq);
    dequeDequeueFront(&deq);
    dequeDequeueFront(&deq);
    dequeDequeueFront(&deq);
    dequeDequeueFront(&deq);
    dequeDisplay(deq);
    dequeDestruct(&deq);
    return 0;
}