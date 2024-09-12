#include <iostream>

using namespace std;

struct Card {
    int suit;
    int value;
};

struct Rectangle {
    int width;
    int height;
    char x;
};

int main() {
    /*
    struct Card deck[52];
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[count].suit = i;
            deck[count].value = j;
            count++;
        }
    }
    for (int i = 0; i < 52; i++) {
        cout<<deck[i].suit<<endl;
        cout<<deck[i].value<<endl;
    }
    */
    struct Rectangle r1 = {10,5,'a'};
    printf("Size: %lu bytes\n", sizeof(r1));
    puts("R1");
    cout<<r1.width<<endl;
    cout<<r1.height<<endl;
    cout<<r1.x<<endl;
    r1.width = 12;
    r1.height = 6;
    r1.x = 'b';
    puts("R1");
    cout<<r1.width<<endl;
    cout<<r1.height<<endl;
    cout<<r1.x<<endl;
    return 0;
}