#include <iostream>

using namespace std;

int main() {
    
    int *P = new int[5];

    P[0] = 5;
    P[1] = 8;
    P[2] = 9;
    P[3] = 6;
    P[4] = 4;

    int *Q = new int[10];

    for (int i = 0; i < 5; i++) {
        Q[i]=P[i];
    }

    for (int i = 0; i < 10; i++) {
        cout<<Q[i]<<endl;
    }

    cout<<"P address: "<<&P[0]<<endl;
    cout<<"Q address: "<<&Q[0]<<endl;

    delete []P;
    
    P = Q;

    cout<<"P address: "<<&P[0]<<endl;

    Q = NULL;

    for (int i = 0; i < 10; i++) {
        cout<<P[i]<<endl;
    }
    
    delete []P;

    return 0;
}