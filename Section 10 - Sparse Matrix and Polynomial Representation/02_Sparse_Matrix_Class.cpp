#include <iostream>
using namespace std;

class Element {
public:
    int i;
    int j;
    int el;
};

class Sparse {
private:
    int m;
    int n;
    int E_size;
    Element * E; 
public:
    Sparse() {
        m = 0;
        n = 0;
        E_size = 0;
    }
    Sparse(int m, int n, int E_size) {
        this->m = m;
        this->n = n;
        this->E_size = E_size;
        E = new Element[this->E_size];
    }
    void set_m(int m) {
        this->m = m;
    }
    void set_n(int n) {
        this->n = n;
    }
    void set_E_size(int E_size) {
        this->E_size = E_size;
    }
    void set_Element(int k, int i, int j, int el) {
        E[k].i = i;
        E[k].j = j;
        E[k].el = el;
    }
    int get_m() {
        return m;
    }
    int get_n() {
        return n;
    }
    int get_E_size() {
        return E_size;
    }
    Element get_element(int i) {
        return E[i];
    }
    ~Sparse() {
        delete [] E;
    }

    Sparse operator+(Sparse &S);

    friend istream & operator>>(istream &is, Sparse &S);
    friend ostream & operator<<(ostream &os, Sparse &S);
};

Sparse Sparse::operator+(Sparse &S) {
    if (m != S.m || n != S.n) {
        Sparse * sum = new Sparse(1, 1, 1);
        sum->E = new Element[1];
        sum->E->i = 0, sum->E->j = 0; sum->E->el = -1;
        return *sum;
    }
    Sparse * sum = new Sparse(m, n, E_size + S.E_size);
    int i, j, k;
    i = j = k = 0;
    while (i < E_size || j < S.E_size) {
        if (i < E_size && j < S.E_size) {
            if (E[i].i < S.E[j].i) {
                sum->E[k] = E[i];
                i++;
                k++;
            }
            else if (E[i].i > S.E[j].i) {
                sum->E[k] = S.E[j];
                j++;
                k++;
            }
            else if (E[i].i == S.E[j].i && E[i].j < S.E[j].j) {
                sum->E[k] = E[i];
                i++;
                k++;
            }
            else if (E[i].i == S.E[j].i && E[i].j > S.E[j].j) {
                sum->E[k] = S.E[j];
                j++;
                k++;
            }
            else {
                sum->E[k] = E[i];
                sum->E[k].el = E[i].el + S.E[j].el; 
                i++;
                j++;
                k++;
            }
        }
        else if (i == E_size || j == S.E_size) {
            sum->E[k] = (i == E_size) ? S.E[j++] : E[i++];
            k++;
        } 
    }
    sum->E_size = k;
    return *sum;
}

istream & operator>>(istream &is, Sparse &S) {
    int i;
    cout<<"Enter Dimensions (m x n): ";
    cin>>S.m>>S.n;
    cout<<"Enter amount of non-zero elements: ";
    cin>>S.E_size;
    S.E = new Element[S.E_size];
    cout<<"Enter all elements\n";
    for (i = 0; i < S.E_size; i++) {
        cout<<"Element "<<i<<" (i j el): ";
        cin>>S.E[i].i>>S.E[i].j>>S.E[i].el;
    }
    return is;
}

ostream & operator<<(ostream &os, Sparse &S) {
    int i, j, k;
    k = 0;
    for (i = 0; i < S.m; i++) {
        for (j = 0; j < S.n; j++) {
            if (i == S.E[k].i && j == S.E[k].j) {
                cout<<S.E[k].el;
                k++;
              }
            else {
                cout<<"0";
            }
            if (j < S.n - 1) {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return os;
}

int main () {
    Sparse S1, S2;
    cin>>S1;
    cin>>S2;
    Sparse sum = S1 + S2;
    cout<<"---------"<<endl<<"Matrix 1"<<endl<<"---------"<<endl;
    cout<<S1;
    cout<<"---------"<<endl<<"Matrix 2"<<endl<<"---------"<<endl;
    cout<<S2;
    cout<<"---------"<<endl<<"Sum of Matrices 1 and 2"<<endl<<"---------"<<endl;
    cout<<sum;
    // Sparse S2(5, 5, 5);
    // int k = 0;
    // int x = 0;
    // int y = 4;
    // for (int i = 0; i < S2.get_m(); i++) {
    //     for (int j = 0; j < S2.get_n(); j++) {
    //         if (i == x && j == y) {
    //             S2.set_Element(k, i, j, k + 1);
    //             x++;
    //             y--;
    //             k++;
    //         }
    //     }
    // }
    // S2.display();
    return 0;
}