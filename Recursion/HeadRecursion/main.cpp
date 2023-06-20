#include <iostream>
using namespace std;
// Head recursion because the recursive call is the first statement;

void fun(int n)
{

    if(n > 0) {

        fun(n - 1);

        cout << n << endl;
    }


}

int main() { fun(3); }