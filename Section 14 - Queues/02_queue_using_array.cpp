#include <iostream>

class Queue {
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(int size) {
        this->size = size;
        Q = new int[this->size];
        front = rear = -1;
    }
    ~Queue() {
        delete [] Q;
    }
    void display();
    void enqueue(int data);
    int dequeue();
};

void Queue::display() {
    std::cout<<"[";
    for (int i = front + 1; i <= rear; i++) {
        std::cout<<Q[i];
        if (i < rear) {
            std::cout<<", ";
        }
    }
    std::cout<<"]\n";
} 

void Queue::enqueue(int data) {
    if (rear == size - 1) {
        std::cout<<"Queue Is Full\n";
    }
    else {
        rear++;
        Q[rear] = data;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (front == rear) {
        std::cout<<"Queue is Empty\n";
    }
    else {
        front++;
        x = Q[front];
    }
    return x;
}

int main() {
    Queue q(3);
    q.enqueue(10);
    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(9);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}