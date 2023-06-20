#include <iostream>
using namespace std;
// Tail recursion

int fact(int n)
{
    if(n <= 1) {
        return 1;
    }

    return fact(n - 1) * n;
}

int main() { cout << fact(10) << endl; }