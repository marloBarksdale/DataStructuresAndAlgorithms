#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

string reverseString(string s);
int main()
{

    cout << reverseString("we  h ") << endl;


    return 0;
}

string reverseString(string s)
{

//    reverse(s.begin(), s.end());
    printf("%s\n", s.data());
    int n = s.size();
    int idx = 0;
    for(int start = 0; start < n; ++start) {
        if(s[start] != ' ') {
            // go to the beginning of the word
            if(idx != 0)
                s[idx++] = ' ';

            // go to the end of the word
            int end = start;
            while(end < n && s[end] != ' ')
                s[idx++] = s[end++];

            // reverse the word
            reverse(s.begin() + idx - (end - start), s.begin() + idx);

            // move to the next word
            start = end;
        }
    }
    s.erase(s.begin() + idx, s.end());

    return s;
}