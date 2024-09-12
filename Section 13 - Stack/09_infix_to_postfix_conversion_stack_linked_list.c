#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next; 
};

struct Node *nodeCreate(char data, struct Node *next) {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = data;
    t->next = next;
    return t;
}

struct Stack {
    struct Node *top;
};

void stackInit(struct Stack *st) {
    st->top = NULL;
}

int stackIsFull() {
    struct Node *t = nodeCreate('\0', NULL);
    if (t == NULL) {
        return 1;
    }
    free(t);
    return 0;
}

int stackIsEmpty(struct Stack st) {
    if (st.top == NULL) {
        return 1;
    }
    return 0;
}

void stackPush(struct Stack *st, char data) {
    if (!stackIsFull()) {
        struct Node *t = nodeCreate(data, NULL);
        if (stackIsEmpty(*st)) {
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

char stackPop(struct Stack *st) {
    char x = '\0';
    if (!stackIsEmpty(*st)) {
        struct Node *p = st->top;
        x = st->top->data;
        st->top = st->top->next;
        free(p);
    }
    else {
        printf("Stack Underflow\n");
    }
    return x;
}

char stackTop(struct Stack st) {
    if (!stackIsEmpty(st)) {
        return st.top->data;
    }
    else {
        return '\0';
    }
}

void stackDisplay(struct Stack st) {
    struct Node *p = st.top;
    printf("[");
    while (p) {
        printf("%c", p->data);
        if (p->next != NULL) {
            printf(", ");
        }
        p = p->next;
    }
    printf("]\n");
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    return 1;
}

int precedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

int countChar(char *s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            result++;
        }
    }
    return result;
}

char *convertInfixToPostfix(char *infix) {
    char *postfix = (char *) malloc(sizeof(char) * (countChar(infix) + 1));
    struct Stack st;
    stackInit(&st);
    int i = 0, j = 0;
    while (infix[i] != 0) {
        if (infix[i] != ' ') {
            if (isOperand(infix[i])) {
                postfix[j++] = infix[i++];
            }
            else {
                if (precedence(infix[i]) > precedence(stackTop(st))) {
                    stackPush(&st, infix[i++]);
                }
                else {
                    postfix[j++] = stackPop(&st);
                }
            }
            printf("%s\n", postfix);
            stackDisplay(st);
        }
        else {
            i++;
        }
    }
    while (!stackIsEmpty(st)) {
        postfix[j++] = stackPop(&st);
        printf("%s\n", postfix);
        stackDisplay(st);
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char *s = "a + b * c - d / e";
    char *postfix = convertInfixToPostfix(s);
    free(postfix);
    return 0;
}