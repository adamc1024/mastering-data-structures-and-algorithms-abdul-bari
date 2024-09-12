#include <iostream>

using namespace std;

// Prototype of function and declaration of function
// Declared as return type
// Call by value
int add(int a, int b) { // <- Formal parameter(s)
    // Function definition 
    int sum = a + b;
    return sum;
}

int main() {
    int x = 10, y = 15, result;
    // Function call
    result = add(x, y); // <- Actual parameters
    printf("The sum of %d and %d is %d.\n", x, y, result);
    return 0;
}