#include <iostream>
#include <vector>
using namespace std;

class DFS
{
public:
	//param node: the current node being visited
	//param adj: the adjacency list representation of the graph
	//param visited: a boolean vector to keep track of visited nodes

	void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
	{
		visited[node] = true;
		cout << node << " ";

		for (int neighbor : adj[node])
		{
			if (!visited[neighbor])
			{
				dfs(neighbor, adj, visited);
			}
		}
	}



};


int main() 
 {
    int n = 5;
 
    vector<vector<int>> adj(n);
 
	  DFS DFSObj;

    // Undirected Graph
    adj[0] = { 1, 2 };
    adj[1] = { 0, 3 };
    adj[2] = { 0, 4 };
    adj[3] = { 1 };
    adj[4] = { 2 };

    vector<bool> visited(n, false);

    cout << "DFS : ";
    DFSObj.dfs(0, adj, visited);
}
