#include <iostream>

void permutations(char array[], int k);
int main()
{
    std::cout << "Hello Testing!" << std::endl;

    char array[]="abc";
    permutations(array, 0);
    return 0;
}

void permutations(char s[], int k)
{

    static int A[20] = { 0 };
    static char Res[20];

     int i;

    if(s[k] == '\0') {
        Res[k] = '\0';
        printf("%s\n", Res);

    } else {

        for(i = 0; s[i] != '\0'; i++) {
            if(A[i] == 0) {
                Res[k] = s[i];
                A[i] = 1;
                permutations(s, k+1);
                A[i] = 0;
            }
        }
    }

}