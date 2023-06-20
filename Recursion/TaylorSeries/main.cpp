

#include <iostream>
using namespace std;
int power(int n, int pow)
{
   if(pow==0){
       return 1;
   }

    return n * power(n, pow-1);

}


int sum(int n)
{
    if(n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int fact(int n)
{
    if(n <= 1) {
        return 1;
    }

    return fact(n - 1) * n;
}



double taylorSeries(int x, int n){


    static double p=1, f=1;
    double r;
    if(n==0){
        return 1;
    }

    r=taylorSeries(x,n-1);
    p=p*x;
    f=f*n;




        return r+p/f;

    }

int main() { cout << taylorSeries(2,100) << endl; }