#include <iostream>
using namespace std;

class UpperTri {
private:
    int n;
    int * A;
    int tri_num(int n) {
        return (n * (n + 1)) / 2;
    }
    int row_major(int i, int j) {
        return (i * (2 * n - i - 1)) / 2 + j;
    }
    int col_major(int i, int j) {
        return (j * (j + 1)) / 2 + i;
    }
public:
    UpperTri() {
        n = 3;
        A = new int[tri_num(n)];
    }
    UpperTri(int n) {
        this->n = n;
        A = new int[tri_num(this->n)];
    }
    void set(int i, int j, int el);
    int get(int i, int j);
    int get_n() {
        return n;
    }
    void display();
    ~UpperTri() {
        delete []A;
    }
};

void UpperTri::set(int i, int j, int el) {
    if (i <= j) {
        A[col_major(i, j)] = el;
    }
}

int UpperTri::get(int i, int j) {
    if (i <= j) {
        return A[col_major(i, j)];
    }
    else {
        return 0;
    }
}

void UpperTri::display() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i <= j) {
                printf("%d ", A[col_major(i, j)]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    cout<<"Enter n Size: ";
    cin>>n;

    UpperTri T(n);
    
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