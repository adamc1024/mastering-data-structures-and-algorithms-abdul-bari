#include <iostream>
using namespace std;

class Symmetric {
private:
    int n;
    int * A;
    int tri_num(int n) {
        return (n * (n + 1)) / 2;
    }
    int row_major(int i, int j) {
        return (i * (i + 1)) / 2 + j;
    }
    int col_major(int i, int j) {
        return (j * (2 * n - j - 1)) / 2 + i;
    }
public:
    Symmetric() {
        n = 3;
        A = new int[tri_num(n)];
    }
    Symmetric(int n) {
        this->n = n;
        A = new int[tri_num(this->n)];
    }
    void set(int i, int j, int el);
    int get(int i, int j);
    int get_n() {
        return n;
    }
    void display();
    ~Symmetric() {
        delete []A;
    }
};

void Symmetric::set(int i, int j, int el) {
    if (i >= j) {
        A[row_major(i, j)] = el;
    }
}

int Symmetric::get(int i, int j) {
    if (i >= j) {
        return A[row_major(i, j)];
    }
    else {
        return A[row_major(j, i)];
    }
}

void Symmetric::display() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i >= j) {
                printf("%d ", A[row_major(i, j)]);
            }
            else {
                printf("%d ", A[row_major(j, i)]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    cout<<"Enter n Size: ";
    cin>>n;

    Symmetric T(n);
    
    int el;
    cout<<"Enter All Elements\n";
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            cin>>el;
            T.set(i, j, el);
        }
    }
    cout<<endl;
    T.display();
    return 0;
}