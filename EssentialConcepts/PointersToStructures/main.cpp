#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{

    struct Rectangle {
        int length;
        int width;
    };

    Rectangle a = { 10, 3 };

    cout << "A: " << a.length << " " << a.width << endl;

    Rectangle* p = &a;
    p->length = 0;

    cout << "A: " << p->length << " " << p->width << endl;

    cout << "A: " << a.length << " " << a.width << endl;

    p = (Rectangle*)malloc(sizeof(struct Rectangle));

    p->width = 6;
    (*p).length = 12;

    cout << "P: " << p->length << " " << p->width << endl;


    Rectangle* k = p;
    a = *k;
    k->length = 300;

    cout << "P: " << p->length << " " << p->width << endl;
    cout << "K: " << k->length << " " << k->width << endl;
    cout << "A: " << a.length << " " << a.width << endl;

    return 0;
}