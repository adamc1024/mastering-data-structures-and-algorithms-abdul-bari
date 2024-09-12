#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tNode {
    int data;
    struct tNode *left;
    struct tNode *right;
};

struct tNode *tNodeCreate(int data) {
    struct tNode *t = (struct tNode *) malloc(sizeof(struct tNode));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

void tNodeDisplay(struct tNode *tn) {
    if (tn != NULL) {
        printf("%d", tn->data);
    }
    else {
        printf("NULL");
    }
}

struct BST {
    struct tNode *root;
};

void bstInit(struct BST *bst) {
    bst->root = NULL;
}

void bstInsertI(struct BST *bst, int data) {
    if (bst->root == NULL) {
        bst->root = tNodeCreate(data);
        return;
    }
    else {
        struct tNode *p = bst->root;
        struct tNode *q, *t;
        while (p) {
            q = p;
            if (data < p->data) {
                p = p->left;
            }
            else if (data > p->data) {
                p = p->right;
            }
            else {
                return;
            }
        }
        t = tNodeCreate(data);
        if (data < q->data) {
            q->left = t;
        }
        else {
            q->right = t;
        }
    }

}

struct tNode *tNodeInsertR(struct tNode *p, int data) {
    if (p == NULL) {
        p = tNodeCreate(data);
    }
    else if (data < p->data) {
        p->left = tNodeInsertR(p->left, data); 
    }
    else if (data > p->data) {
        p->right = tNodeInsertR(p->right, data);
    }
    return p;
}

void bstInsertR(struct BST *bst, int data) {
    bst->root = tNodeInsertR(bst->root, data);
}

struct tNode *tNodeSearchR(struct tNode *p, int data) {
    if (p == NULL) {
        printf("Data not found.\n");
        return NULL;
    }
    if (data < p->data) {
        return tNodeSearchR(p->left, data);
    }
    else if (data > p->data) {
        return tNodeSearchR(p->right, data);
    }
    return p;
}

struct tNode *bstSearchR(struct BST bst, int data) {
    return tNodeSearchR(bst.root, data);
}

struct tNode *bstSearchI(struct BST bst, int data) {
    struct tNode *p = bst.root;
    while (p) {
        if (data == p->data) {
            return p;
        }
        else {
            if (data < p->data) {
                p = p->left;
            }
            else {
                p = p->right;
            }
        }
    }
    printf("Data not found.\n");
    return NULL;
}

struct tNode *inOrderPredecessorI(struct tNode *p) {
    while (p->right) {
        p = p->right;
    }
    return p;
}

struct tNode *inOrderSuccessorI(struct tNode *p) {
    while (p->left) {
        p = p->left;
    }
    return p;
}

struct sNode {
    struct tNode *tn;
    struct sNode *next;
};

struct sNode *sNodeCreate(struct tNode *tn) {
    struct sNode *t = (struct sNode *) malloc(sizeof(struct sNode));
    t->tn = tn;
    t->next = NULL;
    return t;
}

struct Stack {
    struct sNode *top;
};

void stackInit(struct Stack *stack) {
    stack->top = NULL;
}

bool stackIsEmpty(struct Stack *stack) {
    if (stack->top == NULL) {
        return true;
    }
    return false;
}

void stackPush(struct Stack *stack, struct tNode *tn) {
    struct sNode *t = sNodeCreate(tn);
    if (stackIsEmpty(stack)) {
        stack->top = t;
    }
    else {
        t->next = stack->top;
        stack->top = t;
    }
}

struct tNode *stackPop(struct Stack *stack) {
    struct tNode *tn = NULL;
    if (stackIsEmpty(stack)) {
        printf("Stack Underflow\n");
    }
    else {
        struct sNode *sn = stack->top;
        tn = stack->top->tn;
        stack->top = stack->top->next;
        free(sn);
    }
    return tn;
}

void stackDisplay(struct Stack stack) {
    struct sNode *p = stack.top;
    while (p) {
        if (p->tn != NULL) {
            printf("%d ", p->tn->data);
        }
        else {
            printf("NULL ");
        }
        p = p->next;
    }
    printf("\n");
}

void stackDestruct(struct Stack *stack) {
    while (!stackIsEmpty(stack)) {
        stackPop(stack);
    }
}

int nodeHeightI(struct tNode *tn) {
    int x, max;
    long int temp;
    x = max = 0;
    bool right = false;
    struct Stack stack;
    stackInit(&stack);
    struct tNode *p = tn;
    while (!stackIsEmpty(&stack) || p != NULL) {
        if (p) {
            stackPush(&stack, p);
            x++;
            if (x > max) {
                max = x;
            }
            p = p->left;
        }
        else {
            temp = (long int) stackPop(&stack);
            if (temp > 0) {
                stackPush(&stack, (struct tNode *) -temp);
                p = ((struct tNode *) temp)->right;
            }
            else {
                x--;
            }
        }
    }
    return max;
}

void bstDeleteI(struct BST *bst, int data) {
    if (bstSearchI(*bst, data) == NULL) {
        return;
    }
    else if (data == bst->root->data && bst->root->left == NULL && bst->root->right == NULL) {
        free(bst->root);
        bst->root = NULL;
        return;
    }
    struct tNode *p = bst->root;
    struct Stack stPath;
    stackInit(&stPath);
    while (data != p->data) {
        stackPush(&stPath, p);
        if (data < p->data) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    struct Stack stMove;
    stackInit(&stMove);
    int lHeight, rHeight;
    stackPush(&stPath, p);
    while (p->left != NULL || p->right != NULL) {
        stackPush(&stMove, p);
        lHeight = nodeHeightI(p->left);
        rHeight = nodeHeightI(p->right);
        if (lHeight > rHeight) {
            p = p->left;
            stackPush(&stPath, p);
            while (p->right != NULL) {
                p = p->right;
                stackPush(&stPath, p);
            }
        }
        else {
            p = p->right;
            stackPush(&stPath, p);
            while (p->left != NULL) {
                p = p->left;
                stackPush(&stPath, p);
            }
        }
    }
    struct tNode *q, *r;
    q = stackPop(&stMove);
    r = stackPop(&stPath);
    bool childFound, parentFound, stMoveEmptied;
    stMoveEmptied = false;
    while (!stMoveEmptied) {
        printf("a\n");
        if (stackIsEmpty(&stMove)) {
            stMoveEmptied = true;
        }
        childFound = parentFound = false;
        while (!parentFound) {
            if (childFound) {
                parentFound = true;
            }
            else {
                if (q->data == r->data) {
                    childFound = true;
                }
                if (stackIsEmpty(&stPath)) {
                    r = NULL;
                }
                else {
                    r = stackPop(&stPath);
                }
            }
        }
        printf("p == ");
        tNodeDisplay(p);
        printf(", q == ");
        tNodeDisplay(q);
        printf(", r == ");
        tNodeDisplay(r);
        printf("\n");
        if (r == NULL) {
            bst->root = p;
        }
        else {
            if (p->data < r->data) {
                r->left = p;
            }
            else {
                r->right = p;
            }
        }
        p->left = q->left;
        p->right = q->right;
        if (p->left == p) {
            p->left = NULL;
        }
        if (p->right == p) {
            p->right = NULL;
        }
        p = q;
        if (!stackIsEmpty(&stMove)) {
            q = stackPop(&stMove);
        }
    }
    free(q);
}

void tNodeInOrderR(struct tNode *p) {
    if (p) {
        tNodeInOrderR(p->left);
        printf("%d ", p->data);
        tNodeInOrderR(p->right);
    }
}

void bstInOrderR(struct BST bst) {
    tNodeInOrderR(bst.root);
    printf("\n");
}

int main() {
    struct BST bst1;
    bstInit(&bst1);
    bstInsertI(&bst1, 10);
    bstInsertI(&bst1, 5);
    bstInsertR(&bst1, 7);
    bstInsertR(&bst1, 7);
    bstInOrderR(bst1);

    struct tNode *q = bstSearchI(bst1, 5);
    if (q) {
        printf("%d\n", q->data);
    }

    struct BST bst2;
    bstInit(&bst2);
    bstInsertR(&bst2, 14);
    bstInsertR(&bst2, -1);
    bstInsertI(&bst2, -1);
    bstInsertI(&bst2, 100);
    bstInOrderR(bst2);

    struct tNode *r = bstSearchR(bst2, 99);
    if (r) {
        printf("%d\n", r->data);
    }

    struct BST bst3;
    bstInit(&bst3);
    bstInsertR(&bst3, 30);
    bstInsertR(&bst3, 20);
    bstInsertI(&bst3, 40);
    bstInsertI(&bst3, 10);
    bstInsertR(&bst3, 25);
    bstInsertR(&bst3, 22);
    bstInsertI(&bst3, 27);
    bstInsertI(&bst3, 23);
    bstInsertR(&bst3, 26);
    bstInsertR(&bst3, 35);
    bstInsertI(&bst3, 50);

    bstDeleteI(&bst3, 30);
    bstInOrderR(bst3);
    printf("%d\n", bst3.root->data);
    bstDeleteI(&bst3, 27);
    // bstInOrderR(bst3);
    tNodeDisplay(bst3.root);
    printf("\n");
    tNodeDisplay(bst3.root->left);
    printf("\n");
    tNodeDisplay(bst3.root->left->left);
    printf("\n");
    tNodeDisplay(bst3.root->left->right);
    printf("\n");
    tNodeDisplay(bst3.root->left->right->left);
    printf("\n");
    tNodeDisplay(bst3.root->left->right->right);
    printf("\n");
    return 0;
}