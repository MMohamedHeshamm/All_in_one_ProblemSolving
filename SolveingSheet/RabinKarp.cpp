#include <iostream>
#include <string>
#include<cmath>
using namespace std;

// Rabin-Karp search function
bool rabinKarpSearch(const string& text, const string& pattern)
{
	const int prime = 101;  // Prime number for hashing
	const int base = 31;    // Base for hash calculation
	int n = pattern.length();
	int m = text.length();

	if (n > m) return false; // If pattern is longer than text, return false

	int patternHash = 0, textHash = 0, h = 1;

	// Compute the value of h = base^(patternLen-1) % primeا


	h = pow(base, n - 1);



	// ABCDEF -- > 1*31^5 + 2*31^4 + 3*31^3 + 4*31^2 + 5*31^1 + 6*31^0  ( m = 6 )
	// 
	// CD --> 3*31^1 + 4*31^0  ( n = 2 )
	// Compute hash for pattern and first window of text
	//n --> pattern length
	for (int i = 0; i < n; i++) 
	{
		patternHash = (patternHash * base + (pattern[i] - 'A' + 1)) % prime;
		textHash = (textHash * base + (text[i] - 'A' + 1)) % prime;

	}

	// Slide the window over the text
	for (int i = 0; i <= m - n; i++)
	{
		// Check if hashes match
		if (patternHash == textHash)
		{
			if (text.substr(i, n) == pattern)
			{
				return true;  // Pattern found
			}
		}

		// Slide the window: remove first letter, add next letter
		if (i < m - n)
		{
			textHash = (textHash - (text[i] - 'A' + 1) * h) % prime;
			textHash = (textHash * base + (text[i + n] - 'A' + 1)) % prime;


			// Ensure positive hash
			if (textHash < 0) textHash += prime;
		}
	}
	return false; // Pattern not found
}

int main() {
	string text = "abcde";
	string pattern = "abc";

	if (rabinKarpSearch(text, pattern)) {
		cout << "Pattern found in text!" << endl;
	}
	else 
	{
		cout << "Pattern NOT found in text!" << endl;
	}

	return 0;
}