#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *nodeCreate(int data) {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    return t;
}

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void queueInit(struct Queue *queue) {
    queue->front = queue->rear = NULL;
}

int queueIsEmpty(struct Queue *queue) {
    if (queue->front == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void queueDestruct(struct Queue *queue) {
    if (!queueIsEmpty(queue)) {
        struct Node *p = queue->front;
        while (queue->front) {
            queue->front = queue->front->next;
            free(p);
            p = queue->front;
        }
        queue->rear = NULL;
    }
}

void queueDisplay(struct Queue queue) {
    printf("[");
    struct Node *p = queue.front;
    while (p) {
        printf("%d", p->data);
        if (p->next) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
}

void queueEnqueue(struct Queue *queue, int data) {
    struct Node *t = nodeCreate(data);
    if (t == NULL) {
        printf("Queue Overflow\n");
    }
    else {
        if (queueIsEmpty(queue)) {
            queue->front = queue->rear = t;
        }
        else if (queue->rear != NULL && data >= queue->rear->data) {
            queue->rear->next = t;
            queue->rear = t;
        }
        else {
            struct Node *p, *q;
            p = queue->front;
            q = NULL;
            while (p) {
                if (data < p->data) {
                    t->next = p;
                    if (q) {
                        q->next = t;
                    }
                    else {
                        queue->front = t;
                    }
                    break;
                }
                q = p;
                p = p->next;
            }
        }
    }
}

int queueDequeue(struct Queue *queue) {
    int x = -1;
    if (queueIsEmpty(queue)) {
        printf("Queue Underflow\n");
    }
    else {
        struct Node *p = queue->front;
        x = p->data;
        if (queue->front == queue->rear) {
            queue->front = NULL;
            queue->rear = NULL;
        }
        else {
            queue->front = queue->front->next;
        }
        free(p);
    }
    return x;
}

int main() {
    struct Queue q;
    queueInit(&q);
    int arrNums[] = {9, 19, 4, 67, 3, 4, 8, 6, 12, -1, 0, 45, -100, 6};
    for (int i = 0; i < 14; i++) {
        queueEnqueue(&q, arrNums[i]);
        queueDisplay(q);
    }
    while (q.front != NULL) {
        printf("%d\n", queueDequeue(&q));
    }
    return 0;
}