#include <iostream>

int main(){

    char A[] =  "Findingg";



    long int H = 0, x=0;

    x=1;
    x=x<<-224;

    printf("%li", x);



    for(int i = 0; A[i]!='\0'; i++){


        x=1;
int r = A[i]-97;
        x=x<<(A[i]-97);


        if((H&x) == 0){

            H=(H|x);
        }
        else{
            printf("%c is duplicate\n", A[i]);
        }
    }

}