#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function تحسب أقصر مسافة من start لكل النود
vector<int> dijkstra(vector<vector<int>> graph, int start) {

    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; i++) {

        int u = -1;

        // نختار أقرب نود لسه متزارتش
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


//int main() {
//
//    vector<vector<int>> graph = {
//        {0, 4, 1, 0},
//        {4, 0, 2, 5},
//        {1, 2, 0, 8},
//        {0, 5, 8, 0}
//    };
//
//    vector<int> result = dijkstra(graph, 0);
//
//    cout << "Shortest distances:\n";
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << " ";
//    }
//}
