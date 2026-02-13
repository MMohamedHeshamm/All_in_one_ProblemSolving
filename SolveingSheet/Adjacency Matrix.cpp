#include<vector>
using namespace std;

vector<vector<int>> buildAdjMatrix(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        matrix[u][v] = 1;
        matrix[v][u] = 1; // شيلها لو Directed
    }

    return matrix;
}


//for (int i = 0; i < n; i++) {
//    for (int j = 0; j < n; j++) {
//        cout << matrix[i][j] << " ";
//    }
//    cout << endl;
//}
