#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(string pattern) 
{
    int m = pattern.length();
    vector<int> lps(m, 0);  // LPS array initialized to 0
    int len = 0;  // Length of the previous longest prefix suffix
    int i = 1;  // Start from the second character

    while (i < m) 
    {
        if (pattern[i] == pattern[len]) 
        {
            len++;          // Increase the length of the prefix suffix
            lps[i] = len;   // Store it in the LPS array
            i++;            // Move to the next character
        }
        else {
            if (len != 0) 
            {
                len = lps[len - 1];  // Move back in the LPS array
            }
            else 
            {
                lps[i] = 0;  // No prefix suffix match
                i++;
            }
        }
    }
    return lps;
}


void KMPSearch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);  // Compute the LPS array

    int i = 0;  // Pointer for text
    int j = 0;  // Pointer for pattern

    while (i < n) 
    {
        if (pattern[j] == text[i]) {  // Characters match
            i++;
            j++;
        }

        if (j == m) 
        {  // Pattern found at index (i - j)
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // Move j based on LPS array
        }
        else if (i < n && pattern[j] != text[i]) 
        {  // Mismatch occurs
            if (j != 0) 
            {
                j = lps[j - 1];  // Move j using LPS array
            }
            else 
            {
                i++;  // Move to the next character in text
            }
        }
    }
}


int main() 
{
    string text = "ABABABACABABABAC";
    string pattern = "ABABAC";

    cout << "Searching for pattern in text..." << endl;
    KMPSearch(text, pattern);

    return 0;
}