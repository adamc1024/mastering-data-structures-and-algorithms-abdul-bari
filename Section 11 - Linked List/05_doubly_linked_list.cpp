#include <iostream>
using namespace std;

class Node {
public:
    Node *prev;
    int data;
    Node *next;
    Node() {
        prev = NULL;
        next = NULL;
    }
    Node(int data) {
        prev = NULL;
        this->data = data;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;
public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    DoublyLinkedList(int *arr, int n) {
        head = new Node();
        Node *p = head;
        for (int i = 0; i < n; i++) {
            p->data = arr[i];
            if (i < n - 1) {
                p->next = new Node();
                p->next->prev = p;
                p = p->next;
            }

        }
        p->next = NULL;
        tail = p;
    }
    void append(int data);
    int length();
    void insert(int pos, int data);
    void display();
    int sum();
    int max();
    int min();
    float avg();
    void reverse();
    int pop(int pos);
    int middle();
    ~DoublyLinkedList() {
        Node *p = head;
        Node *q;
        while (p) {
            q = p;
            cout<<"Del: "<<q->data<<endl;
            delete q;
            p = p->next;
        }
    }
};

void DoublyLinkedList::append(int data) {
    Node *t = new Node(data);
    if (head == NULL) {
        head = t;
        tail = t;
    }
    else {
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
}

int DoublyLinkedList::length() {
    Node *p = head;
    int result = 0;
    while (p) {
        result++;
        p = p->next;
    }
    return result;
}

void DoublyLinkedList::insert(int pos, int data) {
    if (head == NULL & pos == 0) {
        append(data);
    }
    else {
        int n = length();
        if (pos == n) {
            append(data);
        }
        else if (pos >= 0 && pos < n) {
            Node *t = new Node(data);
            if (pos == 0) {
                t->next = head;
                head->prev = t;
                head = t;
            }
            else {
                Node *p = head;
                for (int i = 0; i < pos - 1; i++) {
                    p = p->next;
                }
                t->next = p->next;
                t->prev = p;
                p->next = t;
            }
        }
    }
}

void DoublyLinkedList::display() {
    Node *p = head;
    cout<<"[";
    bool first = true;
    while (p) {
        if (!first) {
            cout<<", ";
        }
        cout<<p->data;
        p = p->next;
        first = false;
    }
    cout<<"]"<<endl;
}

int DoublyLinkedList::sum() {
    Node *p = head;
    int result = 0;
    while (p) {
        result += p->data;
        p = p->next;
    }
    return result;
}

int DoublyLinkedList::max() {
    Node *p = head;
    int result = p->data;
    while (p) {
        if (p->data > result) {
            result = p->data;
        }
        p = p->next;
    }
    return result;
}

int DoublyLinkedList::min() {
    Node *p = head;
    int result = p->data;
    while (p) {
        if (p->data < result) {
            result = p->data;
        }
        p = p->next;
    }
    return result;
}

float DoublyLinkedList::avg() {
    int n = length();
    Node *p = head;
    float result = p->data;
    while (p) {
        result += p->data;
        p = p->next;
    }
    return result/n;
}

void DoublyLinkedList::reverse() {
    // Node *p = tail;
    // Node *q = NULL;
    // head = p;
    // while (p) {
    //     p->next = p->prev;
    //     p->prev = q;
    //     q = p;
    //     p = p->next;
    // }
    // tail = q;
    Node *p = head;
    Node *t;
    tail = p;
    while (p) {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if (p && p->next == NULL) {
            head = p;
        }
    }
}

int DoublyLinkedList::pop(int pos) {
    int data = -1;
    if (head == NULL) {
        return data;
    }
    else {
        int n = length();
        if (pos >= 0 && pos < n) {
            if (pos < n - 1) {
                Node *p = head;
                if (pos == 0) {
                    data = p->data;
                    head = p->next;
                    head->prev = NULL;
                    delete p;
                    return data;
                }
                else {
                    for (int i = 0; i < pos; i++) {
                        p = p->next;
                    }
                    data = p->data;
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    delete p;
                    return data;
                }

            }
            else {
                Node *p = tail;
                data = p->data;
                tail = p->prev;
                tail->next = NULL;
                delete p;
                return data;
            }
        }
    }
    return data;
}

int DoublyLinkedList::middle() {
    Node *p = head;
    Node *q = tail;
    while (p != q && p->next != q) {
        cout<<p->data<<" "<<q->data<<endl;
        p = p->next;
        q = q->prev;
    }
    p = p == q ? p : q;
    // Node *p, *q;
    // p = q = head;
    // while (q && q->next) {
    //     cout<<p->data<<" "<<q->data<<endl;
    //     p = p->next;
    //     q = q->next->next;
    // }
    return p->data;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(int);
    DoublyLinkedList dll = DoublyLinkedList(arr, n);
    dll.display();
    cout<<dll.middle()<<endl;
    return 0;
}