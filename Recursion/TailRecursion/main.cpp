#include <iostream>
using namespace std;
// Tail recursion because the recursive call is the last statement;

void fun(int n)
{

    if(n > 0) {
        cout << n << endl;

        fun(n - 1);
    }
}

int main() { fun(3); }