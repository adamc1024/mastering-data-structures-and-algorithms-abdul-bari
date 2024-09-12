#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *st, int size) {
    st->top = -1;
    st->size = size;
    st->S = (int *) malloc(st->size * sizeof(int));
}

void display(struct Stack st) {
    int i;
    printf("[");
    for(i=st.top; i >= 0; i--) {
        printf("%d", st.S[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("]\n");
}

void push(struct Stack *st, int x) {
    if (st->top == st->size - 1) {
        printf("Stack Overflow\n");
    }
    else {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if (st->top == -1) {
        printf("Stack Underflow\n");
    }
    else {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int index) {
    int x = -1;
    if (st.top - index + 1 < 0 || index < 1) {
        printf("Invalid Index \n");
    }
    else {
        x = st.S[st.top - index + 1];
    }
    return x;
}

int isEmpty(struct Stack st) {
    if (st.top == -1) {
        return 1;
    }
    return 0;
}

int isFull(struct Stack st) {
    if (st.top == st.size - 1) {
        return 1;
    }
    return 0;
}

int stackTop(struct Stack st) {
    if (!isEmpty(st)) {
        return st.S[st.top];
    }
    return -1;
}

int main() {
    struct Stack st; 
    create(&st, 6);
    push(&st, 1);
    push(&st, 3);
    push(&st, 6);
    push(&st, 10);
    push(&st, 15);
    push(&st, 21);
    push(&st, 28);
    display(st);
    printf("Removed %d\n", pop(&st));
    display(st);
    printf("%d\n", peek(st, 2));
    printf("%d\n", stackTop(st));
}