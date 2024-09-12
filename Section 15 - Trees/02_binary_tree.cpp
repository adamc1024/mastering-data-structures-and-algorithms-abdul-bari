#include <iostream>

class tNode
{
public:
    tNode *left;
    int data;
    tNode *right;
    tNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class qNode
{
public:
    tNode *tn;
    qNode *next;
    qNode(tNode *tn) {
        this->tn = tn;
        next = NULL;
    }
};

class Queue
{
private:
    qNode *front;
    qNode *rear;
public:
    Queue() {
        front = rear = NULL;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    bool isEmpty();
    void enqueue(tNode *tn);
    tNode *dequeue();
};

bool Queue::isEmpty() {
    if (front == NULL && rear == NULL) {
        return true;
    }
    return false;
}

void Queue::enqueue(tNode *tn) {
    qNode *t = new qNode(tn);
    if (t == NULL) {
        std::cout<<"Queue Overflow\n";
    }
    else {
        if (isEmpty()) {
            front = rear = t;
        }
        else {
            rear->next = t;
            rear = t;
        }
    }
}

tNode *Queue::dequeue() {
    tNode *tn = NULL;
    if (isEmpty()) {
        std::cout<<"Queue Underflow\n";
    }
    else {
        qNode *p = front;
        tn = front->tn;
        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
        }
        delete p;
    }
    return tn;
}

class Stack
{
private:
    qNode *top;
public:
    Stack() {
        top = NULL;
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    tNode *getTop();
    bool isEmpty();
    void push(tNode *tn);
    tNode *pop();
};

tNode *Stack::getTop() {
    return top->tn;
}

bool Stack::isEmpty() {
    if (top == NULL) {
        return true;
    }
    return false;
}

void Stack::push(tNode *tn) {
    qNode *t = new qNode(tn);
    if (isEmpty()) {
        top = t;
    }
    else {
        t->next = top;
        top = t;
    }
}

tNode *Stack::pop() {
    tNode *tn = NULL;
    if (isEmpty()) {
        std::cout<<"Stack Underflow\n";
    }
    else {
        qNode *qn = top;
        tn = top->tn;
        top = top->next;
        delete qn;
    }
    return tn;
}

class Tree
{
private:
    tNode *root;
public:
    Tree(bool prompt);
    Tree(int *arr, int arrSize);
    tNode *getRoot();
    void setRoot(tNode *tn);
    // Overloaded functions
    void preOrderR() {
        preOrderR(root);
    }
    void preOrderR(tNode *p);
    void preOrderI();
    void inOrderR() {
        inOrderR(root);
    }
    void inOrderR(tNode *p);
    void inOrderI();
    void postOrderR() {
        postOrderR(root);
    }
    void postOrderR(tNode *p);
    void postOrderI();
    void levelOrder();
    int countR(tNode *p);
    int countR() {
        return countR(root);
    }
    int countI();
    int heightR(tNode *p);
    int heightR() {
        return heightR(root);
    }
    int heightI();
    int countLeafR(tNode*p);
    int countLeafR() {
        return countLeafR(root);
    }
    int countLeafI();
    int countNonLeafR(tNode*p);
    int countNonLeafR() {
        return countNonLeafR(root);
    }
    int countNonLeafI();
    int countDegreeOneR(tNode*p);
    int countDegreeOneR() {
        return countDegreeOneR(root);
    }
    int countDegreeOneI();
    int countDegreeTwoR(tNode*p);
    int countDegreeTwoR() {
        return countDegreeTwoR(root);
    }
    int countDegreeTwoI();
};

Tree::Tree(bool prompt) {
    root = NULL;
    if (!prompt) {
        return;
    }
    tNode *p, *t;
    Queue queue;
    int data = -1;
    std::cout<<"Enter root node data (int): ";
    std::cin>>data;
    if (data != -1) {
        root = new tNode(data);
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            p = queue.dequeue();
            for (int i = 0; i < 2; i++) {
                if (i == 0) {
                    std::cout<<"Enter "<<p->data<<" left child data (int): ";
                }
                else {
                    std::cout<<"Enter "<<p->data<<" right child data (int): ";
                }
                std::cin>>data;
                if (data != -1) {
                    t = new tNode(data);
                    if (i == 0) {
                        p->left = t;
                    }
                    else {
                        p->right = t;
                    }
                    queue.enqueue(t);
                }
            }
        }      
    }
}

Tree::Tree(int *arr, int arrSize) {
    root = NULL;
    tNode *p, *t;
    Queue queue;
    int i = 0;
    if (arr[i] != -1) {
        root = new tNode(arr[i++]);
        queue.enqueue(root);
        while (!queue.isEmpty() && i < arrSize) {
            p = queue.dequeue();
            for (int j = 0; j < 2; j++) {
                if (arr[i] != -1) {
                    t = new tNode(arr[i++]);
                    if (j == 0) {
                        p->left = t;
                    }
                    else {
                        p->right = t;
                    }
                    queue.enqueue(t);
                }
                else {
                    i++;
                }
            }
        }
    }
}

tNode *Tree::getRoot() {
    return root;
}

void Tree::setRoot(tNode *tn) {
    root = tn;
}

void Tree::preOrderR(tNode *p) {
    if (p) {
        std::cout<<p->data<<" ";
        preOrderR(p->left);
        preOrderR(p->right);
    }
}

void Tree::inOrderR(tNode *p) {
    if (p) {
        inOrderR(p->left);
        std::cout<<p->data<<" ";
        inOrderR(p->right);
    }
}

void Tree::postOrderR(tNode *p) {
    if (p) {
        postOrderR(p->left);
        postOrderR(p->right);
        std::cout<<p->data<<" ";
    }
}

void Tree::levelOrder() {
    if (root) {
        tNode *p;
        Queue queue;
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            p = queue.dequeue();   
            std::cout<<p->data<<" ";
            if (p->left) {
                queue.enqueue(p->left);
            }
            if (p->right) {
                queue.enqueue(p->right);
            }
        }
    }
}

