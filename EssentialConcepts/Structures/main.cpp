#include <stdio.h>
using namespace std;
int main()
{

    struct Rectangle {
        int length;
        int width;
    };

    Rectangle r = { 1, 5 };

    Rectangle x[52] = { { 3, 4 } };

    x[1] = r;

    printf("%d\n", x[0].length);

    printf("%d\n", r.width);
    cout << sizeof(r) << endl;

    return 0;
}