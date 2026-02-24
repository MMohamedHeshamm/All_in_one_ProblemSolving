#include <iostream>
#include <vector>
#include "1. Graph traversal_Sheet.cpp"
#include "2. DFS_Sheet.cpp"
#include "3. Dikjistra_Sheet.cpp"
#include "4. Complete Search_Sheet.cpp"
#include "5. Binary search_Sheet.cpp"
#include "6. Merge Sort_Sheet.cpp"
#include "7. Dynamic Programming_Sheet.cpp"
#include "8. GreedyAlgorithm_Sheet.cpp"
#include "9. Learning outcome 3_Sheet.cpp"
#include "10. Learning Outcome 4_Sheet.cpp"
#include "11. Learning Outcome 5_Sheet.cpp"
#include "BFS.cpp"
#include "DFS.cpp"
using namespace std;


int main() {
    int rod_Length;
    DP db;

    cout << "Enter the Rod length: ";
    cin >> rod_Length;

    vector<int> prices(rod_Length+1,0);
    cout << "Enter the prices for lengths 1 to " << rod_Length << ": ";
    for (int i = 1; i <= rod_Length; i++) {
        cin >> prices[i];
    }

    int Max_profit = db.rodCutting(prices, rod_Length);
    cout << "Maximum profit obtainable: " << Max_profit << endl;

    return 0;
}
