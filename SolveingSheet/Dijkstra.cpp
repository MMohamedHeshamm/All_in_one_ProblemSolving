#include <iostream>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int V)
{
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

void dijkstra(int** graph, int V, int src)
{
    int* dist = new int[V];
    bool* sptSet = new bool[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);

    delete[] dist;
    delete[] sptSet;
}


//int main()
//{
//    int V = 5;  // هنا تحدد الحجم اللي انت عايزه
//
//    // إنشاء الجراف
//    int** graph = new int* [V];
//    for (int i = 0; i < V; i++)
//        graph[i] = new int[V];
//
//    // مثال تعبئة القيم
//    graph[0][1] = 10;
//    graph[1][2] = 5;
//    // ... كمل باقي القيم
//
//    dijkstra(graph, V, 0);
//
//    return 0;
//}
