// W4_Dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e9;  // Define a large constant to represent infinity (unreachable nodes)

// Function to add edges to the graph

void Add(vector<vector<pair<int, int>>>& Graph, int from, int to, int weight, bool IsDirected)
{
    Graph[from].push_back({ to, weight });  // Add an edge from 'from' to 'to' with the given weight
    if (!IsDirected)  // If the graph is undirected, add the reverse edge as well
    {
        Graph[to].push_back({ from, weight });
    }
}

// Function to perform Dijkstra's algorithm
// Graph , start node, and a vector to store distances from the start node to all other nodes
void Dijkstra(vector<vector<pair<int, int>>>& Graph, int start, vector<int>& distance)
{
	// pair <int, int> → We store {node, distance}. 
	//vector<pair<int, int>> → The underlying container to hold elements.
	//greater<> → This tells the priority queue to behave like a min-heap (smallest distance first).
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue_w4;
    

    distance[start] = 0;  // Set the distance of the start node to 0
    queue_w4.push({ start, 0 });  // Push the start node into the priority queue
    //queue_w4.push({ start, distance[start] });

    while (!queue_w4.empty())  // Continue until all nodes are processed
    {
        int node = queue_w4.top().first;  // Extract the node with the smallest distance
        int dist = queue_w4.top().second;  // Extract the distance of the node
        queue_w4.pop();  // Remove the node from the queue

        if (dist > distance[node]) continue;  // Ignore outdated distances

        // Iterate over all neighboring nodes
        for (auto neighbour : Graph[node])
        {
            int new_node = neighbour.first;  // Extract the neighboring node
            int w = neighbour.second;  // Extract the edge weight

            // If a shorter path to 'new_node' is found, update it
            if (w + distance[node] < distance[new_node])
            {
                distance[new_node] = w + distance[node];  // Update the shortest distance
                queue_w4.push({ new_node, distance[new_node] });  // Push the updated node into the queue
            }
        }
    }
}

int main()
{
    int nodes, edges;
    bool IsDirected;
    cout << "enter nodes and edges: ";
    cin >> nodes >> edges;  // Input number of nodes and edges
    cout << "enter 1 for directed and 0 for undirected: ";
    cin >> IsDirected;  // Input whether the graph is directed or not

    vector<vector<pair<int, int>>> Graph(nodes);  // Initialize adjacency list for the graph
    int from, to, weight;

    for (int i = 0; i < edges; i++)
    {
        cout << "enter from and to and weight: ";
        cin >> from >> to >> weight;  // Input edge details
        Add(Graph, from, to, weight, IsDirected);  // Add the edge to the graph
    }

    vector<int> distance(nodes, INF);  // Initialize all distances to infinity
    int start;

    cout << "enter start node: ";
    cin >> start;  // Input the starting node

    Dijkstra(Graph, start, distance);  // Run Dijkstra's algorithm from the start node

    return 0;  // End of program
}