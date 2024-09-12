#include <iostream>

class Node {
public:
    char data;
    Node *next;
    Node() {
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
    void push(char data);
    char pop();
    int isBalanced(char *s);
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

void Stack::push(char data) {
    Node *t = new Node();
    t->data = data;
    if (top == NULL) {
        top = t;
    }
    else {
        t->next = top;
        top = t;
    }
}

char Stack::pop() {
    char x = 'x';
    if (top == NULL) {
        std::cout<<"Stack Underflow\n";
    }
    else {
        Node *p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
} 

int Stack::isBalanced(char *s) {
    int i = 0;
    while (s[i]) {
        if (s[i] == '(') {
            push(s[i]);
        }
        else if (s[i] == ')') {
            char x = pop();
            if (x == 'x') {
                return 0;
            }
        }
        i++;
    }
    if (top == NULL) {
        return 1;
    }
    return 0;
}

void print_char_ele(char *s) {
    int i = 0;
    while (s[i]) {
        std::cout<<s[i]<<std::endl;
        i++;
    }
}

int main() {
    char expression[] = "((a + b) * (c - d))";
    Stack st;
    std::cout<<st.isBalanced(expression)<<std::endl;
    st.display();
    return 0;
}