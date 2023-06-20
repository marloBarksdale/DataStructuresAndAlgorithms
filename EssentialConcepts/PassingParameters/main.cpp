#include <iostream>
using namespace std;
void swapRef(int& a, int& b)
{

    int temp = a;
    a = b;
    b = temp;
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}


void swapAdd(int* a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    int x = 4;
    int y = 200;

    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    swapAdd(&x, &y);

    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
}