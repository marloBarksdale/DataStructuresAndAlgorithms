#include <iostream>
using namespace std;

int* fun(int n) { return (int*)malloc(sizeof(int) * n); }

int main()
{
    int* r = fun(5);
    r[2] = 6;
    r[0] = 17;
    cout << r[2];

    int* k = r;

    cout << *k << endl;


    for(auto i:r){
        cout<<i<<" ";
    }
}