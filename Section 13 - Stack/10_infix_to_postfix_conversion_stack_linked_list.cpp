#include <iostream>

class Node {
public:
    char data;
    Node *next;
    Node() {
        next = NULL;
    }
    Node(char data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

int stackIsFull() {
    Node *t = new Node();
    if (t == NULL) {
        return 1;
    }
    delete t;
    return 0;
}

class Stack {
private:
    Node *top;
public:
    Stack() {
        top = NULL;
    }
    int isEmpty();
    void push(char data);
    char pop();
    char getTop();
    void display();
};

int Stack::isEmpty() {
    if (top == NULL) {
        return 1;
    }
    return 0;
}

void Stack::push(char data) {
    if (!stackIsFull()) {
        Node *t = new Node(data, NULL);
        if (isEmpty()) {
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

char Stack::pop() {
    char x = '\0';
    if (!isEmpty()) {
        Node *p = top;
        x = top->data;
        top = top->next;
        delete p;
    }
    else {
        std::cout<<"Stack Underflow\n";
    }
    return x;
}

char Stack::getTop() {
    char x = '\0';
    if (!isEmpty()) {
        x = top->data;
    }
    return x;
}

void Stack::display() {
    Node *p = top;
    std::cout<<"[";
    while (p) {
        std::cout<<p->data;
        if (p->next != NULL) {
            std::cout<<", ";
        }
        p = p->next;
    }
    std::cout<<"]\n";
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }
    return 1;
}

int precedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 2;
    }
    return 0;
}

int countChar(char *s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            result++;
        }
    }
    return result;
}

char *convertInfixToPostfix(char *infix) {
    char *postfix =  new char[countChar(infix) + 1];
    Stack st = Stack();
    int i = 0, j = 0;
    while (infix[i] != 0) {
        if (infix[i] != ' ') {
            if (isOperand(infix[i])) {
                postfix[j++] = infix[i++];
            }
            else {
                if (precedence(infix[i]) > precedence(st.getTop())) {
                    st.push(infix[i++]);
                }
                else {
                    postfix[j++] = st.pop();
                }
            }
            std::cout<<postfix<<std::endl;
            st.display();
        }
        else {
            i++;
        }
    }
    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
        std::cout<<postfix<<std::endl;
        st.display();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char s[] = "a + b * c - d / e";
    char *postfix = convertInfixToPostfix(s);
    delete [] postfix;
    return 0;
}