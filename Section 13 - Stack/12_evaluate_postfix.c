#include <stdio.h>
#include <stdlib.h>

struct charNode {
    char data;
    struct charNode *next;
};

struct charNode *charNodeCreate(char data, struct charNode *next) {
    struct charNode *t = (struct charNode *) malloc(sizeof(struct charNode));
    t->data = data;
    t->next = next;
    return t;
}

struct charStack {
    struct charNode *top;
};

void charStackInit(struct charStack *st, struct charNode *top) {
    st->top = top;
}

void charStackPush(struct charStack *st, char data) {
    struct charNode *t = charNodeCreate(data, NULL);
    if (st->top == NULL) {
        st->top = t;
    }
    else {
        t->next = st->top;
        st->top = t;
    }
}

char charStackPop(struct charStack *st) {
    struct charNode *p;
    char x = '\0';
    if (st->top != NULL) {
        p = st->top;
        x = p->data;
        st->top = st->top->next;
        free(p);
    }
    return x;
}

struct intNode {
    int data;
    struct intNode *next;
};

struct intNode *intNodeCreate(int data, struct intNode *next) {
    struct intNode *t = (struct intNode *) malloc(sizeof(struct intNode));
    t->data = data;
    t->next = next;
    return t;
}

struct intStack {
    struct intNode *top;
};

void intStackInit(struct intStack *st, struct intNode *top) {
    st->top = top;
}

void intStackPush(struct intStack *st, char data) {
    struct intNode *t = intNodeCreate(data, NULL);
    if (st->top == NULL) {
        st->top = t;
    }
    else {
        t->next = st->top;
        st->top = t;
    }
}

char intStackPop(struct intStack *st) {
    struct intNode *p;
    int x = 0;
    if (st->top != NULL) {
        p = st->top;
        x = p->data;
        st->top = st->top->next;
        free(p);
    }
    return x;
}

int isOperand(char x) {
    int charVal = x;
    if (charVal >= 48 && charVal <= 57) {
        return 1;
    }
    return 0;
}

int isOperator(char x) {
    int charVal = x;
    if (charVal == 42 || charVal == 43 || charVal == 45 || charVal == 47) {
        return 1;
    }
    return 0;
}

int evalPostfix(char *s) {
    struct charStack cst;
    charStackInit(&cst, NULL);
    struct intStack ist;
    intStackInit(&ist, NULL);
    int charVal, power, result, x, y;
    int foundOperand = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isOperand(s[i])) {
            charStackPush(&cst, s[i]);
            foundOperand = 1;
        }
        else if (!isOperand(s[i]) && foundOperand) {
            result = 0;
            power = 1;
            while (cst.top != NULL) {
                charVal = charStackPop(&cst);
                charVal -= 48;
                result += (charVal * power);
                power *= 10;
            }
            intStackPush(&ist, result);
            foundOperand = 0;
        }
        else if (isOperator(s[i])) {
            y = intStackPop(&ist);
            x = intStackPop(&ist);
            if (s[i] == '+') {
                intStackPush(&ist, x + y);
            }
            else if (s[i] == '-') {
                intStackPush(&ist, x - y);
            }
            else if (s[i] == '*') {
                intStackPush(&ist, x * y);
            }
            else if (s[i] == '/') {
                intStackPush(&ist, x / y);
            }
        }
    }
    return ist.top->data;
}

int main() {
    char *s = "8 2 / 4 + 9 3 * -";
    printf("%d\n", evalPostfix(s));
    return 0;
}