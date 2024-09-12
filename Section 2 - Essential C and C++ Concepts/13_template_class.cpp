#include <iostream>
#include <math.h>

using namespace std;

template <class T>
class Arithmetic {
private:
    T a;
    T b;
public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b) {
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add() {
    return a + b;
}

template <class T>
T Arithmetic<T>::sub() {
    return a - b;
}

int main() {
    Arithmetic<int> ar(10, 5);
    cout<<"Add: "<<ar.add()<<endl;
    cout<<"Subtract: "<<ar.sub()<<endl;
    Arithmetic<float> ar1(1.416, 6.78);
    cout<<"Add: "<<ar1.add()<<endl;
    cout<<"Subtract: "<<ar1.sub()<<endl;
    return 0;
}

// template <class T>
// class Rectangle {
// private:
//     T width;
//     T height;
// public:
//     // Constructors
//     Rectangle() {
//         width = 0;
//         height = 0;
//     }
//     Rectangle(T width, T height);
//     // Methods
//     T area();
//     T perimeter();
//     float diagonal();
//     T get_width();
//     T get_height();
//     void set_width(T width);
//     void set_height(T height);
//     // Destructor
//     ~Rectangle() {};
// };

// template <class T>
// Rectangle<T>::Rectangle(T width, T height) {
//     this->width = width;
//     this->height = height;
// }

// template <class T>
// T Rectangle<T>::area() {
//     return width * height;
// }

// template <class T>
// T Rectangle<T>::perimeter() {
//     return (width + height) * 2;
// }

// template <class T>
// float Rectangle<T>::diagonal() {
//     return pow((pow(width, 2) + pow(height, 2)), .5);
// }

// template <class T>
// T Rectangle<T>::get_width() {
//     return width;
// }
// template <class T>
// T Rectangle<T>::get_height() {
//     return height;
// }

// template <class T>
// void Rectangle<T>::set_width(T width) {
//     this->width = width;
// }

// template <class T>
// void Rectangle<T>::set_height(T height) {
//     this->height = height;
// }

// int main() {
//     Rectangle<int> r(5, 9);
//     cout<<"Area: "<<r.area()<<endl;
//     cout<<"Perimeter: "<<r.perimeter()<<endl;
//     cout<<"Diagonal: "<<r.diagonal()<<endl;
//     Rectangle<float> r1(3.4, 5.5);
//     cout<<"Area: "<<r1.area()<<endl;
//     cout<<"Perimeter: "<<r1.perimeter()<<endl;
//     cout<<"Diagonal: "<<r1.diagonal()<<endl;
//     return 0;
// }