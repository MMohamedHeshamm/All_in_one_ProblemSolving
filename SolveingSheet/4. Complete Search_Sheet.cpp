//1- 
#pragma region Question 1
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/
// Subsets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

