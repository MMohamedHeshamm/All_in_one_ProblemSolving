#include <iostream>
#include <cmath>
using namespace std;

// Rabin-Karp algorithm for string matching ( txt: text, pattern: pattern to search )
int RabinKarp(string txt, string pattern)
{
	
	int n = txt.size(); // Length of the text
	int m = pattern.size(); // Length of the pattern

	// If pattern is longer than text, it cannot be found
    if (m > n) return -1;

	// Base and prime for hashing
	int Base = 256; // #  character set size (e.g., ASCII)
	int prime = 101; // A prime number to reduce collisions

    long long h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * Base) % prime;  // h = pow(Base, m - 1) % prime
    }

    long long pattHash = 0;
    long long txtHash = 0;

    // Precompute powers and hashes like in your original style
    for (int i = 0; i < m; i++)
    {
        pattHash += (1LL * pattern[i] * ((long long)(pow(Base, m - i - 1)) % prime));
        pattHash %= prime;

        txtHash += (1LL * txt[i] * ((long long)(pow(Base, m - i - 1)) % prime));
        txtHash %= prime;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (pattHash == txtHash)
        {
            if (txt.substr(i, m) == pattern)
                return i;
        }

        if (i < n - m)
        {
            // Update txtHash using the same formula style
            txtHash = txtHash - ((long long)txt[i] * ((long long)(pow(Base, m - 1)) % prime));
            txtHash = (txtHash * Base + txt[i + m]) % prime;

            if (txtHash < 0)
                txtHash += prime;
        }
    }

    return -1;
}

int repeatedStringMatch(string a, string b)
{
    string repeated = a;
    int count = 1;

    while (repeated.size() < b.size())
    {
        repeated += a;
        count++;
    }

    if (RabinKarp(repeated, b) != -1)
        return count;

    repeated += a;
    count++;

    if (RabinKarp(repeated, b) != -1)
        return count;

    return -1;
}



int strStr(string haystack, string needle) {
    return RabinKarp(haystack, needle);
}

int main()
{
	cout << repeatedStringMatch("abcd", "cdabcdab") << endl; // Output: 3
    cout << "\n";
	cout << strStr("HappyOrsad", "Or");                     // Output: 5
    return 0;
}


