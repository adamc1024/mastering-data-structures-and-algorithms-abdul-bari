#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    // variable declared and initiated
    // stored in the stack at unique location
    int a = 10;
    // & is reference character to a's location
    // r is an alias for a
    // reference cannot be redeclared
    // you must initialize reference upon declaration
    int &r = a;
    cout<<a<<endl<<r<<endl;
    r++;
    cout<<a<<endl<<r<<endl;
    int b = 30;
    r = b;
    cout<<a<<endl<<r<<endl;
    return 0;
}
