#include <iostream>

class Deque {
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Deque(int size) {
        this->size = size + 1;
        front = rear = 0;
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

bool Deque::isEmpty() {
    if (front == rear) {
        return true;
    }
    return false;
}

bool Deque::isFull() {
    if (front == (rear + 1) % size) {
        return true;
    }
    return false;
}

void Deque::enqueueFront(int data) {
    if (front == (rear + 1) % size) {
        std::cout<<"Deque Overflow\n";
    }
    else {
        Q[front] = data;
        front = (front - 1) % size;
        if (front < 0) {
            front += size;
        }
    }
}

void Deque::enqueueRear(int data) {
    if (isFull()) {
        std::cout<<"Deque Overflow\n";
    }
    else {
        rear = (rear + 1) % size;
        Q[rear] = data;
    }
}

int Deque::dequeueFront() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Deque Underflow\n";
    }
    else {
        front = (front + 1) % size;
        x = Q[front];
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
        rear = (rear - 1) % size;
        if (rear < 0) {
            rear += size;
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
    Deque deq(4);
    deq.enqueueRear(3);
    deq.enqueueRear(5);
    deq.enqueueRear(7);
    deq.enqueueRear(9);
    deq.enqueueRear(11);
    deq.display();
    deq.dequeueFront();
    deq.dequeueFront();
    deq.dequeueFront();
    deq.dequeueFront();
    deq.dequeueFront();
    deq.display();
    std::cout<<deq.getFrontIndex()<<" "<<deq.getRearIndex()<<std::endl;
    return 0;
}