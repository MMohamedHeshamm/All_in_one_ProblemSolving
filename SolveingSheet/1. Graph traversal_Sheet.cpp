#include <vector>
#include <queue>
using namespace std;


class Graph_traversal
{
public:

	//1- Find Center of Star Graph - LeetCode
	int findCenter(vector<vector<int>>& edges)
	{
		// parameters: edges: a 2D vector representing the edges
		// like [[1, 2], [1, 3], [1, 4]]

		#pragma region problem description
		/*

		There is an undirected star graph consisting of n nodes
		labeled from 1 to n.
		A star graph is a graph where there is one center node
		and exactly n - 1 edges that connect the center node
		with every other node.

		You are given a 2D integer array edges where each edges[i] = [ui, vi]
		indicates that there is an edge between the nodes ui and vi.
		Return the center of the given star graph.

		Constraints:

		3 <= n <= 105
		edges.length == n - 1
		edges[i].length == 2
		1 <= ui, vi <= n
		ui != vi
		The given edges represent a valid star graph.
		*/

		#pragma endregion

// لو لقيت ايدج واحده علي الاقل مشتركه فيهم نود واحد يبقي النود ده هو المركز

        // First edge
		int a = edges[0][0]; // 1
		int b = edges[0][1]; //2

		// second edge
		int c = edges[1][0]; // 1
		int d = edges[1][1]; // 3

		//  //third edge
		//  int e = edges[2][0]; // 1
		//  int f = edges[2][1]; // 4

		// The center node must be connected to all other nodes
		// , so it must appear in both edges.
		if (a == c || a == d) return a;


		return b;  // If a is not the center, then b must be the center.


		#pragma region Main
		/*

		   vector<vector<int>> edges = { {1, 2}, {1, 3}, {1, 2} };
		   Graph_traversal gt;
		   int center = gt.findCenter(edges);
		   cout << center << endl;
		   return 0;

		*/
		#pragma endregion

	}


	//2- Find the Town Judge - LeetCode 
	int findJudge(int n, vector<vector<int>>& trust)
	{
		// parameters: n: the number of people in the town
		// trust: a 2D vector where trust[i] = [a, b]
		// indicates that person a trusts person b

#pragma region problem description
/*
	In a town, there are n people labeled from 1 to n.
	There is a rumor that one of these people is secretly the town judge.

	If the town judge exists:
	1. The town judge trusts nobody.
	2. Everybody (except for the town judge) trusts the town judge.
	3. There is exactly one person that satisfies properties 1 and 2.

	Return the label of the town judge if exists, else -1.

	Constraints:

	1 <= n <= 1000
	0 <= trust.length <= 104
	trust[i].length == 2
	All the pairs of trust are unique.
	ai != bi
	1 <= ai, bi <= n

*/
#pragma endregion

//vector to store trust score for each person but start from 1 to n
		vector<int> trustScore(n + 1, 0);

		// Update trust score based on the trust relationships
		for (auto& t : trust) {
			int a = t[0]; // a trusts b
			int b = t[1]; // b is trusted by a

			trustScore[a]--; // a trusts someone → decrease score
			trustScore[b]++; // b is trusted → increase score
		}

		// Find the judge by checking who has trusted by everyone
		for (int i = 1; i <= n; i++)
		{
			if (trustScore[i] == n - 1) return i;
		}

		return -1; //if No judge found return -1



		//Why decrease score for the person who trusts someone else?
		// 
		// Because the town judge trusts nobody,
		// so if a person trusts someone else,
		// they cannot be the judge.
		// By decreasing their score,
		// we can easily identify the judge as the one with a score of n - 1 
		// (trusted by everyone else and trusts no one).



#pragma region Main
		/*
			#include <iostream>
		#include <vector>
		#include "Graph traversal.cpp"
		using namespace std;
		
		
		int main() 
		{
			// Example 1
			int n1 = 2;
			vector<vector<int>> trust1 = { {1,2} };
			Graph_traversal gt;
			cout << "Town Judge is: " << gt.findJudge(n1, trust1) << endl; // Output: 2
		
			// Example 2
			int n2 = 3;
			vector<vector<int>> trust2 = { {1,3},{2,3} };
			cout << "Town Judge is: " << gt.findJudge(n2, trust2) << endl; // Output: 3
		
			// Example 3
			int n3 = 3;
		    vector<vector<int>> trust3 = { {1,3},{2,3},{3,1} };
			cout << "Town Judge is: " << gt.findJudge(n3, trust3) << endl; // Output: -1

		}
		*/
		
		

		#pragma endregion




	}


	//3- Find if Path Exists in Graph - LeetCode

	bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
	{
			// if source and destination are the same, we can return true immediately
			if (source == destination) return true;

			// 1) Build adjacency list
			vector<vector<int>> adj(n);

			for (auto& e : edges)
			{
				int u = e[0];
				int v = e[1];

				adj[u].push_back(v);
				adj[v].push_back(u); // undirected graph
			}

			// 2) BFS to find if there is a path from source to destination
			vector<bool> visited(n, false);
			queue<int> q;

			q.push(source);
			visited[source] = true;

			while (!q.empty())
			{
				int node = q.front();
				q.pop();

				if (node == destination) return true;

				for (int neighbor : adj[node])
				{
					if (!visited[neighbor])
					{
						visited[neighbor] = true;
						q.push(neighbor);
					}
				}
			}

			// finding the destination		
			 return false;
	}


	//4- Minimum Score of a Path Between Two Cities - LeetCode
	#pragma region 4
	int minScore1 = INT_MAX;

	void dfs(int city, vector<vector<pair<int, int>>>& adj, vector<bool>& visited)
	{
		visited[city] = true;

		for (auto& neighbor : adj[city]) {
			int nextCity = neighbor.first;
			int distance = neighbor.second;


			minScore1 = min(minScore1, distance);

			if (!visited[nextCity])
			{
				dfs(nextCity, adj, visited);
			}
		}
	}
	int minScore(int n, vector<vector<int>>& roads) {
		vector<vector<pair<int, int>>> adj(n + 1);


		for (auto& road : roads) {
			int a = road[0];
			int b = road[1];
			int dist = road[2];

			adj[a].push_back({ b, dist });
			adj[b].push_back({ a, dist });
		}

		vector<bool> visited(n + 1, false);

		dfs(1, adj, visited);

		return minScore1;
	}


	#pragma endregion

	
};




