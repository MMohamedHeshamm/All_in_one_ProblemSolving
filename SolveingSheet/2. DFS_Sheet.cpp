#include <vector> 
using namespace std;

int diameter = 0;

int dfs(int node, int parent, vector<vector<int>>& adj)
{
	int max1 = 0, max2 = 0; 
	for (int neighbor : adj[node])
	{
		if (neighbor == parent) continue;

		int h = dfs(neighbor, node, adj) + 1;
		if (h > max1)
		{
			max2 = max1; max1 = h;
		}
		else if (h > max2)
		{
			max2 = h;
		}
	}
	diameter = max(diameter, max1 + max2);
	return max1;
}
int solve(vector<int>& A)
{
	int n = A.size(); vector<vector<int>> adj(n); int root = -1; // build tree for (int i = 0; i < n; i++) { if (A[i] == -1) { root = i; } else { adj[i].push_back(A[i]); adj[A[i]].push_back(i); } } dfs(root, -1, adj); return diameter; }



};