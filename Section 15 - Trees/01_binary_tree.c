#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tNode
{
    struct tNode *left;
    int data;
    struct tNode *right;
};

struct tNode * tNodeCreate(int data) {
    struct tNode *t = (struct tNode *) malloc(sizeof(struct tNode));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}

struct qNode
{
    struct tNode *tn;
    struct qNode *next;
};

struct qNode * qNodeCreate(struct tNode *tn) {
    struct qNode *t = (struct qNode *) malloc(sizeof(struct qNode));
    t->tn = tn;
    t->next = NULL;
    return t;
}

struct Queue
{
    struct qNode *front;
    struct qNode *rear;
};

void queueInit(struct Queue *queue) {
    queue->front = queue->rear = NULL;
}

bool queueIsEmpty(struct Queue *queue) {
    if (queue->front == queue->rear && queue->front == NULL) {
        return true;
    }
    return false;
}

void queueEnqueue(struct Queue *queue, struct tNode *tn) {
    struct qNode *t = qNodeCreate(tn);
    if (t == NULL) {
        printf("Queue Overflow\n");
    }
    else {
        if (queueIsEmpty(queue)) {
            queue->front = queue->rear = t;
        }
        else {
            queue->rear->next = t;
            queue->rear = t;
        }
    }
}

struct tNode * queueDequeue(struct Queue *queue) {
    struct tNode *tn = NULL;
    if (queueIsEmpty(queue)) {
        printf("Queue Underflow\n");
    }
    else {
        struct qNode *p = queue->front;
        tn = queue->front->tn;
        if (queue->front == queue->rear) {
            queue->front = queue->rear = NULL;
        }
        else {
            queue->front = queue->front->next;
        }
        free(p);
    }
    return tn;
}

void queueDestruct(struct Queue *queue) {
    while (!queueIsEmpty(queue)) {
        queueDequeue(queue);
    }
}

struct Stack
{
    struct qNode *top;
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
    struct qNode *t = qNodeCreate(tn);
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
        struct qNode *qn = stack->top;
        tn = stack->top->tn;
        stack->top = stack->top->next;
        free(qn);
    }
    return tn;
}

void stackDestruct(struct Stack *stack) {
    while (!stackIsEmpty(stack)) {
        stackPop(stack);
    }
}

struct Tree
{
    struct tNode *root;
};

void treeInit(struct Tree *tree) {
    tree->root = NULL;
} 

void treeCreateFromPrompt(struct Tree *tree) {
    struct tNode *p, *t;
    struct Queue queue;
    int data;
    queueInit(&queue);
    printf("Enter root node data (int): ");
    scanf("%d", &data);
    if (data != -1) {
        tree->root = tNodeCreate(data);
        queueEnqueue(&queue, tree->root);
        while (!queueIsEmpty(&queue)) {
            p = queueDequeue(&queue);
            printf("Enter %d left child data (int): ", p->data);
            scanf("%d", &data);
            if (data != -1) {
                t = tNodeCreate(data);
                p->left = t;
                queueEnqueue(&queue, t);
            }
            printf("Enter %d right child data (int): ", p->data);
            scanf("%d", &data);
            if (data != -1) {
                t = tNodeCreate(data);
                p->right = t;
                queueEnqueue(&queue, t);
            }
        }
        queueDestruct(&queue);       
    }
}

void treeCreateFromArray(struct Tree *tree, int *arr, int arrSize) {
    struct tNode *p, *t;
    struct Queue queue;
    int i = 0;
    queueInit(&queue);
    tree->root = tNodeCreate(arr[i++]);
    queueEnqueue(&queue, tree->root);
    while (!queueIsEmpty(&queue) && i < arrSize) {
        p = queueDequeue(&queue);
        for (int j = 0; j < 2; j++) {
            if (arr[i] != -1) {
                t = tNodeCreate(arr[i++]);
                if (j == 0) {
                    p->left = t;
                }
                else {
                    p->right = t;
                }
                queueEnqueue(&queue, t);
            }
            else {
                i++;
            }
        }
    }
    queueDestruct(&queue);
}

void preOrderR(struct tNode *p) {
    if (p) {
        printf("%d ", p->data);
        preOrderR(p->left);
        preOrderR(p->right);
    }
}

