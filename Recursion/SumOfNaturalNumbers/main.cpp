#include <iostream>
using namespace std;
// Tree recursion because there are multiple recursive calls

int sum(int n)
{
    if(n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int main() { cout << sum(7) << endl; }