#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *nodeCreate(int data) {
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

struct BST {
    struct Node *root;
};

void bstInit(struct BST *bst) {
    bst->root = NULL;
}

void bstInsertI(struct BST *bst, int data) {
    if (bst->root == NULL) {
        bst->root = nodeCreate(data);
        return;
    }
    else {
        struct Node *p = bst->root;
        struct Node *q, *t;
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
        t = nodeCreate(data);
        if (data < q->data) {
            q->left = t;
        }
        else {
            q->right = t;
        }
    }

}

struct Node *nodeInsertR(struct Node *p, int data) {
    if (p == NULL) {
        p = nodeCreate(data);
    }
    if (data < p->data) {
        p->left = nodeInsertR(p->left, data); 
    }
    else if (data > p->data) {
        p->right = nodeInsertR(p->right, data);
    }
    return p;
}

void bstInsertR(struct BST *bst, int data) {
    bst->root = nodeInsertR(bst->root, data);
}

void nodeInOrderR(struct Node *p) {
    if (p) {
        nodeInOrderR(p->left);
        printf("%d ", p->data);
        nodeInOrderR(p->right);
    }
}

void bstInOrderR(struct BST bst) {
    nodeInOrderR(bst.root);
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

    struct BST bst2;
    bstInit(&bst2);
    bstInsertR(&bst2, 14);
    bstInsertR(&bst2, -1);
    bstInsertI(&bst2, -1);
    bstInsertI(&bst2, 100);
    bstInOrderR(bst2);
    return 0;
}