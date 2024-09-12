#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node() {
        next = NULL;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

class Stack {
private:
    Node *top;
    int size;
public:
    Stack() {
        top = NULL;
        size = 0;
    }
    Stack(Node *top) {
        this->top = top;
        size = 1;
    }
    Stack(int *arr, int n) {
        top = NULL;
        size = 0;
        for (int i = 0; i < n; i ++) {
            push(arr[i]);
            size++;
        }
    }
    Node *getTop();
    int getSize();
    void display();
    int peek(int index);
    void push(int data);
    int pop();
    int isEmpty();
};

Node *Stack::getTop() {
    return top;
}

int Stack::getSize() {
    return size;
}

void Stack::display() {
    Node *p = top;
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

int Stack::peek(int index) {
    if (index > size || index < 1) {
        std::cout<<"Invalid Index"<<std::endl;
    }
    else {
        Node *p = top;
        int i = 1;
        while (i <= size) {
            if (i == index) {
                return p->data;
            }
            p = p->next;
            i++;
        }
    }
    return -1;
}

void Stack::push(int data) {
    Node *p = new Node();
    if (p == NULL) {
        std::cout<<"Stack Overflow"<<std::endl;
    }
    else {
        p->data = data;
        p->next = top;
        top = p;
    }
}

int Stack::pop() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Stack Underflow"<<std::endl;
    }
    else {
        x = top->data;
        Node *p = top;
        top = top->next;
        delete p;
        size--;
    }
    return x;
}

int Stack::isEmpty() {
    if (top == NULL) {
        return 1;
    }
    return 0;
}

int main() {
    int arr[] = {51, 42, 73, 84};
    Stack st = Stack(arr, 4);
    st.display();
    std::cout<<"Top is "<<st.getTop()->data<<std::endl;
    std::cout<<"Size is "<<st.getSize()<<std::endl;
    std::cout<<st.peek(1)<<std::endl;
    std::cout<<"Popped value is "<<st.pop()<<std::endl;
    std::cout<<"Top is "<<st.getTop()->data<<std::endl;
    std::cout<<"Size is "<<st.getSize()<<std::endl;
    return 0;
}