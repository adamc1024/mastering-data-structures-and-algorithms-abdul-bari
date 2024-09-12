#include <iostream>

using namespace std;

double e_1(int x, int n) {
    static double p = 1, f = 1;
    double r;
    if (n == 0) {
        return 1;
    }
    else {
        r = e_1(x, n - 1);
        p *= x;
        f *= n;
        return r + p/f;
    }
}

double e_2(double x, double n) {
    double r = 1;
    for (; n > 0; n--) {
        r *= x / n;
        r++;
    }
    return r;
}

double e_3(double x, double n) {
    static double r = 1; 
    if (n == 0) {
        return r;
    }
    r *= x / n;
    r++;
    return e_3(x, n - 1);
}

int main() {
    cout<<e_3(1, 4)<<endl;
    return 0;
}