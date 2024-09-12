#include <iostream>
#include <math.h>

using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    // Constructors
    Rectangle() {
        width = 0;
        height = 0;
    }
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    // Methods
    double area() {
        return width * height;
    }
    double perimeter() {
        return (width + height) * 2;
    }
    double diagonal() {
        return pow((pow(width, 2) + pow(height, 2)), .5);
    }
    double get_width() {
        return width;
    }
    double get_height() {
        return height;
    }
    void set_width(double w) {
        width = w;
    }
    void set_height(double h) {
        height = h;
    }
    // Destructor
    ~Rectangle() {
        cout<<"Destructor\n";
    };
};

int main() {
    Rectangle r(34, 55);
    cout<<"Area: "<<r.area()<<endl;
    cout<<"Perimeter: "<<r.perimeter()<<endl;
    cout<<"Diagonal: "<<r.diagonal()<<endl;
    return 0;
}