#include <iostream>
#include <stdio.h>

using namespace std;

// // monolithic program
// // everything happens in main()
// int main() {
//     int width = 0, height = 0;
//     printf("Enter width and height: ");
//     cin>>width>>height;
//     int area = width * height;
//     int peri = 2 * width + 2 * height;
//     printf("Area = %d\nPerimeter = %d\n", area, peri);
//     return 0;
// }

// // modular program/procedural program
// int calc_area(int width, int height) {
//     return width * height;
// }

// int calc_perimeter(int width, int height) {
//     return 2 * (width + height);
// }

// int main() {
//     int width = 0; height = 0;
//     printf("Enter width and height: ");
//     cin>>width>>height;
//     int area = calc_area(width, height);
//     int perimeter = calc_perimeter(width, height);
//     printf("Area = %d\nPerimeter = %d\n", area, perimeter);
//     return 0;
// }

// modular program/procedural program
// with structure and functions
// struct Rectangle {
//     int width;
//     int height;
// };

// void initialize(struct Rectangle *p, int width, int height) {
//     p->width = width;
//     p->height = height;
// }

// int calc_area(struct Rectangle rectangle) {
//     return rectangle.width * rectangle.height;
// }

// int calc_perimeter(struct Rectangle rectangle) {
//     return 2 * (rectangle.width + rectangle.height);
// }

// int main() {
//     struct Rectangle r = {0, 0};
//     int w, h;
//     printf("Enter width and height: ");
//     cin>>w>>h;
//     initialize(&r, w, h);
//     int area = calc_area(r);
//     int perimeter = calc_perimeter(r);
//     printf("Area = %d\nPerimeter = %d\n", area, perimeter);
//     return 0;
// }

// object oriented program
class Rectangle {

    private:
        int width;
        int height;

    public:
        Rectangle(int w, int h) {
            width = w;
            height = h;
        }

        int calc_area() {
            return width * height;
        }

        int calc_perimeter() {
            return 2 * (width + height);
        }
};

int main() {

    int w = 0, h = 0;

    cout<<"Enter width: ";
    cin>>w;
    cout<<"Enter height: ";
    cin>>h;

    Rectangle r(w, h);

    cout<<"Area = "<<r.calc_area()<<endl;
    cout<<"Perimeter = "<<r.calc_perimeter()<<endl;
    
    return 0;
}