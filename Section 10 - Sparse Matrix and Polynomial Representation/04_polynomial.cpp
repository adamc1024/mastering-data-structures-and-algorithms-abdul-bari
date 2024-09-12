#include <iostream>
#include <math.h>
using namespace std;

class Term {
public:
    int coeff;
    int exp;
};

class Poly {
public:
    int n;
    int x;
    class Term * T;
    Poly() {
        int n = 0;
        int x = 0;
    }
    Poly(int n) {
        this->n = n;
        T = new Term[n];
    }
    void read();
    void display();
    float eval(int num = 0);
    Poly * add_poly(Poly * P2);
    ~Poly() {
        delete [] T;
    }
};

void Poly::read() {
    int i;
    cout<<"Enter amount of non-zero terms: ";
    cin>>n;
    T = new Term[n];
    for (i = 0; i < n; i++) {
        cout<<"Term "<<i + 1<<" (coefficient, exponent): ";
        cin>>T[i].coeff>>T[i].exp;
    }
}

void Poly::display() {
    int i, coeff, exp;
    cout<<"f(x) = ";
    for (i = 0; i < n; i++) {
        coeff = T[i].coeff >= 0 ? T[i].coeff : T[i].coeff * -1;
        exp = T[i].exp;
        if (i == 0 && T[i].coeff < 0) {
            cout<<"-";
        }
        if (i > 0) {
            if (T[i].coeff > 0) {
                cout<<" + ";
            }
            else {
                cout<<" - ";
            }
        }
        if (coeff > 1 || coeff == 1 && exp == 0) {
            cout<<coeff;
        }
        if (exp == 1) {
            cout<<"x";
        }
        if (exp < 0 || exp > 1) {
            cout<<"x^"<<exp;
        }
        if (i == n - 1) {
            cout<<endl;
        }
    }
}

float Poly::eval(int num) {
    if (num == 0) {
        cout<<"Enter x: ";
        cin>>x;
    }
    else {
        x = num;
    }
    float result = 0, temp;
    int exp, i;
    for (i = 0; i < n; i++) {
        exp = T[i].exp >= 0 ? T[i].exp : T[i].exp * -1;
        temp = pow(x, exp);
        if (T[i].exp < 0) {
            temp = 1/temp;
        }
        result += T[i].coeff * temp;
        // cout<<T[i].coeff<<" x "<<temp<<" = "<<T[i].coeff * temp<<endl;
    }
    cout<<"f("<<x<<") = "<<result<<endl;
    return result;
}

Poly * Poly::add_poly(Poly * P2) {
    Poly * P3 = new Poly(n + P2->n);
    int i, j, k;
    i = j = k = 0;
    while (i < n || j < P2->n) {
        if (T[i].exp == P2->T[j].exp) {
            P3->T[k].coeff = T[i].coeff + P2->T[j].coeff;
            P3->T[k].exp = T[i].exp;
            i++;
            j++;
            k++;
        }
        else if (T[i].exp > P2->T[j].exp) {
            P3->T[k] = T[i];
            i++;
            k++;
        }
        else if (T[i].exp < P2->T[j].exp) {
            P3->T[k] = P2->T[j];
            j++;
            k++;
        }
        else if (i < n && j == P2->n) {
            P3->T[k] = P2->T[i];
            i++;
            k++;
        } 
        else if (i == n && j < P2->n) {
            P3->T[k] = P2->T[j];
            j++;
            k++;
        }
    }
    P3->n = k;
    return P3;
}

int main() {
    Poly P1, P2, * P3;
    cout<<"P1"<<endl;
    P1.read();
    P1.display();
    P1.eval();
    cout<<"P2"<<endl;
    P2.read();
    P2.display();
    P2.eval();
    cout<<"P1 + P2"<<endl;
    P3 = P1.add_poly(&P2);
    P3->display();
    P3->eval();
    return 0;
} 