#include <iostream>

class Stack {
private:
    char *arr;
    int top;
    int size;
public:
    Stack() {
        top = -1;
        size = 0;
    }
    Stack(int size) {
        arr = new char[size];
        this->size = size;
        top = -1;
    }
    ~Stack() {
        delete arr;
    }
    void push(char data);
    char pop();
    int isBalanced(char *s);
    void display();
};

void Stack::push(char data) {
    if (top < size - 1) {
        top++;
        arr[top] = data;
    }
    else {
        std::cout<<"Stack Overflow"<<std::endl;
    }
}

char Stack::pop() {
    char x = '\0';
    if (top > -1) {
        x = arr[top];
        top--;
    }
    else {
        std::cout<<"Stack Underflow"<<std::endl;
    }
    return x;
}

void Stack::display() {
    std::cout<<'[';
    for (int i = top; i > -1; i--) {
        std::cout<<arr[i];
        if (i > 0) {
            std::cout<<", ";
        }
    }
    std::cout<<"]\n";
}

int Stack::isBalanced(char *s) {
    for (int i = 0; s[i] != '\0'; i ++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
            display();
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (top > -1) {
                if (arr[top] == '(' && s[i] == ')') {
                    pop();
                }
                else if (arr[top] == '[' && s[i] == ']') {
                    pop();
                }
                else if (arr[top] == '{' && s[i] == '}') {
                    pop();
                }
                else {
                    return 0;
                }
                display();
            }
            else {
                return 0;
            }
        }
    }
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }

}

int getStringLength(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i ++;
    }
    return i;
}

int main() {
    char expression[] = "{[(a + b) * (c - d)]/[(a - b) / (c + d)]}";
    int size = getStringLength(expression);
    Stack st = Stack(size);
    std::cout<<st.isBalanced(expression)<<std::endl;
    st.display();
    return 0;
}