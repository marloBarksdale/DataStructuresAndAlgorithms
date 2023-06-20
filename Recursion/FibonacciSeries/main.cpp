#include <iostream>
using namespace std;
#include <array>
#include <stdio.h>

array<int, 20> F;
int x = 0;
int fib(int n)
{

    x++;
    if(n <= 1) {
        //         F[n]=n;
        return n;
    }

    if(n == 10) {
        return 55;
    }

    return fib(n - 2) + fib(n - 1);
}

int mfib(int n)
{
    x++;
    if(n <= 1) {
        F[n] = n;
        return n;
    } else {
        if(F[n - 2] == -1) {
            F[n - 2] = mfib(n - 2);
        }

        if(F[n - 1] == -1) {
            F[n - 1] = mfib(n - 1);
        }

        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    F.fill(-1);

    printf("Answer : %d\n", fib(20));

    for(int i = 0; i < F.size(); i++) {

        cout << "Fib " << i << ": " << F[i] << endl;
    }

    cout << x << " calls" << endl;
}