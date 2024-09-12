#include <iostream>
using namespace std;

class Diagonal {
private:
    int n;
    int * A;
public:
    Diagonal() {
        n = 10;
        A = new int[10];
    }
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int el);
    int get(int i, int j);
    void display();
    ~Diagonal() {
        delete []A;
    }
};

void Diagonal::set(int i, int j, int el) {
    if (i == j) {
        A[i] = el;
    }
}

int Diagonal::get(int i, int j) {
    if (i == j) {
        return A[i];
    }
    else {
        return 0;
    }
}

void Diagonal::display() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                printf("%d ", A[i]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    Diagonal M(5);
    M.set(0, 0, 3);
    M.set(1, 1, 7);
    M.set(2, 2, 4);
    M.set(3, 3, 9);
    M.set(4, 4, 6);
    M.display();
    return 0;
}