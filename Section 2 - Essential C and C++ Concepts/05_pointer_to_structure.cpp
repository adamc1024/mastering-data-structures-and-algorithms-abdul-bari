#include <iostream>

using namespace std;

struct Rectangle {
    int width;
    int height;
};

int main()
{
    /*
    // Example 1

    struct Rectangle r = {10,5};
    struct Rectangle *p = &r;

    // these do the same thing
    (*p).height = 15;
    p->width = 20;
    */

    // Create object in the heap
    struct Rectangle *p;
    //*********************************
    // these do the same thing 

    // C lang
    // malloc allocates memory in heap 
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    // C++
    p = new Rectangle;
    //*********************************
    p->width = 10;
    p->height = 5;
    cout<<p->width<<endl<<p->height<<endl;
    return 0;
}
