#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        next = NULL;
    }
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

class SinglyLinkedList {
private:
    Node *head;
    Node *tail;
public:
    SinglyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    SinglyLinkedList(Node *head, Node *tail) {
        this->head = head;
        this->tail = tail;
    }
    SinglyLinkedList(int *arr, int n) {
        head = new Node();
        Node *p = head;
        for (int i = 0; i < n; i++) {
            p->data = arr[i];
            if (i < n - 1) {
                p->next = new Node();
                p = p->next;
            }
        }
        tail = p;
    }
    void display();
    int length();
    void append(int data);
    void insert(int pos, int data);
    int pop(int pos);
    int sum();
    int max();
    int min();
    float average();
    bool is_sorted(bool ascending);
    void sort(bool ascending);
    void unique();
    void reverse();
    bool is_looped();
    Node *get_head();
    void set_head(Node *p);
    Node *get_tail();
    void set_tail(Node *p);
    ~SinglyLinkedList() {
        Node *p, *q;
        p = head;
        while (p) {
            q = p;
            delete q;
            p = p->next;
        }
    }
};

void SinglyLinkedList::display() {
    Node *p = head;
    cout<<"[";
    bool comma = false;
    while (p) {
        if (comma) {
            cout<<", ";
        }
        else {
            comma = true;
        }
        cout<<p->data;
        p = p->next;
    }
    cout<<"]\n";
}

int SinglyLinkedList::length() {
    int result = 0;
    Node *p = head;
    while (p) {
        result++;
        p = p->next;
    }
    return result;
}

void SinglyLinkedList::append(int data) {
    Node *t = new Node(data, NULL);
    if (head == NULL && tail == NULL) {
        head = tail = t;
    }
    else {
        tail->next = t;
        tail = t;
    }
}

void SinglyLinkedList::insert(int pos, int data) {
    Node *p = head;
    Node *q;
    int n = length();
    if (pos == n) {
        append(data);
    }
    else if (pos >= 0 && pos < n) {
        Node *t;
        if (pos == 0) {
            t = new Node(data, p);
            head = t;
        }
        else {
            for (int i = 0; i < pos; i++) {
                q = p;
                p = p->next;
            }
            t = new Node(data, p);
            q->next = t;
        }
    }
}

int SinglyLinkedList::pop(int pos) {
    int data, n;
    data = -1;
    n = length();
    if (n && pos >= 0 && pos < n) {
        Node *p = head;
        if (pos == 0) {
            data = p->data;
            head = p->next;
            delete p;
        }
        else {
            Node *q;
            for (int i = 0; i < pos; i++) {
                q = p;
                p = p->next;
            }
            data = p->data;
            q->next = p->next;
            delete p;
            if (pos == n - 1) {
                tail = q;
            }
        }
    }
    return data;
}

int SinglyLinkedList::sum() {
    int result = 0;
    Node *p = head;
    while (p) {
        result += p->data;
        p = p->next;
    }
    return result;
}

int SinglyLinkedList::max() {
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

int SinglyLinkedList::min() {
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

float SinglyLinkedList::average() {
    return (float) sum()/length();
}

bool SinglyLinkedList::is_sorted(bool ascending) {
    Node *p = head;
    int data;
    while (p->next) {
        data = p->data;
        p = p->next;
        if (ascending && data > p->data) {
            break;
        }
        if (! ascending && data < p->data) {
            break;
        }
    }
    if (p->next == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void SinglyLinkedList::sort(bool ascending) {
    Node *p, *q, *r;
    while (! is_sorted(ascending)) {
        p = NULL;
        q = head;
        r = q->next;
        while (r) {
            if (ascending && q->data > r->data || !ascending && q->data < r->data) {
                q->next = r->next;
                r->next = q;
                q = r;
                r = q->next;
                if (p) {
                    p->next = q;
                }
                else {
                    head = q;
                }
            }
            p = q;
            q = q->next;
            r = r->next;
        }
    }
}

bool SinglyLinkedList::is_looped() {
    Node *p, *q;
    p = q = head;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q) {
        return true;
    } 
    else {
        return false;
    }
}

void SinglyLinkedList::unique() {
    int max = this->max();
    int min = this->min();
    int n = max - min + 1;
    int H[n];
    for (int i = 0; i < n; i++) {
        H[i] = 0;
    }
    Node *p = head;
    Node *q;
    while (p) {
        if (H[p->data - min] == 0) {
            H[p->data - min]++;
            q = p;
            p = p->next;
        }
        else if (H[p->data - min] > 0) {
            q->next = p->next;
            delete p;
            p = q->next;
        }
    }
}

void SinglyLinkedList::reverse() {
    Node *p, *q, *r;
    tail = head;
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

Node *SinglyLinkedList::get_head() {
    return head;
}

void SinglyLinkedList::set_head(Node *p) {
    head = p;
}

Node *SinglyLinkedList::get_tail() {
    return tail;
}

void SinglyLinkedList::set_tail(Node *p) {
    tail = p;
}

SinglyLinkedList *concatenate(SinglyLinkedList *sll_1, SinglyLinkedList *sll_2) {
    Node *sll_1_tail = sll_1->get_tail();
    Node *sll_2_head = sll_2->get_head();
    sll_1_tail->next = sll_2_head;
    SinglyLinkedList *sll_3 = new SinglyLinkedList(sll_1->get_head(), sll_2->get_tail());
    sll_1->set_head(NULL);
    sll_1->set_tail(NULL);
    sll_2->set_head(NULL);
    sll_2->set_tail(NULL);
    return sll_3;
}

SinglyLinkedList *merge(SinglyLinkedList *sll_1, SinglyLinkedList *sll_2, bool ascending) {
    SinglyLinkedList *sll_3 = concatenate(sll_1, sll_2);
    sll_3->sort(ascending);
    return sll_3;
}

int main() {
    int arr_1[] = {1, 4, -3, 7, 9, 3};
    int arr_2[] = {1, 10, 3, 6, 8, 9, 10};
    SinglyLinkedList sll_1 = SinglyLinkedList(arr_1, sizeof(arr_1)/sizeof(int));
    SinglyLinkedList sll_2 = SinglyLinkedList(arr_2, sizeof(arr_2)/sizeof(int)); 
    SinglyLinkedList *sll_3;
    sll_3 = merge(&sll_1, &sll_2, false);
    sll_3->unique();
    sll_3->reverse();
    sll_3->display();
    delete sll_3;
    return 0;
}