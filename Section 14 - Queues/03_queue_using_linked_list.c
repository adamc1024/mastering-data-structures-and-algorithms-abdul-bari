#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Node *nodeCreate() {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    return t;
}

void queueInit(struct Queue *q) {
    q->front = q->rear = NULL;
}

int queueIsEmpty(struct Queue *q) {
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void queueDestruct(struct Queue *q) {
    if (!queueIsEmpty(q)) {
        struct Node *p = q->front;
        while (q->front) {
            q->front = q->front->next;
            free(p);
            p = q->front;
        }
        q->rear = NULL;
    }
}

void queueDisplay(struct Queue q) {
    printf("[");
    struct Node *p = q.front;
    while (p) {
        printf("%d", p->data);
        if (p->next) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
} 

int queueIsFull() {
    struct Node *t = nodeCreate();
    if (t == NULL) {
        return 1;
    }
    else {
        free(t);
        return 0;
    }
}

void enqueue(struct Queue *q, int data) {
    if (queueIsFull()) {
        printf("Queue Is Full\n");
    }
    else {
        struct Node *t = nodeCreate();
        t->data = data;
        t->next = NULL;
        if (q->front == NULL && q->rear == NULL) {
            q->front = t;
            q->rear = t;
        }
        else {
            q->rear->next = t;
            q->rear = q->rear->next;
        }
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    if (q->front == NULL && q->rear == NULL) {
        printf("Queue is Empty\n");
    }
    else {
        struct Node *p = q->front;
        x = p->data;
        if (q->front == q->rear) {
            q->front = NULL;
            q->rear = NULL;
        }
        else {
            q->front = q->front->next;
        }
        free(p);
    }
    return x;
}

int main() {
    struct Queue q;
    queueInit(&q);
    enqueue(&q, 10);
    enqueue(&q, 4);
    enqueue(&q, 8);
    enqueue(&q, 9);
    queueDisplay(q);
    dequeue(&q);
    dequeue(&q);
    queueDisplay(q);
    queueDestruct(&q);
    return 0;
}