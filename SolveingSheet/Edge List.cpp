#include <iostream>
#include <vector>
using namespace std;


vector<pair<int, int>> buildEdgeList(vector<pair<int, int>>& edges) {
    vector<pair<int, int>> edgeList;

    for (auto edge : edges) {
        edgeList.push_back(edge);
    }

    return edgeList;
}


//int main() {
//
//    vector<pair<int, int>> edges = {
//        {0,1},
//        {0,2},
//        {1,3}
//    };
//
//    vector<pair<int, int>> edgeList = buildEdgeList(edges);
//
//    cout << "Edge List:\n";
//
//    for (auto edge : edgeList) {
//        cout << edge.first << " -> " << edge.second << endl;
//    }
//
//    return 0;
//}
