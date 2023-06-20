#include <iostream>

using namespace std;

template <class T> class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T> Arithmetic<T>::Arithmetic(T a, T b)
{

    this->a = a;
    this->b = b;
}
template <class T> T Arithmetic<T>::add() { return this->a + this->b; }

template <class T> T Arithmetic<T>::sub() { return this->a - this->b; }

int main()
{
    Arithmetic ar = Arithmetic(5.5, 5.5);

    cout << ar.add() << endl;
}