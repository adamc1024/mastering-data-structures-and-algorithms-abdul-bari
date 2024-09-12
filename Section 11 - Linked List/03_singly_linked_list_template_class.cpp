#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T>() {
        next = NULL;
    }
    Node<T>(T data) {
        this->data = data;
        next = NULL;
    } 
};

template <class T>
class SinglyLinkedList {
private:
    Node<T> *head;
public:
    SinglyLinkedList() {
        head = NULL;
    }
    SinglyLinkedList(T arr[], int n) {
        head = new Node<T>;
        Node<T> *p = head;
        for (int i = 0; i < n; i++) {
            p->data = arr[i];
            if (i < n - 1) {
                p->next = new Node<T>;
                p = p->next;
            }
        }
    }
    ~SinglyLinkedList() {
        Node<T> *p, *q;
        p = head;
        while (p) {
            q = p;
            p = p->next;
            cout<<"Delete -> "<<q->data<<endl;
            delete q;
        }
    }
    void set_head_node(Node<T> *p) {
        head = p;
    }
    Node<T> *get_head_node() {
        return head;
    }
    void append(T data);
    void display();
    int count();
    void insert(int pos, T data);
    T pop(int pos);
    void reverse();
};

template <class T>
void SinglyLinkedList<T>::append(T data) {
    Node<T> *t, *p;
    t = new Node<T>(data);
    p = head;
    if (p) {
        while (p->next) {
            p = p->next;
        }
        p->next = t;
    }
    else {
        set_head(t);
    }
}

template <class T>
void SinglyLinkedList<T>::display() {
    Node<T> *p;
    p = head;
    cout<<"[";
    int count = 0;
    while (p) {
        if (count > 0) {
           cout<<", "; 
        }
        cout<<p->data;
        p = p->next;
        count++;
    }
    cout<<"]"<<endl;
}

template <class T>
int SinglyLinkedList<T>::count() {
    Node<T> *p = head;
    int result = 0;
    while (p) {
        result++;
        p = p->next;
    }
    return result;
}

template <class T>
void SinglyLinkedList<T>::insert(int pos, T data) {
    int n = count();
    if (n && pos >= 0 && pos <= n) {
        Node<T> *t;
        t = new Node<T>(data);
        Node<T> *p, *q;
        p = head;

        if (pos == 0) {
            t->next = p;
            head = t;
        }
        else {
            int count = 0;
            while (count < pos) {
                q = p;
                p = p->next;
                count++;
            }
            q->next = t;
            t->next = p;
        }
    }
}

template <class T>
T SinglyLinkedList<T>::pop(int pos) {
    int n = count();
    T data = -1;
    if (pos >= 0 && pos < n) {
        Node<T> *p, *q;
        p = head;
        int count = 0;
        if (pos == 0) {
            q = p;
            p = p->next;
            data = q->data;
            delete q;
            head = p;
        }
        else if (pos < n - 1) {
            while (count < n) {
                q = p;
                p = p->next;
                count++;
            }
            q->next = p->next;
            data = p->data;
            delete p;
        }
        else {
            while (p->next) {
                q = p;
                p = p->next;
            }
            data = p->data;
            q->next = p->next;
            delete p;
        }
    }
    return data;
}

template <class T>
void SinglyLinkedList<T>::reverse() {
    Node<T> *p, *q, *r;
    p = head;
    q = r = NULL;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

int main() {
    float arr[] = {0.1, 5.6, 7.8, 9.6};
    SinglyLinkedList<float> ll = SinglyLinkedList<float>(arr, sizeof(arr)/sizeof(float));
    ll.display();
    ll.reverse();
    ll.display();
    return 0;
}