#include <iostream>
using namespace std;
// Tree recursion because there are multiple recursive calls

int fun(int n)
{

    if(n > 100) {

        cout << n << endl;
        return n - 10;

    } else {
        return fun(fun(n + 11));
    }
}

int main() { cout << fun(95) << endl; }