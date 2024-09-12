#include <iostream>

class Stack {
private:
    char *arr;
    int top;
    int arrSize;
public:
    Stack() {
        top = -1;
        arrSize = 0;
    }
    Stack(int arrSize) {
        arr = new char[arrSize];
        top = -1;
        this->arrSize = arrSize;
    }
    ~Stack() {
        delete [] arr;
    }
    void push(char data);
    char pop();
    void display();
    char * infixPostfixConvert(char *s);
};

void Stack::push(char data) {
    if (top < arrSize - 1) {
        top++;
        arr[top] = data;
    }
    else {
        std::cout<<"Stack Overflow\n";
    }
}

char Stack::pop() {
    char x = '\0';
    if (top > -1) {
        x = arr[top];
        top--;
    }
    else {
        std::cout<<"Stack Underflow\n";
    }
    return x;
}

void Stack::display() {
    if (arrSize > 0) {
        std::cout<<"[";
        for (int i = top; i > -1; i--) {
            std::cout<<arr[i];
            if (i > 0) {
                std::cout<<", ";
            }
        }
        std::cout<<"]\n";
    }
    else {
        std::cout<<"[]\n";
    }
} 

int getStackArrSize(char *s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            count++;
        }
    }
    return count;
}

int getPrecedence(char data) {
    if (data == '+' || data == '-') {
        return 1;
    }
    else if (data == '*' || data == '/') {
        return 2;
    }
    return 0;
}

char * Stack::infixPostfixConvert(char *s) {
    int pfIndex = 0;
    char *pf = new char[arrSize + 1];
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            std::cout<<'\"'<<s[i]<<"\": ";
            if (getPrecedence(s[i])) {
                int sPrecedence = getPrecedence(s[i]);

                if (top == -1) {
                    push(s[i]);
                    std::cout<<"Push \""<<s[i]<<"\". ";
                }
                else {
                    int stackTopPrecedence = getPrecedence(arr[top]);
                    if(sPrecedence > stackTopPrecedence) {
                        push(s[i]);
                        std::cout<<"Push \""<<s[i]<<"\". ";
                    }
                    else {
                        while (sPrecedence <= stackTopPrecedence) {
                            pf[pfIndex] = pop();
                            std::cout<<"Pop \""<<pf[pfIndex]<<"\". ";
                            stackTopPrecedence = getPrecedence(arr[top]);
                            pfIndex++;
                        }
                        push(s[i]);
                        std::cout<<"Push \""<<s[i]<<"\". ";
                    }
                }
            }
            else {
                pf[pfIndex] = s[i];
                pfIndex++;
            }
            display();
        }
    }
    while (top > - 1) {
        pf[pfIndex] = pop();
        std::cout<<"Pop \""<<pf[pfIndex]<<"\". ";
        pfIndex++;
        display();
    }
    pf[pfIndex] = '\0';
    return pf;
}

int main() {
    char s[] = "a + b * c - d / e";
    int stackArrSize = getStackArrSize(s);
    Stack st = Stack(stackArrSize);
    std::cout<<s<<std::endl;
    char *pf = st.infixPostfixConvert(s);
    std::cout<<pf<<std::endl;
    delete [] pf;
    return 0;
}