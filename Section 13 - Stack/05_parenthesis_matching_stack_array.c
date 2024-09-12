#include <stdio.h>
#include <stdlib.h>

struct Stack {
    char *arr;
    int top;
    int size;
};

void initStack(struct Stack *st, int size) {
    st->arr = (char *) malloc(sizeof(char) * size);
    st->size = size;
    st->top = -1;
}

void displayStack(struct Stack st) {
    printf("[");
    for (int i = st.top; i > -1; i--) {
        printf("%c", st.arr[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("]\n");
}

void pushStack(struct Stack *st, char data) {
    if (st->top < st->size - 1) {
        st->top++;
        st->arr[st->top] = data;
    }
    else {
        printf("Stack Overflow\n");
    }
}

char popStack(struct Stack *st) {
    char x = 'x';
    if (st->top > -1) {
        x = st->arr[st->top];
        st->top--;
    }
    else {
         printf("Stack Underflow\n");
    }
    return x;
}

int stringLength(char *s) {
    int i = 0;
    while (s[i]) {
        i++;
    }
    return i;
}

int isBalanced(struct Stack *st, char *s) {
    int i = 0;
    while (s[i]) {
        if (s[i] == '(') {
            pushStack(st, s[i]);
        }
        if (s[i] == ')') {
            char x = popStack(st);
            if (x == 'x') {
                return 0;
            }
        }
        i++;
    }
    if (st->top == -1) {
        return 1;
    }
    return 0;
}

int main() {
    char expression[] = "((a + b) * (c - d))";
    int size = stringLength(expression);
    struct Stack st;
    initStack(&st, size);
    printf("%d\n", isBalanced(&st, expression));
    return 0;
}