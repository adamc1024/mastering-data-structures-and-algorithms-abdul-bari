#include <iostream>

using namespace std;

// Call by value
void show_result(int num1, int num2) {
    cout<<"a = "<<num1<<endl<<"b = "<<num2<<endl;
}

// // Will not modify variables outside of this function
// void swap(int x, int y) {
//     int temp = x;
//     x = y;
//     y = temp;
//     show_result(x, y);
// }

// Call by address
// Best practice
void swap(int *x, int *y) { // <- "*" dereferences address
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 10, b = 15;
    show_result(a, b);
    // indirectly modifies values
    swap(&a, &b); // <- address(es) of value(s) passed into function
    show_result(a, b);
}

// // Call by reference
// // Only available in C++
// // Should be used carefully
// void swap(int &x, int &y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 10, b = 15;
//     show_result(a, b);
//     swap(a, b);
//     show_result(a, b);
// }
