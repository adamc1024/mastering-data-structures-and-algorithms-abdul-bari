#include <iostream>

using namespace std;

class Rectangle {

    private:    
        int width;
        int height;

    public:
        // initialization function
        Rectangle(int w, int h) {
            width = w;
            height = h;
        }

        int calc_area() {
            return width * height;
        }

        void change_width(int w) {
            width = w;
        }

        void display_info() {
            cout<<"Width: "<<width<<endl;
            cout<<"Height: "<<height<<endl;
            cout<<"Area: "<<calc_area()<<endl;
        }
};

int main() {
    Rectangle r(10, 5);
    r.change_width(20);
    r.display_info();
    return 0;
}