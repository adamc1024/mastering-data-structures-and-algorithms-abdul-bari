#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class CircularSinglyLinkedList {
private:
    Node *head;
public:
    CircularSinglyLinkedList() {
        head = NULL;
        head->next = head;
    }
    CircularSinglyLinkedList(int arr[], int n) {
        head = new Node();
        Node *p = head;
        for (int i = 0; i < n; i++) {
            p->data = arr[i];
            if (i < n - 1) {
                p->next = new Node();
                p = p->next;
            }
        }
        p->next = head;
    }
    void display();
    int count();
    int sum();
    int min();
    int max();
    bool is_sorted(bool ascending);
    bool is_looped();
    void append(int data);
    void sort(bool ascending);
    void delete_duplicates();
    void reverse();
    void insert(int pos, int data);
    int pop(int pos);
    ~CircularSinglyLinkedList() {
        Node *p = head;
        Node *q;
        do {
            q = p;
            delete q;
            p = p->next;
        } while (p != head);
    }
};

void CircularSinglyLinkedList::display() {
    Node *p;
    p = head;
    cout<<"[";
    bool is_head = true;
    do {
        if (!is_head) {
            cout<<", ";
        }
        cout<<p->data;
        p = p->next;
        is_head = false;
    } while (p != head);
    cout<<"]"<<endl;
}

int CircularSinglyLinkedList::count() {
    Node *p = head;
    int result = 0;
    if (p) {
        do {
            result++;
            p = p->next;
        } while (p != head);
    }
    return result;
}

int CircularSinglyLinkedList::sum() {
    Node *p = head;
    int result = 0;
    if (p) {
        do {
            result += p->data;
            p = p->next;
        } while (p != head);
    }
    return result;
}

int CircularSinglyLinkedList::min() {
    Node *p = head;
    int result = p->data;
    if (p) {
        do {
            if (p->data < result) {
                result = p->data;
            }
            p = p->next;
        } while (p != head);
    }
    return result;
}

int CircularSinglyLinkedList::max() {
    Node *p = head;
    int result = p->data;
    if (p) {
        do {
            if (p->data > result) {
                result = p->data;
            }
            p = p->next;
        } while (p != head);
    }
    return result;
}

bool CircularSinglyLinkedList::is_sorted(bool ascending) {
    Node *p = head;
    bool is_sorted = false; 
    if (p) {
        int result = 0;
        int n = count();
        int prev_data = p->data;
        do {
            if (p->data >= prev_data && ascending) {
                result++;
            }
            else if (p->data <= prev_data && ! ascending) {
                result++;
            }
            prev_data = p->data;
            p = p->next;
        } while (p != head);
        is_sorted = result == n;
    }
    return is_sorted;
}

bool CircularSinglyLinkedList::is_looped() {
    Node *p = head;
    do {
        p = p->next;
    }   while(p != head);
    return p == head;
}

void CircularSinglyLinkedList::append(int data) {
    Node *t = new Node(data);
    if (head == NULL) {
        head = t;
        head->next = head;
    }
    else {
        Node *p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = t;
        t->next = head;
    }
}

void CircularSinglyLinkedList::insert(int pos, int data) {
    int n = count();
    pos = pos == 0 ? n : pos;
    if (pos >= 0 && pos <= n) {
        Node *p = head;
        Node *t = new Node(data);
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int CircularSinglyLinkedList::pop(int pos) {
    int n = count();
    int data;
    if (pos >= 0 && pos < n) {
        Node *p = head;
        Node *q;
        if (pos == 0) {
            q = p;
            q = q->next;
            head = q;
            while (q->next != p) {
                q = q->next;
            }
            data = p->data;
            q->next = head;
        }
        else {
            for (int i = 0; i < pos; i++) {
                q = p;
                p = p->next;
            }
            data = p->data;
            q->next = p->next;
        }
        delete p;
        return data;
    }
    return -1;
}

void CircularSinglyLinkedList::sort(bool ascending) {
    Node *p, *q, *r;
    int i, n;
    n = count();
    while (!is_sorted(ascending)) {
        p = NULL;
        q = head;
        r = q->next;
        for (i = 0; i < n - 1; i++) {
            if (ascending && q->data > r->data || !ascending && q->data < r->data) {
                q->next = r->next;
                r->next = q;
                q = r;
                r = q->next;
                if (p == NULL) {
                    head = q;
                }
                else {
                    p->next = q;
                }
            }
            if (i < n - 2) {
                p = q;
                q = r;
                r = r->next;
            }
        }
        r->next = head;
    }
}

void CircularSinglyLinkedList::delete_duplicates() {
    Node *p, *q;
    p = head;
    q = NULL;
    int min, max, n;
    min = this->min();
    max = this->max();
    n = max - min + 1;
    int H[n];
    for (int i = 0; i < n; i++) {
        H[i] = 0;
    }
    do {
        if (!H[p->data]) {
            H[p->data]++;
        }
        else {
            q->next = p->next;
            delete p;
            p = q;
        }
        q = p;
        p = p->next;
    } while (p != head);
    q->next = head;
}

void CircularSinglyLinkedList::reverse() {
    Node *p, *q, *r;
    int n = count();
    p = head;
    q = r = NULL;
    for (int i = 0; i < n; i++) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head->next = q;
    head = q;
}

int main() {
    int arr[] = {0, 9, 2, 7, 8, 3, 7, 4, 1, 6, 5};
    CircularSinglyLinkedList csll = CircularSinglyLinkedList(arr, sizeof(arr)/sizeof(int));
    csll.sort(true);
    csll.display();
    return 0;
}