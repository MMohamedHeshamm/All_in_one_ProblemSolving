//1- 
#pragma region Question 1

#include <iostream>
#include<vector>
using namespace std;

class CompSearch {
public:
	//parameters : indx : the current index in the nums array,
	// subset : the current subset being built,
	// RES : the result vector to store all subsets,
	// nums : the input array
	void generateSubsets(int indx, vector<int>& subset, vector<vector<int>>& RES, vector<int>& nums)
	{

		if (indx == nums.size())
		{
			RES.push_back(subset);
			return;
		}


		generateSubsets(indx + 1, subset, RES, nums);
		subset.push_back(nums[indx]);
		generateSubsets(indx + 1, subset, RES, nums);
		subset.pop_back();

	}

	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>>RES;
		vector<int>subset;

		generateSubsets(0, subset, RES, nums);

		return RES;


	}
};




//int main()
//{
//    CompSearch sol;
//    vector<int> nums = { 1, 2, 3 };
//    vector<vector<int>> result = sol.subsets(nums);
//
//    cout << "Subsets:\n";
//    for (const auto& subset : result) {
//        cout << "[ ";
//        for (int num : subset) cout << num << " ";
//        cout << "]\n";
//    }
//
//    return 0;
//
//
//}




#pragma endregion


//=========================================================
//=========================================================
//=========================================================
//=========================================================

#pragma region Question 2

#include <iostream>
#include <vector>
using namespace std;

class FibonacciMemoization
{

	long  fib(int n, vector<long >& memo)
	{
		if (n <= 1)
			return n;

		if (memo[n] != -1)   // already computed
			return memo[n];

		memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
		return memo[n];
	}

	/*int main()
	{
		int n = 5;
		vector<long> memo(n + 1, -1);

		cout << "Fibonacci of " << n << " = "
			<< fib(n, memo) << endl;

		return 0;
	}*/
};



#pragma endregion

