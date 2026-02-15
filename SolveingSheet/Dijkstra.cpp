#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Dijkstra
{
 public:
    //calculate the shortest path from start node to all other nodes in the graph
    vector<int> dijkstra(vector<vector<int>> graph, int start) {

        int n = graph.size();

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[start] = 0;

        for (int i = 0; i < n; i++) {

            int u = -1;

            //choose the unvisited node with the smallest distance
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            for (int v = 0; v < n; v++) {

                if (graph[u][v] != 0) {

                    if (dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
        }

        return dist;
    }
};

//int main() {
// 
//    dijkstra DijkstraObj;
//
//    vector<vector<int>> graph = {
//        {0, 4, 1, 0},
//        {4, 0, 2, 5},
//        {1, 2, 0, 8},
//        {0, 5, 8, 0}
//    };
//
//    vector<int> result = DijkstraObj.dijkstra(graph, 0);
//
//    cout << "Shortest distances:\n";
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << " ";
//    }
//}
