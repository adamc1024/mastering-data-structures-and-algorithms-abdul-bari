#include <iostream>

using namespace std;

struct Rectangle {
    int width;
    int height;
};

// call by value
// changes to values within function
// will not modify actual variable
// int area(struct Rectangle rectangle) {
//     rectangle.width++;
//     return rectangle.width * rectangle.height;
// }

// call by reference
// changes to values within function
// will modify actual variable
// int area(struct Rectangle &rectangle) {
//     rectangle.width++;
//     return rectangle.width * rectangle.height;
// }

// int main() {
//     struct Rectangle r = {5,10};
//     cout<<area(r)<<endl;
//     cout<<r.width<<" "<<r.height<<endl;
//     return 0;
// }

// call by address
// changes to values within function
// will modify actual variable
// asterisk dereferences address
// void change_width(struct Rectangle *p, int w) {
//     // pointer structure uses 
//     // arrow to access values
//     p->width = 20;
// }

// int main() {
//     struct Rectangle r = {10,5};
//     cout<<r.width<<" "<<r.height<<endl;
//     // pass address of structure
//     // for call by address
//     change_width(&r, 20);
//     cout<<r.width<<" "<<r.height<<endl;
//     return 0;
// }

// struct Test {
//     int A[5];
//     int n;
// };

// void fun(struct Test t1) {
//     for (int i = 0; i < t1.n; i++) {
//         cout<<t1.A[i]<<endl;
//     }
// }

// int main () {
//     struct Test t = {{2, 4, 6, 8, 10}, 5};
//     fun(t);
//     return 0;
// }

// struct Rectangle *fun() {
//     struct Rectangle *p;
//     // C++
//     p = new Rectangle;
//     // C lang
//     // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
//     p->width = 0;
//     p->height = 0;
//     return p;
// }

// int main() {
//     struct Rectangle *r = fun();
//     cout<<r->height<<" "<<r->width<<endl;
//     return 0;
// }

void initialize(struct Rectangle *r, int w, int h) {
    r->width = w;
    r->height = h;
}

int area(struct Rectangle r) {
    return r.width * r.height;
}

void change_width(struct Rectangle *r, int w) {
    r->width = w;
}

int main() {
    struct Rectangle r;
    initialize(&r, 10, 5);
    area(r);
    change_width(&r, 20);
    return 0;
}