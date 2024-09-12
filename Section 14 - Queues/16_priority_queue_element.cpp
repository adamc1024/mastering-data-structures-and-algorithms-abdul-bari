#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        next = NULL;
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
    bool isEmpty();
    void display();
    void enqueue(int data);
    int dequeue();
};

bool Queue::isEmpty() {
    if (front == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void Queue::display() {
    std::cout<<"[";
    struct Node *p = front;
    while (p) {
        std::cout<<p->data;
        if (p->next) {
            std::cout<<", ";
        }
        p = p->next;
    }
    std::cout<<"]\n";
}

void Queue::enqueue(int data) {
    Node *t = new Node(data);
    if (t == NULL) {
        std::cout<<"Queue Overflow\n";
    }
    else {
        if (isEmpty()) {
            front = rear = t;
        }
        else if (rear != NULL && data >= rear->data) {
            rear->next = t;
            rear = t;
        }
        else {
            struct Node *p, *q;
            p = front;
            q = NULL;
            while (p) {
                if (data < p->data) {
                    t->next = p;
                    if (q) {
                        q->next = t;
                    }
                    else {
                        front = t;
                    }
                    break;
                }
                q = p;
                p = p->next;
            }
        }
    }
}

int Queue::dequeue() {
    int x = -1;
    if (isEmpty()) {
        std::cout<<"Queue Underflow\n";
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
        free(p);
    }
    return x;
}

int main() {
    Queue q;
    int arrNums[] = {9, 19, 4, 67, 3, 4, 8, 6, 12, -1, 0, 45, -100, 6};
    for (int i = 0; i < 14; i++) {
        q.enqueue(arrNums[i]);
        q.display();
    }
    while (!q.isEmpty()) {
        std::cout<<q.dequeue()<<std::endl;
    }
    return 0;
}