void preOrderI(struct Tree tree) {
    if (tree.root) {
        struct tNode *p = tree.root;
        struct Stack stack;
        stackInit(&stack);
        while (!stackIsEmpty(&stack) || p != NULL) {
            if (p) {
                printf("%d ", p->data);
                stackPush(&stack, p);
                p = p->left;
            }
            else {
                p = stackPop(&stack);
                p = p->right;
            }
        }
        stackDestruct(&stack);
    }
}

void inOrderR(struct tNode *p) {
    if (p) {
        inOrderR(p->left);
        printf("%d ", p->data);
        inOrderR(p->right);
    }
}

void inOrderI(struct Tree tree) {
    if (tree.root) {
        struct tNode *p = tree.root;
        struct Stack stack;
        stackInit(&stack);
        while (!stackIsEmpty(&stack) || p != NULL) {
            if (p) {
                stackPush(&stack, p);
                p = p->left;
            }
            else {
                p = stackPop(&stack);
                printf("%d ", p->data);
                p = p->right;
            }
        }
        stackDestruct(&stack);
    }
}

void postOrderR(struct tNode *p) {
    if (p) {
        postOrderR(p->left);
        postOrderR(p->right);
        printf("%d ", p->data);
    }
}

// Iterative PostOrder using one stack
void postOrderI(struct Tree tree) {
    if (tree.root) {
        struct tNode *p = tree.root;
        struct Stack stack;
        stackInit(&stack);
        long int temp;
        while (!stackIsEmpty(&stack) || p != NULL) {
            if (p != NULL) {
                stackPush(&stack, p);
                p = p->left;
            }
            else {
                temp = (long int) stackPop(&stack);
                if (temp > 0) {
                    stackPush(&stack, (struct tNode *) -temp);
                    p = ((struct tNode *) temp)->right;
                }
                else {
                    printf("%d ", ((struct tNode *) -temp)->data);
                }
            }
        }
        stackDestruct(&stack);
    }
}

// // Iterative PostOrder using two stacks
// void postOrderI(struct Tree tree) {
//     if (tree.root) {
//         struct tNode *p = tree.root;
//         struct Stack stack1, stack2;
//         stackInit(&stack1);
//         stackInit(&stack2);
//         stackPush(&stack1, p);
//         while (!stackIsEmpty(&stack1)) {
//             p = stackPop(&stack1);
//             stackPush(&stack2, p);
//             if (p->left) {
//                 stackPush(&stack1, p->left);
//             }
//             if (p->right) {
//                 stackPush(&stack1, p->right);
//             }
//         }
//         while (!stackIsEmpty(&stack2)) {
//             p = stackPop(&stack2);;
//             printf("%d ", p->data);
//         }
//         stackDestruct(&stack1);
//         stackDestruct(&stack2);
//     }
// }

void levelOrder(struct Tree tree) {
    if (tree.root) {
        struct tNode *p;
        struct Queue queue;
        queueInit(&queue);
        queueEnqueue(&queue, tree.root);
        while (!queueIsEmpty(&queue)) {
            p = queueDequeue(&queue);   
            printf("%d ", p->data);
            if (p->left) {
                queueEnqueue(&queue, p->left);
            }
            if (p->right) {
                queueEnqueue(&queue, p->right);
            }
        }
        queueDestruct(&queue);
    }
}

int searchInOrder(int *in, int startIn, int endIn, int data) {
    for (int i = startIn; i <= endIn; i++) {
        if (in[i] == data) {
            return i;
        }
    }
    return -1;
}

struct tNode *treeFromPreInR(int *pre, int *in, int startIn, int endIn) {
    static int preI = 0;
    if (startIn > endIn) {
        return NULL;
    }
    struct tNode *tn = tNodeCreate(pre[preI]);
    preI++;
    if (startIn == endIn) {
        return tn;
    }
    int splitI = searchInOrder(in, startIn, endIn, tn->data);
    tn->left = treeFromPreInR(pre, in, startIn, splitI - 1);
    tn->right = treeFromPreInR(pre, in, splitI + 1, endIn);
    return tn;
}

