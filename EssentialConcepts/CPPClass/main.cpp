#include <iostream>
using namespace std;
class Rectangle
{

private:
    int length;
    int width;

public:
    Rectangle()
    {
        length = 0;
        width = 0;
    }

    Rectangle(int length, int width)
    {
        this->length = length;
        this->width = width;
    }

    int area() { return length * width; }

    int perimeter() { return 2 * (length + width); }

    void setLength(int length) { this->length = length; }

    void setWidth(int width) { this->width = width; }

    int getLength() { return length; }

    int getWidth() { return width; }


    ~Rectangle(){
        cout<<"Destructor";
    }
};

int main()
{

    Rectangle r = Rectangle(6, 8);

    cout << r.getLength()<<endl;
}