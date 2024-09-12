#include <iostream>

using namespace std;

int count_1 = 0, count_2 = 0;

int pow_1(int m, int n) {
    count_1++;
    if (n == 0) {
        return 1;
    }
    return pow_1(m, n - 1) * m;
}

int pow_2(int m, int n) {
    count_2++;
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return pow_2(m * m, n / 2);
    }
    else {
        return m * pow_2(m * m, (n - 1) / 2);
    }
}

int main() {
    cout<<pow_1(2,8)<<endl<<"Call count: "<<count_1<<endl;
    cout<<pow_2(2,8)<<endl<<"Call count: "<<count_2<<endl;
    return 0;
}