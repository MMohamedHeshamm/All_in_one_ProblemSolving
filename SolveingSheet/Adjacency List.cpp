#include <iostream>
#include <vector>
using namespace std;

// n: number of vertices
// edges: list of edges
class adjlist
{
public:
    vector<vector<int>> buildAdjList(int n, const vector<pair<int, int>>& edges)
    {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;

            adj[u].push_back(v);
            adj[v].push_back(u);   // remove this line if graph is directed
        }

        return adj;
    }

};


//int main()
//{
//    int n = 4;
//
//    vector<pair<int, int>> edges =
//    {
//        {0,1},
//        {0,2},
//        {1,3}
//    };
//
//    vector<vector<int>> graph = buildAdjList(n, edges);
//
//    cout << "Adjacency List:\n";
//
//    for (int i = 0; i < n; i++)
//    {
//        cout << i << " -> ";
//
//        for (int neighbor : graph[i])
//        {
//            cout << neighbor << " ";
//        }
//
//        cout << endl;
//    }
//
//    return 0;
//}
