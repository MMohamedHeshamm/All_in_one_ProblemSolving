#include <iostream>
#include <vector>
using namespace std;

// Undirected Graph
vector<vector<int>> buildAdjList(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u); // شيلها لو الجراف Directed
    }

    return adj;
}



//int main() {
//    int n = 5;
//    vector<pair<int, int>> edges = {
//        {0,1}, {0,2}, {1,3}, {2,4}
//    };
//
//    vector<vector<int>> adj = buildAdjList(n, edges);
//
//    for (int i = 0; i < n; i++) {
//        cout << i << ": ";
//        for (int v : adj[i])
//            cout << v << " ";
//        cout << endl;
//    }
//}
