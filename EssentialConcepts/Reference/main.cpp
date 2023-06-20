#include <iostream>
using namespace std;





int ref(int& s)
{

    s = s * 2;
    return s;
}

int norm(int s)
{

    s = s * 2;
    return s;
}


int main()
{

    int a = 10;
    int& r = a;

    cout << "A: " << a << endl;
    cout << "R: " << r << endl;

    cout << "Norm: " << norm(a) << endl;
    cout << "A: " << a << endl;
    cout << "R: " << r << endl;

    cout << "Ref: " << ref(a) << endl;
    cout << "A: " << a << endl;
    cout << "R: " << r << endl;
}

