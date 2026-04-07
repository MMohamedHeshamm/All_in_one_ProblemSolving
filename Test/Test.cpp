#include <iostream>
#include <string>
#include<cmath>
using namespace std;

// Rabin-Karp search function
bool rabinKarpSearch(const string& text, const string& pattern)
{
	const int prime = 101;  // Prime number for hashing
	const int base = 31;    // Base for hash calculation
	int patternLen = pattern.length();
	int textLen = text.length();
	
	if (patternLen > textLen) return false; // If pattern is longer than text, return false

	int patternHash = 0, winHash = 0, h = 1;

	// Compute the value of h = base^(patternLen-1)


	h = pow(base, patternLen - 1);


	// Compute hash for pattern and first window of text
	for (int i = 0; i < patternLen; i++)
	{
		patternHash = (patternHash * base + (pattern[i] - 'A' + 1)) % prime;
		winHash = (winHash * base + (text[i] - 'A' + 1)) % prime;

	}

	// Slide the window over the text
	for (int i = 0; i <= textLen - patternLen; i++)
	{
		// Check if hashes match
		if (patternHash == winHash)
		{
			if (text.substr(i, patternLen) == pattern)
			{
				return true;  // Pattern found
			}
		}

		// Slide the window: remove first letter, add next letter
		if (i < textLen - patternLen)
		{
			winHash = (winHash - (text[i] - 'A' + 1) * h) % prime;
			winHash = (winHash * base + (text[i + patternLen] - 'A' + 1)) % prime;


			// Ensure positive hash
			if (winHash < 0) winHash += prime;
		}
	}
	return false; // Pattern not found
}

int main() 
{
	string text = "abcde";
	string pattern = "de";

	if (rabinKarpSearch(text, pattern)) 
	{
		cout << "Pattern found in text!" << endl ;
	}
	else 
	{
		cout << "Pattern NOT found in text!" << endl ;
	}

	return 0;
}