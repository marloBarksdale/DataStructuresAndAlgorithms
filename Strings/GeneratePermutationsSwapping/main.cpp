#include <iostream>

void permutations(char array[], int k, int h);
void swap(char s[], int a, int b);
int main()
{

    char array[] = "abc";
    permutations(array, 0, 2);
    return 0;
}

void permutations(char s[], int k, int h)
{

    int i;
    if(k == h) {
        printf("%s\n", s);

    } else {

        for(i = k; i <=h; i++) {

            swap(s, k, i);

            permutations(s, k+1 , h);

            swap(s, k, i);
        }
    }
}

void swap(char s[], int a, int b)
{

    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}