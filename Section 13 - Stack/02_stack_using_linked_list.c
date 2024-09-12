#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *CreateNode() {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    return t;
}

void InitNode(struct Node *node, int data, struct Node *next) {
    node->data = data;
    node->next = next;
}

struct Stack {
    struct Node *top;
};

void InitStack(struct Stack *st) {
    st->top = NULL;
}

void Push(struct Stack *st, int data) {
    struct Node *t = CreateNode();
    if (t == NULL) {
        printf("Stack Overflow\n");
    }
    else {
        if (st->top == NULL) {
            InitNode(t, data, NULL);
            st->top = t;
        }
        else {
            InitNode(t, data, st->top);
            st->top = t;
        }
    }
}

void Display(struct Stack st) {
    struct Node *p = st.top;
    printf("[");
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
}

int isEmpty(struct Stack st) {
    if (st.top == NULL) {
        return 1;
    }
    return 0;
}

int isFull() {
    struct Node *t = CreateNode();
    if (t == NULL) {
        return 1;
    }
    free(t);
    return 0;
} 

int stackTop(struct Stack st) {
    int x = -1;
    if (! isEmpty(st)) {
        x = st.top->data;
    }
    return x;
}

int Pop(struct Stack *st) {
    int x = -1;
    if (isEmpty(*st)) {
        printf("Stack Underflow\n");
    }
    else {
        struct Node *p = st->top;
        x = p->data;
        st->top = st->top->next;
        free(p);
    }
    return x;
}

int main() {
    struct Stack st;
    InitStack(&st);
    int arr[] = {6, 1, 9, 5, 3};
    for (int i = 0; i < 5; i ++) {
        Push(&st, arr[i]);
    }
    Display(st);
    printf("Popped value: %d\n", Pop(&st));
    printf("Popped value: %d\n", Pop(&st));
    printf("Popped value: %d\n", Pop(&st));
    printf("Popped value: %d\n", Pop(&st));
    printf("Popped value: %d\n", Pop(&st));
    printf("Popped value: %d\n", Pop(&st));
    Display(st);
    return 0;
}