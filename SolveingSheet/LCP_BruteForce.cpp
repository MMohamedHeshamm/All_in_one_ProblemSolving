#include <iostream>
#include <vector>
using namespace std;



//     name of function ( LCP )  paramters -- >  vector<string> { Words }
string longestCommonPrefix(vector<string>& strs)
{

	// Check vector if it have any Words or not 
	// empty return boolen value 
	// if value true  --> empty vector 
	if (strs.empty())
		return "";

	string prefix = strs[0];  // Start with the first word

	for (int i = 1; i < strs.size(); i++)
	{

		// Compare with each word

		int Counter = 0;// to iterate over charachters
		while (Counter < prefix.size() && Counter < strs[i].size() 
			&& prefix[Counter] == strs[i][Counter])
		{ 
			Counter++;
		}


		/*

		j = 0; → Initialize an index for character-by-character comparison.

		while loop:

		Ensures we don't go out of bounds (j < prefix.size() and j < strs[i].size()).

		Continues as long as characters match (prefix[j] == strs[i][j]).

		Increments j to check the next character


		*/

		prefix = prefix.substr(0, Counter);  // Keep only the common part


		if (prefix.empty())
			return "no Common Prefix";  // If no common prefix, return empty string
	}

	/*The prefix is updated to the first j characters (prefix.substr(0, j)).

		If no common characters are found (j = 0), prefix becomes an empty string.

	*/
	return prefix;
}

int main() 
{
	vector<string> words = { "flower", "flow", "flight" };


	cout << "LCP: " << longestCommonPrefix(words) << endl;  // Output: "fl"
	return 0;
}

/*

Time Complexity
Worst case: O(N * M), where:

N is the number of words.

M is the length of the longest word.

Best case: O(N), if all words share the same prefix


*/