#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Person {
    char name[30];
    int age;
};

struct Person Adam = {"Adam Joseph Cote", 37};

int main() {
    /*
    // Example 1

    int a = 10;
    int *p = &a;
    cout<<a<<endl;
    cout<<*p<<endl;

    // Example 2

    // int *p;
    // C lang
    p = (int *)malloc(5*sizeof(int));
    // C++
    p = new int[5];

    // Example 3

    int a = 10;
    // Declaration of pointer
    int *p;
    // Dereferencing
    p = &a;
    printf("using pointer: the value of a is %d at location %p\n", *p, &a);

    // Example 4

    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    p = A;
    for (int i = 0; i < 5; i++) {
        cout<<"Pointer: "<<p[i]<<endl<<"Array: "<<A[i]<<endl;
    }

    // Example 5

    int *p;

    // Dynamic memory allocation

    // Using C lang
    p = (int *)malloc(5*sizeof(int));
    
    // Using C++
    p = new int[5];

    p[0] = 10, p[1] = 15, p[2] = 14, p[3] = 21, p[4] = 31;
    for (int i = 0; i < 5; i++) {
        cout<<p[i]<<endl;
    }

    // deallocate memory when finished

    // C lang
    free(p);

    // C++
    delete [ ] p;
    */

    // Example 6

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Person *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;

    return 0;
}