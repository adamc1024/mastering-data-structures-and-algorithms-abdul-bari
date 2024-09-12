#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node *next; 
};

struct Node *nodeCreate() {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    return t;
};

void nodeInit(struct Node *node, char data, struct Node *next) {
    node->data = data;
    node->next = next;
}

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void queueInit(struct Queue *q) {
    q->front = q->rear = NULL;
}

void queueDestruct(struct Queue *q) {
    struct Node *p = q->front;
    struct Node *o;
    if (p) {
        while (p) {
            o = p;
            p = p->next;
            free(o);
        }
    }
}

bool queueIsFull() {
    struct Node *t = nodeCreate();
    if (t == NULL) {
        return true;
    }
    return false;

}

bool queueIsEmpty(struct Queue *q) {
    if (q->front == NULL) {
        return true;
    }
    return false;
}

void queueEnqueue(struct Queue *q, char data) {
    struct Node *t = nodeCreate();
    if (queueIsFull()) {
        printf("Queue Overflow");
    }
    else {
        if (queueIsEmpty(q)) {
            nodeInit(t, data, NULL);
            q->front = q->rear = t;
        }
        else {
            nodeInit(t, data, NULL);
            q->rear->next = t;
            q->rear = t;
        }
    }
}

char queueDequeue(struct Queue *q) {
    char x = '\0';
    struct Node *p;
    if (!queueIsEmpty(q)) {
        p = q->front;
        x = p->data;
        q->front = q->front->next;
        free(p);
    }
    else {
        printf("Queue Underflow");
    }
    return x;
}

void queueDisplay(struct Queue q) {
    struct Node *p = q.front;
    printf("[");
    while (p) {
        printf("%c", p->data);
        if (p->next) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
}

struct PQueue {
    struct Queue *p1;
    struct Queue *p2;
    struct Queue *p3;
};

void pqueueInit(struct PQueue *pque) {
    struct Queue *queues[] = {pque->p1, pque->p2, pque->p3};
    for (int i = 0; i < 3; i++) {
        queueInit(queues[i]);
    }
}

void pqueueEnqueue(struct PQueue *pque, int priority, char data) {
    if (priority == 1) {
        queueEnqueue(pque->p1, data);
    }
    else if (priority == 2) {
        queueEnqueue(pque->p2, data);
    }
    else if (priority == 3) {
        queueEnqueue(pque->p3, data);
    }
}

char pqueueDequeue(struct PQueue *pque) {
    if (!queueIsEmpty(pque->p1)) {
        return queueDequeue(pque->p1);
    }
    if (!queueIsEmpty(pque->p2)) {
        return queueDequeue(pque->p2);
    }
    if (!queueIsEmpty(pque->p3)) {
        return queueDequeue(pque->p3);
    }
    return '\0';
}

void pqueueDisplay(struct PQueue pque) {
    queueDisplay(*pque.p1);
    queueDisplay(*pque.p2);
    queueDisplay(*pque.p3);
}

void pqueueDestruct(struct PQueue pque) {
    queueDestruct(pque.p1);
    queueDestruct(pque.p2);
    queueDestruct(pque.p3);
}

int main() {
    struct PQueue pque;
    pqueueInit(&pque);
    char chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    char priorities[] = {1, 1, 2, 3, 2, 1, 2, 3, 2, 2, 1};
    for (int i = 0; i < 11; i++) {
        pqueueEnqueue(&pque, priorities[i], chars[i]);
    }
    pqueueDisplay(pque);
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    printf("%c\n", pqueueDequeue(&pque));
    pqueueDisplay(pque);
    pqueueDestruct(pque);
    return 0;
}