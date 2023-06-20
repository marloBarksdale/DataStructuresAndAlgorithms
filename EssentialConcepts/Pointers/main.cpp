#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{

    int* p = (int*)malloc(5 * sizeof(int));

    int x = *p;

    cout << x << " " << p << endl;


    free(p);
    delete void* p;
}