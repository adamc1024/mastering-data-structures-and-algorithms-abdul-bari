#include <stdio.h>
#include <stdlib.h>

struct Stack {
    char *arr;
    int size;
    int top;
};

void stackInit(struct Stack *st, int size) {
    st->arr = (char *) malloc(sizeof(char) * size);
    st->size = size;
    st->top = -1;
}

void stackDestruct(struct Stack *st) {
    free(st->arr);
}

void stackPush(struct Stack *st, char data) {
    if (st->top < st->size - 1) {
        st->top++;
        st->arr[st->top] = data;
    }
    else {
        printf("Stack Overflow\n");
    }
}

char stackPop(struct Stack *st) {
    char poppedChar = '\0'; 
    if (st->top > -1) {
        poppedChar = st->arr[st->top];
        st->top--;
    }
    else {
        printf("Stack Underflow\n");
    }
    return poppedChar;
}

void stackDisplay(struct Stack st) {
    printf("[");
    for (int i = st.top; i > -1; i--) {
        printf("%c", st.arr[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("]\n");
}

char stackTop(struct Stack st) {
    return st.arr[st.top];
}

int stackIsEmpty(struct Stack st) {
    if (st.top > -1) {
        return 0;
    }
    return 1;
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

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    else {
        return 1;
    }
}

int precedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    else if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

char * convert(char *infix) {
    struct Stack st;
    stackInit(&st, countChar(infix));
    char *postfix = (char *) malloc(sizeof(char) * (countChar(infix) +1));
    int i = 0, j = 0;
    while (infix[i] != '\0') {
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
    }
    postfix[j] = '\0';
    stackDestruct(&st);
    return postfix;
}

int main() {
    char s[] = "a + b * c - d / e";
    char *postfix = convert(s);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}