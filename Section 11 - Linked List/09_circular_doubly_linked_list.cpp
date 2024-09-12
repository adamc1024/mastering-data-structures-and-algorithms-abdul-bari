#include <iostream>

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data) {
        this->data = data;
        prev = next = NULL;
    }
    Node(int data, Node *prev, Node *next) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

class CircularDoublyLinkedList {
private:
    int length;
    struct Node *head;
    struct Node *tail;
public:
    CircularDoublyLinkedList() {
        length = 0;
        head = tail = NULL;
    }
    ~CircularDoublyLinkedList() {
        Node *p = head;
        Node *q;
        while (q != tail) {
            q = p;
            if (p != tail) {
                p = p->next;
            }
            delete q;
        }
    }
    void display();
    bool isEmpty();
    void append(int data);
    void insert(int pos, int data);
    int pop(int pos);
    int sum();
    int max();
    int min();
    float avg();
    bool isSorted(bool ascending);
    void sort(bool ascending);
    void unique();
    void reverse();
    bool isLooped();
};

void CircularDoublyLinkedList::display() {
    Node *p = head;
    std::cout<<"[";
    if (p) {
        int i = 0;
        do
        {
            std::cout<<p->data;
            if (p != tail) {
                std::cout<<", ";
            }
            p = p->next;
            i++;
        } while (p != head);
    }
    std::cout<<"]\n";
    
}

bool CircularDoublyLinkedList::isEmpty() {
    if (length == 0) {
        return true;
    }
    return false;
}

void CircularDoublyLinkedList::append(int data) {
    Node *t = new Node(data);
    if (isEmpty()) {
        t->prev = t->next = t;
        head = tail = t;
    }
    else {
        t->prev = tail;
        t->next = head;
        tail->next = t;
        tail = t;
        head->prev = tail;
    }
    length++;
}

void CircularDoublyLinkedList::insert(int pos, int data) {
    if (pos >= 0 && pos <= length){
        if (pos == length) {
            append(data);
        }
        else {
            Node *t = new Node(data);
            if (pos == 0) {
                t->prev = tail; 
                t->next = head;
                head = t;
                head->next->prev = head;
                head->prev->next = head;

            }
            else {
                Node *p;
                if (((length - 1) - pos) < pos) {
                    p = tail;
                    for (int i = length - 1; i >= pos; i--) {
                        if (i != pos) {
                            p = p->prev;
                        }
                    }
                }
                else {
                    p = head;
                    for (int i = 0; i <= pos; i++) {
                        if (i != pos) {
                            p = p->next;
                        }
                    }
                }
                t->prev = p->prev;
                t->next = p;
                p->prev->next = t;
                p->prev = t;
            }
            length++;
        }
    }
    else {
        std::cout<<"Invalid Index\n";
    }
}

int CircularDoublyLinkedList::pop(int pos) {
    int x = -1; 
    if (!isEmpty() && pos >= 0 && pos <= length - 1) {
        Node *p;
        if (length == 1 && pos == 0) {
            p = head;
            head = tail = NULL;
        }
        else if (length > 1 && pos == 0) {
            p = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        else if (length > 1 && pos == length - 1) {
            p = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        else {
            int i;
            if (((length - 1) - pos) < pos) {
                p = tail;
                for (i = length - 1; i >= pos; i--) {
                    if (i != pos) {
                        p = p->prev;
                    }
                }
            }
            else {
                p = head;
                for (i = 0; i <= pos; i++) {
                    if (i != pos) {
                        p = p->next;
                    }
                }
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
        length--;
    }
    else if (length == 0) {
        std::cout<<"List Underflow\n";
    }
    else {
        std::cout<<"Invalid Index\n";
    }
    return x;
}

int CircularDoublyLinkedList::sum() {
    int x = -1;
    Node *p = head;
    if (p) {
        x = 0;
        do
        {
            x += p->data;
            p = p->next;
        } while (p != head);
    }
    return x;
}

int CircularDoublyLinkedList::max() {
    int x = -1;
    Node *p = head;
    if (p) {
        x = p->data;
        do
        {
            if (p->data > x) {
                x = p->data;
            }
            p = p->next;
        } while (p != head);
    }
    return x;
}

int CircularDoublyLinkedList::min() {
    int x = -1;
    Node *p = head;
    if (p) {
        x = p->data;
        do
        {
            if (p->data < x) {
                x = p->data;
            }
            p = p->next;
        } while (p != head);
    }
    return x;
}

float CircularDoublyLinkedList::avg() {
    float x = -1;
    Node *p = head;
    if (p) {
        x = 0;
        do
        {
            x += p->data;
            p = p->next;
        } while (p != head);
        x /= length;
    }
    return x;
}

bool CircularDoublyLinkedList::isSorted(bool ascending) {
    Node *p = head;
    if (p) {
        int x = p->data;
        do
        {
            if (ascending && p->data < x) {
                return false;
            }
            else if (!ascending && p->data > x) {
                return false;
            }
            x = p->data;
            p = p->next;
        } while (p != head);
        return true;
    }
    std::cout<<"List Is Empty\n";
    return false;
}

void CircularDoublyLinkedList::sort(bool ascending) {
    if (head != tail) {
        Node *p, *q;
        while (!isSorted(ascending)) {
            p = head;
            q = p->next;
            while (p != tail) {
                if (ascending && p->data > q->data || !ascending && p->data < q->data) {
                    if (p == head) {
                        head = q;
                    }
                    if (q == tail) {
                        tail = p;
                    }
                    p->next = q->next;
                    p->next->prev = p;
                    q->prev = p->prev;
                    q->prev->next = q;
                    q->next = p;
                    p->prev = q;
                    q = p->next;
                }
                else {
                    p = p->next;
                    q = p->next;
                }
            }
        }
    }
    else {
        std::cout<<"List Is Empty\n";
    }
}

void CircularDoublyLinkedList::unique() {
    int x = min();
    int y = max();
    int n = y - x + 1;
    int H[n];
    for (int i = 0; i < n; i++) {
        H[i] = 0;
    }
    struct Node *p = head;
    struct Node *q = p->next;
    do
    {
        if (H[p->data - x] < 1) {
            H[p->data - x]++;
        }
        else {
            if (p == tail) {
                tail = p->prev;
            }
            p->prev->next = q;
            q->prev = p->prev;
            delete p;
        }
        p = q;
        q = q->next;
    } while (p != head);  
}

void CircularDoublyLinkedList::reverse() {
    Node *p = head;
    Node *q;
    if (p) {
        do
        {
            q = p->prev;
            p->prev = p->next;
            p->next = q;
            p = q;
        } while (p != head);
        p = head;
        head = tail;
        tail = p;
    }
}
bool CircularDoublyLinkedList::isLooped() {
    Node *p = head;
    Node *q = p;
    if (p) {
        do
        {
            p = p->next;
            q = q->prev;
        } while (p != head && q != head); 
        if (p == head && q == head) {
            return true;
        }
    }
    return false;
}


int main() {
    CircularDoublyLinkedList cdll;
    cdll.append(7);
    cdll.append(3);
    cdll.append(8);
    cdll.append(16);
    cdll.append(2);
    cdll.display();
    cdll.pop(2);
    cdll.display();
    cdll.insert(1, 2);
    cdll.display();
    cdll.reverse();
    cdll.display();
    cdll.sort(true);
    cdll.display();
    cdll.unique();
    cdll.display();
    cdll.sort(false);
    cdll.display();
    cdll.sort(true);
    cdll.display();
    std::cout<<"isLooped: "<<cdll.isLooped()<<"\n";
    return 0;
}