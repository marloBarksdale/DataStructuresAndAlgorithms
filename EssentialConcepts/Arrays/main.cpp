#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  
    int array[5]={0};
    array[0] = 6;
    
    int n=0;
    int a[n]={1,5,7};
    
    for(int i:array){
        cout<< i<<" ";
    }
    
    cout<<"\n";
    cout<<sizeof(array)<<"\n";
    cout <<sizeof(array[2])<<"\n";
    printf("%d\n", array[2]);
    
    return 0;
    
}