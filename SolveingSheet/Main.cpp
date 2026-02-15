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

	int n = 7;
		BFS bfsObj;
		vector<vector<int>> adj(n);
	
		adj[0] = { 1, 2 };
		adj[1] = { 0, 3 , 6 };
		adj[2] = { 0, 4 , 5 };
		adj[3] = { 1 };
		adj[4] = { 2 };
		adj[5] = { 2 };
		adj[6] = { 1 };
	
		cout << "BFS : ";
		bfsObj.bfs(0, adj, n);
	

}
