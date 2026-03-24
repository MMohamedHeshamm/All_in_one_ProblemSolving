#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//                           strs[0] ,strs[1]  ,strs[2]
//                         { Flower , flow , flight }
string longestCommonPrefix(vector<string> strs)
{
	//check if the vector is empty or not
	if (strs.empty())
		return " this vector is empty ";

	

	sort(strs.begin(), strs.end());  // Sort words alphabetically

	string first = strs[0];
	string last = strs[strs.size() - 1]; // strs[2]
	int counter = 0;
	//        0   <                     0    <
	while (counter < first.size() && counter < last.size() && first[counter] == last[counter])
	{
		counter++;
	}
	
	
	/*
		for(int i =0; i<first.size()&&last.size() ;i++)
		{
			if (first[i]==last[i])
			counter++;
			else
			break;
		}

	 */

	return first.substr(0, counter);
	/*

	if you wanna print the common instead of substr u can do the following
	for(int i=0; i<counter; i++)
	cout<<first[i]<<" ";

	*/
}

int main()
{
	vector<string> words = { "flower", "flow", "flight" };

	/*

			int n;
			for()
			{
				//push_back
			}

	*/

	cout << "LCP: " << longestCommonPrefix(words) << endl; // Output: "fl"
	return 0;
}


/*

		before sorting
		["flower", "flow", "flight"]


		After sorting
		["flight", "flow", "flower"]

*/