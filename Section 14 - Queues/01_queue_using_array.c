#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void queueInit(struct Queue *q, int size) {
    q->size = size;
    q->Q = (int *) malloc(q->size * sizeof(int)); 
    q->front = q->rear = -1;
}

void queueDestruct(struct Queue *q) {
    free(q->Q);
}

void queueDisplay(struct Queue q) {
    printf("[");
    for (int i = q.front + 1; i <= q.rear; i++) {
        printf("%d", q.Q[i]);
        if (i < q.rear) {
            printf(", ");
        }
    }
    printf("]\n");
} 

void enqueue(struct Queue *q, int data) {
    if (q->rear == q->size - 1) {
        printf("Queue Is Full\n");
    }
    else {
        q->rear++;
        q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    if (q->front == q->rear) {
        printf("Queue is Empty\n");
    }
    else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int main() {
    struct Queue q;
    queueInit(&q, 3);
    enqueue(&q, 10);
    enqueue(&q, 4);
    enqueue(&q, 8);
    enqueue(&q, 9);
    queueDisplay(q);
    dequeue(&q);
    queueDisplay(q);
    queueDestruct(&q);
    return 0;
}