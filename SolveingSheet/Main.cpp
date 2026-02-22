#include <iostream>
#include <vector>
#include "1. Graph traversal_Sheet.cpp"
#include "2. DFS_Sheet.cpp"
#include "3. Dikjistra_Sheet.cpp"
#include "4. Complete Search_Sheet.cpp"
#include "5. Binary search_Sheet.cpp"
#include "6. Merge Sort_Sheet.cpp"
#include "7. Dynamic Programming_Sheet.cpp"
#include "8. GreedyAlgorithm_Sheet.cpp"
#include "9. Learning outcome 3_Sheet.cpp"
#include "10. Learning Outcome 4_Sheet.cpp"
#include "11. Learning Outcome 5_Sheet.cpp"
#include "BFS.cpp"
#include "DFS.cpp"
using namespace std;


int main()
{
	CompSearch CS;
	    vector<int> nums = { 1, 2, 3 };
	    vector<vector<int>> result = CS.subsets(nums);
	
	    cout << "Subsets:\n";
	    for (const auto& subset : result) {
	        cout << "[ ";
	        for (int num : subset) cout << num << " ";
	        cout << "]\n";
	    }
	
	    return 1;
	

}
