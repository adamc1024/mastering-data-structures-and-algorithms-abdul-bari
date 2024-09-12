#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void queueInit(struct Queue *q, int size) {
    q->size = size + 1;
    q->Q = (int *) malloc(q->size * sizeof(int)); 
    q->front = q->rear = 0;
}

void queueDestruct(struct Queue *q) {
    free(q->Q);
}

void queueDisplay(struct Queue q) {
    printf("[");
    int i = (q.front + 1) % q.size;
    while (i != (q.rear +1) % q.size) {
        printf("%d", q.Q[i]);
        if (i != q.rear) {
            printf(", ");
        }
        i = (i + 1) % q.size;
    }
    printf("]\n");
} 

int queueIsEmpty(struct Queue *q) {
    if (q->front == q->rear) {
        return 1;
    }
    else {
        return 0;
    }
}

int queueIsFull(struct Queue *q) {
    if (q->front == (q->rear + 1) % q->size) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(struct Queue *q, int data) {
    if (queueIsFull(q)) {
        printf("Queue Is Full\n");
    }
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    if (queueIsEmpty(q)) {
        printf("Queue is Empty\n");
    }
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[(q->front + 1) % q->size];
    }
    return x;
}

int main() {
    struct Queue q;
    queueInit(&q, 3);
    enqueue(&q, 10);
    enqueue(&q, 4);
    enqueue(&q, 8);
    queueDisplay(q);
    dequeue(&q);
    enqueue(&q, 9);
    enqueue(&q, 9);
    queueDisplay(q);
    queueDestruct(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    queueDisplay(q);
    return 0;
}