void Tree::preOrderI() {
    if (root) {
        tNode *p = root;
        Stack stack;
        while (!stack.isEmpty() || p != NULL) {
            if (p) {
                std::cout<<p->data<<" ";
                stack.push(p);
                p = p->left;
            }
            else {
                p = stack.pop();
                p = p->right;
            }
        }
    }
}

void Tree::inOrderI() {
    if (root) {
        tNode *p = root;
        Stack stack;
        while (!stack.isEmpty() || p != NULL) {
            if (p) {
                stack.push(p);
                p = p->left;
            }
            else {
                p = stack.pop();
                std::cout<<p->data<<" ";
                p = p->right;
            }
        }
    }
}

// Iterative PostOrder using one stack
void Tree::postOrderI() {
    if (root) {
        tNode *p = root;
        Stack stack;
        long int temp;
        while (!stack.isEmpty() || p != NULL) {
            if (p != NULL) {
                stack.push(p);
                p = p->left;
            }
            else {
                temp = (long int) stack.pop();
                if (temp > 0) {
                    stack.push((tNode *) -temp);
                    p = ((tNode *) temp)->right;
                }
                else {
                    std::cout<<((tNode *) -temp)->data<<" ";
                }
            }
        }
    }
}

// // Iterative PostOrder using two stacks
// void Tree::postOrderI() {
//     if (root) {
//         tNode *p = root;
//         Stack stack1, stack2;
//         stack1.push(p);
//         while (!stack1.isEmpty()) {
//             p = stack1.pop();
//             stack2.push(p);
//             if (p->left) {
//                 stack1.push(p->left);
//             }
//             if (p->right) {
//                 stack1.push(p->right);
//             }
//         }
//         while (!stack2.isEmpty()) {
//             p = stack2.pop();
//             std::cout<<p->data<<" ";
//         }
//     }
// }

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
    tNode *tn = new tNode(pre[preI]);
    preI++;
    if (startIn == endIn) {
        return tn;
    }
    int splitI = searchInOrder(in, startIn, endIn, tn->data);
    tn->left = treeFromPreInR(pre, in, startIn, splitI - 1);
    tn->right = treeFromPreInR(pre, in, splitI + 1, endIn);
    return tn;
}