struct tNode *treeFromPreInI(int *pre, int *in, int n) {
    int preI = 1;
    int inI = 0;
    bool right = false;
    struct Stack stack;
    stackInit(&stack);
    struct tNode *p = tNodeCreate(pre[0]);
    struct tNode *root = p;
    stackPush(&stack, p);
    while (preI < n) {
        if (!stackIsEmpty(&stack) && in[inI] == stack.top->tn->data) {
            p = stackPop(&stack);
            inI++;
            right = true;
        }
        else {
            struct tNode *t = tNodeCreate(pre[preI++]);
            stackPush(&stack, t);
            if (!right) {
                p->left = t;
                p = p->left;
            }
            else {
                p->right = t;
                p = p->right;
                right = false;
            }
        }
    }
    return root;
}

void arrReverse(int *arr, int n) {
    int i, j;
    i = 0;
    j = n - 1;
    int temp;
    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

struct tNode *treeFromPostInR(int *post, int *in, int startIn, int endIn) {
    static int postI = 0;
    if (startIn > endIn) {
        return NULL;
    }
    struct tNode *tn = tNodeCreate(post[postI]);
    postI++;
    if (startIn == endIn) {
        return tn;
    }
    int splitI = searchInOrder(in, startIn, endIn, tn->data);
    tn->right = treeFromPostInR(post, in, splitI + 1, endIn);
    tn->left = treeFromPostInR(post, in, startIn, splitI - 1);
    return tn;
}

struct tNode *treeFromPostInI(int *post, int *in, int n) {
    int postI = n - 2;
    int inI = n - 1;
    bool left = false;
    struct Stack stack;
    stackInit(&stack);
    struct tNode *p = tNodeCreate(post[n - 1]);
    struct tNode *root = p;
    stackPush(&stack, p);
    while (postI >= 0) {
        if (!stackIsEmpty(&stack) && in[inI] == stack.top->tn->data) {
            p = stackPop(&stack);
            inI--;
            left = true;
        }
        else {
            struct tNode *t = tNodeCreate(post[postI--]);
            stackPush(&stack, t);
            if (!left) {
                p->right = t;
                p = p->right;
            }
            else {
                p->left = t;
                p = p->left;
                left = false;
            }
        }
    }
    return root;
}

int treeNodeCountR(struct tNode *p) {
    int x, y;
    if (p) {
        x = treeNodeCountR(p->left);
        y = treeNodeCountR(p->right);
        return x + y + 1;
    }
    return 0;

}

int treeNodeCountI(struct Tree tree) {
    int result = 0;
    struct tNode *p = tree.root;
    struct Stack stack;
    stackInit(&stack);
    while (!stackIsEmpty(&stack) || p != NULL) {
        if (p) {
            stackPush(&stack, p);
            result++;
            p = p->left;
        }
        else {
            p = stackPop(&stack);
            p = p->right;
        }
    }
    return result;
}

int treeHeightR(struct tNode *p) {
    int x, y;
    if (p) {
        x = treeHeightR(p->left);
        y = treeHeightR(p->right);
        if (x > y) {
            return x + 1;
        }
        else {
            return y + 1;
        }
    }
    return 0;
}

int treeHeightI(struct Tree tree) {
    int x, max;
    long int temp;
    x = max = 0;
    bool right = false;
    struct tNode *p = tree.root;
    struct Stack stack;
    stackInit(&stack);
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

int leafNodeCountR(struct tNode *p) {
    int x, y;
    if (p) {
        x = leafNodeCountR(p->left);
        y = leafNodeCountR(p->right);
        if (p->left == NULL && p->right == NULL) {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int leafNodeCountI(struct Tree tree) {
    int result = 0;
    struct tNode *p = tree.root;
    struct Stack stack;
    stackInit(&stack);
     while (!stackIsEmpty(&stack) || p != NULL) {
        if (p) {
            stackPush(&stack, p);
            if (p->left == NULL && p->right == NULL) {
                result++;
            }
            p = p->left;
        }
        else {
            p = stackPop(&stack);
            p = p->right;
        }
    }
    return result;
}

int nonLeafNodeCountR(struct tNode *p) {
    int x, y;
    if (p) {
        x = nonLeafNodeCountR(p->left);
        y = nonLeafNodeCountR(p->right);
        if (p->left != NULL || p->right != NULL) {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int nonLeafNodeCountI(struct Tree tree) {
    int result = 0;
    struct tNode *p = tree.root;
    struct Stack stack;
    stackInit(&stack);
     while (!stackIsEmpty(&stack) || p != NULL) {
        if (p) {
            stackPush(&stack, p);
            if (p->left != NULL || p->right != NULL) {
                result++;
            }
            p = p->left;
        }
        else {
            p = stackPop(&stack);
            p = p->right;
        }
    }
    return result;
}

int nodeDegOneCountR(struct tNode *p) {
    int x, y;
    if (p) {
        x = nodeDegOneCountR(p->left);
        y = nodeDegOneCountR(p->right);
        if (p->left != NULL ^ p->right != NULL) {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int nodeDegOneCountI(struct Tree tree) {
    int result = 0;
    struct tNode *p = tree.root;
    struct Stack stack;
    stackInit(&stack);
     while (!stackIsEmpty(&stack) || p != NULL) {
        if (p) {
            stackPush(&stack, p);
            if (p->left != NULL ^ p->right != NULL) {
                result++;
            }
            p = p->left;
        }
        else {
            p = stackPop(&stack);
            p = p->right;
        }
    }
    return result;
}

int nodeDegTwoCountR(struct tNode *p) {
    int x, y;
    if (p) {
        x = nodeDegTwoCountR(p->left);
        y = nodeDegTwoCountR(p->right);
        if (p->left != NULL && p->right != NULL) {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int nodeDegTwoCountI(struct Tree tree) {
    int result = 0;
    struct tNode *p = tree.root;
    struct Stack stack;
    stackInit(&stack);
     while (!stackIsEmpty(&stack) || p != NULL) {
        if (p) {
            stackPush(&stack, p);
            if (p->left != NULL && p->right != NULL) {
                result++;
            }
            p = p->left;
        }
        else {
            p = stackPop(&stack);
            p = p->right;
        }
    }
    return result;
}

int main() {
    struct Tree tree1, tree2, tree3;
    treeInit(&tree1);
    treeInit(&tree2);
    treeInit(&tree3);

    // Binary tree created by user prompt

    // printf("Tree 1\n\n");
    // treeCreateFromPrompt(&tree1);
    // printf("\nPreorder\n");
    // preOrderR(tree1.root);
    // printf("\n");
    // printf("Inorder\n");
    // inOrderR(tree1.root);
    // printf("\n");
    // printf("Postorder\n");
    // postOrderR(tree1.root);
    // printf("\n");
    // printf("Level Order\n");
    // levelOrder(tree1);
    // printf("\n");

    // Binary tree created from array
    
    // printf("\nTree 2\n");
    // int arr[] = {5, 1, 7, -1, 2, 4, 8};
    // int arrSize = (int) sizeof(arr)/sizeof(int);
    // treeCreateFromArray(&tree2, arr, arrSize);
    // printf("Preorder\n");
    // preOrderI(tree2);
    // printf("\n");
    // printf("Inorder\n");
    // inOrderI(tree2);
    // printf("\n");
    // printf("Postorder\n");
    // postOrderI(tree2);
    // printf("\n");
    // printf("Level Order\n");
    // levelOrder(tree2);
    // printf("\n");
    // printf("Height\n");
    // printf("%d", treeHeightI(tree2));
    // printf("\n");
    // printf("Count\n");
    // printf("%d", treeNodeCountI(tree2));
    // printf("\n");

    printf("\nTree 3\n");
    int post[] = {2, 1, 4, 8, 7, 5};
    int in[] = {1, 2, 5, 4, 7, 8};
    int n = (int) sizeof(post)/sizeof(int);
    arrReverse(post, n);
    tree3.root = treeFromPostInR(post, in, 0, n - 1);
    printf("Preorder\n");
    preOrderI(tree3);
    printf("\n");
    printf("Inorder\n");
    inOrderI(tree3);
    printf("\n");
    printf("Postorder\n");
    postOrderI(tree3);
    printf("\n");
    printf("Level Order\n");
    levelOrder(tree3);
    printf("\n");
    printf("Height\n");
    printf("%d", treeHeightI(tree3));
    printf("\n");
    printf("Count\n");
    printf("%d", treeNodeCountI(tree3));
    printf("\n");
    printf("Leaf Node Count\n");
    printf("%d", leafNodeCountI(tree3));
    printf("\n");
    return 0;
}