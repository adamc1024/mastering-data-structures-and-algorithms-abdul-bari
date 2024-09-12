#include <iostream>

using namespace std;

// Question 1
int f1(int n) {
    static int i = 1;
    if (n >= 5) {
        return n;
    }
    n += i;
    i++;
    return f1(n);
}

// Question 2
void f2(int n, int sum) {
    int k = 0, j = 0;
    if (n == 0) {
        return;
    }
    k = n % 10;
    j = n / 10;
    sum += k;
    f2(j, sum);
    cout<<k<<", ";
}

// Question 3
int f3(int &x, int c) {
    c -= 1;
    if (c == 0) {
        return 1;
    }
    x += 1;
    return f3(x, c) * x;
}

// Question 4
int f4(int n) {
    int x = 1, k;
    if (n == 1) {
        return x;
    }
    for (k = 1; k < n; k++) {
        x = x + f4(k) * f4(n - k);
    }
    return x;
}

// Question 5
void count(int n) {
    static int d = 1;
    cout<<n<<", "<<d<<", ";
    d++;
    if (n > 1) {
        count(n - 1);
    }
    cout<<d;
    if (d != n + 1) {
        cout<<", ";
    }
}

int main() {
    // Question 1
    cout<<"Question 1:\n"<<f1(1)<<"\n\n";

    // Question 2
    int a = 2048, sum = 0;
    cout<<"Question 2:\n";
    f2(a, sum);
    cout<<sum<<"\n\n";

    // Question 3
    int p = 5;
    cout<<"Question 3:\n"<<f3(p, p)<<"\n\n";

    // Question 4
    cout<<"Question 4:\n"<<f4(5)<<"\n\n";

    // Question 5
    cout<<"Question 5:\n";
    count(3);
    cout<<"\n";

    return 0;
}