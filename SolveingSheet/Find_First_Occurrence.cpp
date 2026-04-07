#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) 
{
    int m = haystack.length();
    int n = needle.length();

    for (int i = 0; i <= m - n; i++) 
    {
        int j = 0;

        // check match
        while (j < n && haystack[i + j] == needle[j]) 
        {
            j++;
        }

        // full match found
        if (j == n) 
        {
            return i;
        }
    }

    return -1;
}

int main() 
{
    cout << strStr("ksadbutsad", "sad") << endl; // 0
    cout << strStr("leetcode", "leeto") << endl; // -1
}