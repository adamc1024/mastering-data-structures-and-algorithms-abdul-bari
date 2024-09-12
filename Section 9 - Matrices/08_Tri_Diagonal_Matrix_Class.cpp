#include <iostream>
using namespace std;

class TriDiagonal {
private:
    int n;
    int * A;
    int A_size;
    int calc_A_size(int n) {
        return 3 * n - 2; 
    }
public:
    TriDiagonal() {
        n = 4;
        A_size = calc_A_size(n);
        A = new int[A_size];
    }
    TriDiagonal(int n) {
        this->n = n;
        A_size = calc_A_size(n);
        A = new int[A_size];
    }
    void set(int i, int j, int el);
    int get(int i, int j);
    void display();
    int get_n() {
        return n;
    };
    int get_A_size() {
        return A_size;
    };
    ~TriDiagonal() {
        delete []A;
    }
};

void TriDiagonal::set(int i, int j, int el) {
    if (i - j == 1) {
        A[i - 1] = el;
    }
    else if (i - j == 0) {
        A[n - 1 + i] = el;
    }
    else if (i - j == - 1) {
        A[2 * n - 1 + i] = el;
    }
}

int TriDiagonal::get(int i, int j) {
    if (i - j == 1) {
        return A[i - 1];
    }
    else if (i - j == 0) {
        return A[n - 1 + i];
    }
    else if (i - j == - 1) {
        return A[2 * n - 1 + i];
    }
    else {
        return 0;
    }
}

void TriDiagonal::display() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - j == 1) {
                cout<<A[i - 1]<<" ";
            }
            else if (i - j == 0) {
                cout<<A[n - 1 + i]<<" ";
            }
            else if (i - j == - 1) {
                cout<<A[2 * n - 1 + i]<<" ";
            }
            else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter dimension: ";
    cin>>n;
    
    TriDiagonal T(n);
    int el;
    cout<<"Enter all elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cin>>el;
          T.set(i, j, el);
        }
    }
    cout<<endl;
    T.display();
    return 0;
}