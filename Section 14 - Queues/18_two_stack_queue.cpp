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

class Stack {
private:
    Node *top;
public:
    Stack() {
        top = NULL;
    }
    void display();
    void push(int data);
    int pop();
    Node *getTop();
};

void Stack::display() {
    Node *p = top;
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

void Stack::push(int data) {
    Node *t = new Node(data);
    if (t != NULL) {
        if (top == NULL) {
            top = t;
        }
        else {
            t->next = top;
            top = t;
        }
    }
    else {
        std::cout<<"Stack Overflow\n";
    }
}

int Stack::pop() {
    int x = -1;
    if (top != NULL) {
        Node *p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    else {
        std::cout<<"Stack Underflow\n";
    }
    return x;
}

Node * Stack::getTop() {
    return top;
}

class Queue {
public:
    Stack stIn;
    Stack stOut;
    void display();
    void enqueue(int data);
    int dequeue();
};

void Queue::display() {
    std::cout<<"In: ";
    stIn.display();
    std::cout<<"Out: ";
    stOut.display();
}

void Queue::enqueue(int data) {
    stIn.push(data);
}   

int Queue::dequeue() {
    int x = -1;
    if (stOut.getTop() != NULL){
        x = stOut.pop();
    } 
    else if (stIn.getTop() != NULL && stOut.getTop() == NULL) {
        while (stIn.getTop() != NULL) {
            stOut.push(stIn.pop());
        }
        x = stOut.pop();
    }
    return x;
} 

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    std::cout<<q.dequeue()<<"\n";
    q.display();
    std::cout<<q.dequeue()<<"\n";
    q.display();
    std::cout<<q.dequeue()<<"\n";
    q.display();
    return 0;
}