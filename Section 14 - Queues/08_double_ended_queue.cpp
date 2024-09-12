#include <iostream>

class Deque {
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Deque(int size) {
        this->size = size;
        front = rear = -1;
        Q = new int[this->size];
    }
    ~Deque() {
        delete [] Q;
    }
    void display();
    bool isEmpty();
    bool isFull();
    void enqueueFront(int data);
    void enqueueRear(int data);
    int dequeueFront();
    int dequeueRear();
    int getFrontIndex();
    int getRearIndex();
};

void Deque::display() {
    std::cout<<"[";
    for (int i = front + 1; i <= rear; i++) {
        std::cout<<Q[i];
        if (i < rear) {
            std::cout<<", ";
        }
    }
    std::cout<<"]\n";
}

bool Deque::isEmpty() {
    if (front == rear) {
        return true;
    }
    return false;
}

bool Deque::isFull() {
    if (rear == size -1) {
        return true;
    }
    return false;
}

void Deque::enqueueFront(int data) {
    if (front == -1) {
        std::cout<<"Deque Overflow\n";
    }
    else {
        Q[front] = data;
        front--;
    }
}

void Deque::enqueueRear(int data) {
    if (isFull()) {
        std::cout<<"Deque Overflow\n";
    }
    else {
        rear++;
        Q[rear] = data;
    }
}

int Deque::dequeueFront() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Deque Underflow\n";
    }
    else {
        front++;
        x = Q[front];
        if (isEmpty()) {
            front = rear = -1;
        }
    }
    return x;
}

int Deque::dequeueRear() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Deque Underflow\n";
    }
    else {
        x = Q[rear];
        rear--;
        if (isEmpty()) {
            front = rear = -1;
        }
    }
    return x;
}

int Deque::getFrontIndex() {
    return front;
}

int Deque::getRearIndex() {
    return rear;
}

int main() {
    struct Deque deq(4);
    deq.enqueueRear(3);
    deq.enqueueRear(5);
    deq.enqueueRear(7);
    deq.enqueueRear(9);
    deq.enqueueRear(11);
    deq.display();
    deq.dequeueRear();
    deq.display();
    deq.dequeueFront();
    deq.display();
    deq.enqueueFront(8);
    deq.display();
    deq.dequeueFront();
    deq.display();
    deq.dequeueFront();
    deq.display();
    deq.dequeueRear();
    deq.display();
    std::cout<<deq.getFrontIndex()<<" "<<deq.getRearIndex()<<std::endl;
    return 0;
}