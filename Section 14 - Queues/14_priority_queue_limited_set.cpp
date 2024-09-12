#include <iostream>

class Node {
public:
    char data;
    Node *next;
    Node() {
        data = '\0';
        next = NULL;
    }
    Node(char data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
private:
    Node *front;
    Node *rear;
public:
    Queue() {
        front = rear = NULL;
    }
    ~Queue() {
        Node *p, *q;
        p = front;
        if (p) {
            while (p) {
                q = p;
                p = p->next;
                delete q;
            }
        }
    }
    bool isFull();
    bool isEmpty();
    void enqueue(char data);
    char dequeue();
    void display();
};

bool Queue::isFull() {
    Node *t = new Node;
    if (t == NULL) {
        return true;
    }
    delete t;
    return false;

}

bool Queue::isEmpty() {
    if (front == NULL) {
        return true;
    }
    return false;
}

void Queue::enqueue(char data) {
    Node *t = new Node(data);
    if (isFull()) {
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

char Queue::dequeue() {
    char x = '\0';
    Node *p;
    if (!isEmpty()) {
        p = front;
        x = p->data;
        front = front->next;
        delete p;
    }
    else {
        std::cout<<"Queue Underflow\n";
    }
    return x;
}

void Queue::display() {
    Node *p = front;
    std::cout<<"[";
    while (p) {
        std::cout<<p->data;
        if (p->next) {
            std::cout<<", ";
        }
        p = p->next;
    }
    std::cout<<"]\n";
}

class PQueue {
private:
    Queue p1;
    Queue p2;
    Queue p3;
public:
    void enqueue(int priority, char data);
    char dequeue();
    void display();
};

void PQueue::enqueue(int priority, char data) {
    if (priority == 1) {
        p1.enqueue(data);
    }
    else if (priority == 2) {
        p2.enqueue(data);
    }
    else if (priority == 3) {
        p3.enqueue(data);
    }
}

char PQueue::dequeue() {
    if (!p1.isEmpty()) {
        return p1.dequeue();
    }
    if (!p2.isEmpty()) {
        return p2.dequeue();
    }
    if (!p3.isEmpty()) {
        return p3.dequeue();
    }
    return '\0';
}

void PQueue::display() {
    p1.display();
    p2.display();
    p3.display();
}

int main() {
    PQueue pque;
    char chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    char priorities[] = {1, 1, 2, 3, 2, 1, 2, 3, 2, 2, 1};
    for (int i = 0; i < 11; i++) {
        pque.enqueue(priorities[i], chars[i]);
    }
    pque.display();
    for (int i = 0; i < 11; i++) {
        std::cout<<pque.dequeue()<<"\n";
    }
    pque.display();
    return 0;
}