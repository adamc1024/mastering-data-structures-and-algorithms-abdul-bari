#include <iostream>

class Queue {
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(int size) {
        this->size = size + 1;
        front = rear = 0;
        Q = new int[this->size];
    }
    ~Queue() {
        delete [] Q;
    }
    void display();
    int isEmpty();
    int isFull();
    void enqueue(int data);
    int dequeue();
};

void Queue::display() {
    std::cout<<"[";
    int i = (front + 1) % size;
    while (i != (rear +1) % size) {
        std::cout<<Q[i];
        if (i != rear) {
            std::cout<<", ";
        }
        i = (i + 1) % size;
    }
    std::cout<<"]\n";
} 

int Queue::isEmpty() {
    if (front == rear) {
        return 1;
    }
    else {
        return 0;
    }
}

int Queue::isFull() {
    if (front == (rear + 1) % size) {
        return 1;
    }
    else {
        return 0;
    }
}

void Queue::enqueue(int data) {
    if (isFull()) {
        std::cout<<"Queue Is Full\n";
    }
    else {
        rear = (rear + 1) % size;
        Q[rear] = data;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Queue is Empty\n";
    }
    else {
        front = (front + 1) % size;
        x = Q[(front + 1) % size];
    }
    return x;
}

int main() {
    Queue q(3);
    q.enqueue(10);
    q.enqueue(4);
    q.enqueue(8);
    q.display();
    q.dequeue();
    q.enqueue(9);
    q.enqueue(9);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}