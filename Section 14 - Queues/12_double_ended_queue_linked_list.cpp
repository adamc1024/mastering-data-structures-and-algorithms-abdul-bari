#include <iostream>

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    Node() {
        data = -1;
        prev = next = NULL;
    }
    Node(int data) {
        this->data = data;
        prev = next = NULL;
    }
};

class Deque {
private:
    Node *front;
    Node *rear;
public:
    Deque() {
        front = rear = NULL;
    }
    ~Deque() {
        if (!isEmpty()) {
            Node *p = front;
            while (front) {
                front = front->next;
                delete p;
                p = front;
            }
            rear = NULL;
        }
    }
    bool isEmpty();
    bool isFull();
    void display();
    void enqueueFront(int data);
    void enqueueRear(int data);
    int dequeueFront();
    int dequeueRear();
};

bool Deque::isEmpty() {
    if (front == NULL) {
        return true;
    }
    return false;
}

bool Deque::isFull() {
    Node *t = new Node;
    if (t == NULL) {
        return true;
    }
    return false;
}

void Deque::display() {
    std::cout<<"[";
    Node *p = front;
    while (p) {
        std::cout<<p->data;
        if (p->next) {
            std::cout<<", ";
        }
        p = p->next;
    }
    std::cout<<"]\n";
}

void Deque::enqueueFront(int data) {
    Node *t = new Node(data);
    if (isEmpty()) {
        front = rear = t;
    }
    else {
        if (isFull()) {
            std::cout<<"Deque Overflow\n";
        }
        else {
            t->next = front;
            front->prev = t;
            front = t;
        }
    }
}

void Deque::enqueueRear(int data) {
    Node *t = new Node(data);
    if (isEmpty()) {
        front = rear = t;
    }
    else {
        if (isFull()) {
            std::cout<<"Deque Overflow\n";
        }
        else {
            t->prev = rear;
            rear->next = t;
            rear = t;
        }
    }
}

int Deque::dequeueFront() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Deque Underflow\n";
    }
    else {
        Node *p = front;
        x = p->data;
        front = front->next;
        delete p;
        front->prev = NULL;
    }
    return x;
}

int Deque::dequeueRear() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Deque Underflow\n";
    }
    else {
        Node *p = rear;
        x = p->data;
        rear = rear->prev;
        delete p;
        rear->next = NULL;
    }
    return x;
}



int main() {
    struct Deque deq;
    deq.enqueueRear(0);
    deq.display();
    deq.enqueueFront(-1);
    deq.display();
    deq.enqueueRear(1);
    deq.display();
    deq.dequeueFront();
    deq.display();
    deq.dequeueRear();
    deq.display();
    return 0;
}