tNode *treeFromPreInI(int *pre, int *in, int n) {
    int preI = 1;
    int inI = 0;
    bool right = false;
    Stack s;
    tNode *p = new tNode(pre[0]);
    tNode *root = p;
    s.push(p);
    while (preI < n) {
        if (!s.isEmpty() && in[inI] == s.getTop()->data) {
            p = s.pop();
            inI++;
            right = true;
        }
        else {
            tNode *t = new tNode(pre[preI++]);
            s.push(t);
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
    tNode *tn = new tNode(post[postI]);
    postI++;
    if (startIn == endIn) {
        return tn;
    }
    int splitI = searchInOrder(in, startIn, endIn, tn->data);
    tn->right = treeFromPostInR(post, in, splitI + 1, endIn);
    tn->left = treeFromPostInR(post, in, startIn, splitI - 1);
    return tn;
}

tNode *treeFromPostInI(int *post, int *in, int n) {
    int postI = n - 2;
    int inI = n - 1;
    bool left = false;
    Stack s;
    tNode *p = new tNode(post[n - 1]);
    tNode *root = p;
    s.push(p);
    while (postI >= 0) {
        if (!s.isEmpty() && in[inI] == s.getTop()->data) {
            p = s.pop();
            inI--;
            left = true;
        }
        else {
            tNode *t = new tNode(post[postI--]);
            s.push(t);
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

int Tree::countR(tNode *p) {
    int x, y;
    if (p) {
        x = countR(p->left);
        y = countR(p->right);
        return x + y + 1;
    }
    return 0;

}

int Tree::countI() {
    int result = 0;
    tNode *p = root;
    Stack stack;
    while (!stack.isEmpty() || p != NULL) {
        if (p) {
            stack.push(p);
            result++;
            p = p->left;
        }
        else {
            p = stack.pop();
            p = p->right;
        }
    }
    return result;
}

int Tree::heightR(tNode *p) {
    int x, y;
    if (p) {
        x = heightR(p->left);
        y = heightR(p->right);
        if (x > y) {
            return x + 1;
        }
        else {
            return y + 1;
        }
    }
    return 0;
}

int Tree::heightI() {
    int x, max;
    long int temp;
    x = max = 0;
    bool right = false;
    tNode *p = root;
    Stack stack;
    while (!stack.isEmpty() || p != NULL) {
        if (p) {
            stack.push(p);
            x++;
            if (x > max) {
                max = x;
            }
            p = p->left;
        }
        else {
            temp = (long int) stack.pop();
            if (temp > 0) {
                stack.push((tNode *) -temp);
                p = ((tNode *) temp)->right;
            }
            else {
                x--;
            }
        }
    }
    return max;
}

int Tree::countLeafR(tNode *p) {
    int x, y;
    if (p) {
        x = countLeafR(p->left);
        y = countLeafR(p->right);
        if (p->left == NULL && p->right == NULL) {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int Tree::countLeafI() {
    int result = 0;
    tNode *p = root;
    Stack stack;
     while (!stack.isEmpty() || p != NULL) {
        if (p) {
            stack.push(p);
            if (p->left == NULL && p->right == NULL) {
                result++;
            }
            p = p->left;
        }
        else {
            p = stack.pop();
            p = p->right;
        }
    }
    return result;
}

int Tree::countNonLeafR(tNode *p) {
    int x, y;
    if (p) {
        x = countNonLeafR(p->left);
        y = countNonLeafR(p->right);
        if (p->left != NULL || p->right != NULL) {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int Tree::countNonLeafI() {
    int result = 0;
    tNode *p = root;
    Stack stack;
     while (!stack.isEmpty() || p != NULL) {
        if (p) {
            stack.push(p);
            if (p->left != NULL || p->right != NULL) {
                result++;
            }
            p = p->left;
        }
        else {
            p = stack.pop();
            p = p->right;
        }
    }
    return result;
}

int Tree::countDegreeOneR(tNode *p) {
    int x, y;
    if (p) {
        x = countDegreeOneR(p->left);
        y = countDegreeOneR(p->right);
        if (p->left != NULL ^ p->right != NULL) {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int Tree::countDegreeOneI() {
    int result = 0;
    tNode *p = root;
    Stack stack;
     while (!stack.isEmpty() || p != NULL) {
        if (p) {
            stack.push(p);
            if (p->left != NULL ^ p->right != NULL) {
                result++;
            }
            p = p->left;
        }
        else {
            p = stack.pop();
            p = p->right;
        }
    }
    return result;
}

int Tree::countDegreeTwoR(tNode *p) {
    int x, y;
    if (p) {
        x = countDegreeTwoR(p->left);
        y = countDegreeTwoR(p->right);
        if (p->left != NULL && p->right != NULL) {
            return x + y + 1;
        }
        return x + y;
    }
    return 0;
}

int Tree::countDegreeTwoI() {
    int result = 0;
    tNode *p = root;
    Stack stack;
     while (!stack.isEmpty() || p != NULL) {
        if (p) {
            stack.push(p);
            if (p->left != NULL && p->right != NULL) {
                result++;
            }
            p = p->left;
        }
        else {
            p = stack.pop();
            p = p->right;
        }
    }
    return result;
}

int main() {

    // Binary tree created by user prompt

    // std::cout<<"Tree from user prompt\n\n";
    // Tree tree1;
    // std::cout<<"\npreOrder\n";
    // tree1.preOrderR();
    // std::cout<<"\n";
    // std::cout<<"inOrder\n";
    // tree1.inOrderR();
    // std::cout<<"\n";
    // std::cout<<"postOrder\n";
    // tree1.postOrderR();
    // std::cout<<"\n";

    // Binary tree created from array

    // int numArr[] = {5, 1, 7, -1, 2, 4, 8};
    // int arrSize = (int) sizeof(numArr)/sizeof(int);
    // std::cout<<"\nTree from array\n";
    // Tree tree2(numArr, arrSize);
    // std::cout<<"preOrder\n";
    // tree2.preOrderI();
    // std::cout<<"\n";
    // std::cout<<"inOrder\n";
    // tree2.inOrderI();
    // std::cout<<"\n";
    // std::cout<<"postOrder\n";
    // tree2.postOrderI();
    // std::cout<<"\n";
    // std::cout<<"levelOrder\n";
    // tree2.levelOrder();
    // std::cout<<"\n";

    Tree tree3(false);
    int pre[] = {8, 3, 12, 4, 9, 7, 5, 10, 6, 2};    
    int in[] = {12, 9, 4, 7, 3, 8, 10, 5, 2, 6};
    int post[] = {9, 7, 4, 12, 3, 10, 2, 6, 5, 8};
    int n = (int) sizeof(pre)/sizeof(int);
    tree3.setRoot(treeFromPostInI(post, in, n));
    std::cout<<"preOrderI\n";
    tree3.preOrderI();
    std::cout<<"\n";
    std::cout<<"preOrderR\n";
    tree3.preOrderR();
    std::cout<<"\n";
    std::cout<<"inOrderI\n";
    tree3.inOrderI();
    std::cout<<"\n";
    std::cout<<"inOrderR\n";
    tree3.inOrderR();
    std::cout<<"\n";
    std::cout<<"postOrderI\n";
    tree3.postOrderI();
    std::cout<<"\n";
    std::cout<<"postOrderR\n";
    tree3.postOrderR();
    std::cout<<"\n";
    std::cout<<"countI\n";
    std::cout<<tree3.countI()<<"\n";
    std::cout<<"countR\n";
    std::cout<<tree3.countR()<<"\n";
    std::cout<<"heightI\n";
    std::cout<<tree3.heightI()<<"\n";
    std::cout<<"heightR\n";
    std::cout<<tree3.heightR()<<"\n";
    std::cout<<"countLeafI\n";
    std::cout<<tree3.countLeafI()<<"\n";
    std::cout<<"countLeafR\n";
    std::cout<<tree3.countLeafR()<<"\n";
    std::cout<<"countNonLeafI\n";
    std::cout<<tree3.countNonLeafI()<<"\n";
    std::cout<<"countNonLeafR\n";
    std::cout<<tree3.countNonLeafR()<<"\n";
    std::cout<<"countDegreeOneI\n";
    std::cout<<tree3.countDegreeOneI()<<"\n";
    std::cout<<"countDegreeOneR\n";
    std::cout<<tree3.countDegreeOneR()<<"\n";
    std::cout<<"countDegreeTwoI\n";
    std::cout<<tree3.countDegreeTwoI()<<"\n";
    std::cout<<"countDegreeTwoR\n";
    std::cout<<tree3.countDegreeTwoR()<<"\n";
    return 0;
}