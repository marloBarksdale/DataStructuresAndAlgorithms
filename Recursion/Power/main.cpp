#include <iostream>
using namespace std;
// Tree recursion because there are multiple recursive calls

int power(int n, int pow)
{
   if(pow==0){
       return 1;
   }

    return n * power(n, pow-1);

}

int main() { cout << power(2,8) << endl; }