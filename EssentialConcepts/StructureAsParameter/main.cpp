#include <iostream>
using namespace std;

struct Rectangle {

    int length;
    int width;
    int area;
};

void area(Rectangle& r) { r.area = r.length * r.width; }

Rectangle* func()
{

    Rectangle* x = (Rectangle*)malloc(sizeof(Rectangle));
    Rectangle* v = (Rectangle*)malloc(sizeof(Rectangle));

    x->length = 87;
    x->width = 6;
    v->length = 90;
}

int main()
{

    Rectangle x = { 5, 7 };

    area(x);

    Rectangle* g = func();

    cout << g->length << endl;
}
