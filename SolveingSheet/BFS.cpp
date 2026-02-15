#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFS
{
public:

	//param start: the starting node for BFS traversal
	//param adj: the adjacency list representation of the graph
	void bfs(int start, vector<vector<int>>& adj, int n)
	{
		// Create a visited array to keep track of visited nodes
		vector<bool> isVisited(n, false);

		// Create a queue for BFS traversal
		queue<int> queue;

		isVisited[start] = true;

		queue.push(start);

		while (!queue.empty()) 
		{
			
			int node = queue.front();
			queue.pop();
			cout << node << " ";

			for (int neighbor : adj[node])
			{
				if (!isVisited[neighbor])
				{
					isVisited[neighbor] = true;
					queue.push(neighbor);
				}
			}
		}
	}

};

//int main()
//{
//
//	int n = 7;
//	BFS bfsObj;
//	vector<vector<int>> adj(n);
//
//	adj[0] = { 1, 2 };
//	adj[1] = { 0, 3 , 6 };
//	adj[2] = { 0, 4 , 5 };
//	adj[3] = { 1 };
//	adj[4] = { 2 };
//	adj[5] = { 2 };
//	adj[6] = { 1 };
//
//	cout << "BFS : ";
//	bfsObj.bfs(0, adj, n);
//
//
//};





