#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node() {
        next = NULL;
    }
    Node(int data) {
        next = NULL;
        this->data = data;
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
    void display();
    int isEmpty();
    int isFull();
    void enqueue(int data);
    int dequeue();
    int getFront();
    int getRear();
};

int Queue::isEmpty() {
    if (front == NULL && rear == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void Queue::display() {
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

int Queue::isFull() {
    struct Node *t = new Node();
    if (t == NULL) {
        return 1;
    }
    else {
        delete t;
        return 0;
    }
}

void Queue::enqueue(int data) {
    if (isFull()) {
        std::cout<<"Queue Is Full\n";
    }
    else {
        Node *t = new Node(data);
        if (front == NULL && rear == NULL) {
            front = t;
            rear = t;
        }
        else {
            rear->next = t;
            rear = rear->next;
        }
    }
}

int Queue::dequeue() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Queue is Empty\n";
    }
    else {
        Node *p = front;
        x = p->data;
        if (front == rear) {
            front = NULL;
            rear = NULL;
        }
        else {
            front = front->next;
        }
        delete p;
    }
    return x;
}

int Queue::getFront() {
    if (front) {
        return front->data;
    }
    return -1;
}

int Queue::getRear() {
    if (rear) {
        return rear->data;
    }
    return -1;
}

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(9);
    q.display();
    std::cout<<q.dequeue()<<std::endl;
    std::cout<<q.dequeue()<<std::endl;
    std::cout<<q.dequeue()<<std::endl;
    q.display();
    std::cout<<"Front: "<<q.getFront()<<std::endl;
    std::cout<<"Rear: "<<q.getRear()<<std::endl;
    return 0;
}