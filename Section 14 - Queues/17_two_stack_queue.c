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

struct Stack {
    struct Node *top;
};

void stackInit(struct Stack *st) {
    st->top = NULL;
}

void stackDisplay(struct Stack *st) {
    struct Node *p = st->top;
    printf("[");
    while (p) {
        printf("%d", p->data);
        if (p->next) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
}

void stackPush(struct Stack *st, int data) {
    struct Node *t = nodeCreate(data);
    if (t != NULL) {
        if (st->top == NULL) {
            st->top = t;
        }
        else {
            t->next = st->top;
            st->top = t;
        }
    }
    else {
        printf("Stack Overflow\n");
    }
}

int stackPop(struct Stack *st) {
    int x = -1;
    if (st->top != NULL) {
        struct Node *p = st->top;
        x = p->data;
        st->top = st->top->next;
        free(p);
    }
    else {
        printf("Stack Underflow\n");
    }
    return x;
}

struct Queue {
    struct Stack stIn;
    struct Stack stOut;
};

void queueInit(struct Queue *q) {
    stackInit(&q->stIn);
    stackInit(&q->stOut);
}

void queueDisplay(struct Queue q) {
    printf("In: ");
    stackDisplay(&q.stIn);
    printf("Out: ");
    stackDisplay(&q.stOut);
}

void queueEnqueue(struct Queue *q, int data) {
    stackPush(&q->stIn, data);
}   

int queueDequeue(struct Queue *q) {
    int x = -1;
    if (q->stOut.top != NULL){
        x = stackPop(&q->stOut);
    } 
    else if (q->stIn.top != NULL && q->stOut.top == NULL) {
        while (q->stIn.top != NULL) {
            stackPush(&q->stOut, stackPop(&q->stIn));
        }
        x = stackPop(&q->stOut);
    }
    return x;
} 

int main() {
    struct Queue q;
    queueInit(&q);
    queueEnqueue(&q, 6);
    queueEnqueue(&q, 7);
    queueEnqueue(&q, 4);
    queueEnqueue(&q, 6);
    queueEnqueue(&q, 7);
    queueEnqueue(&q, 4);
    queueDisplay(q);
    printf("%d\n", queueDequeue(&q));
    queueDisplay(q);
    printf("%d\n", queueDequeue(&q));
    queueDisplay(q);
    printf("%d\n", queueDequeue(&q));
    queueDisplay(q);
    return 0;
}