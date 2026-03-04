#include <iostream>
#include <vector>
using namespace std;
//Memoization Approach – O(n x W) Time and Space

int kSackRec(int W, vector<int>& weight_Vector, vector<int>& profit,
    int index, vector<vector<int>>& memo) {

    // Base condition
    if (index < 0)
        return 0;

    if (memo[index][W] != -1)
        return memo[index][W];

    // if the weight of item > the capacity of the Bag we will skip it 
    if (weight_Vector[index] > W) {
        memo[index][W] = kSackRec(W, weight_Vector, profit, index - 1, memo);
    }
    else {
        //get the max between (take the item or leave it )
        memo[index][W] = max(profit[index] +
            kSackRec(W - weight_Vector[index], weight_Vector, profit, index - 1, memo),
            kSackRec(W, weight_Vector, profit, index - 1, memo));
    }

    return memo[index][W];
}

void printMemo(const vector<vector<int>>& memo) {
    cout << "\nMemoization Table:\n";
    for (const auto& row : memo) {
        for (int val : row) {
            if (val == -1)
                cout << " - ";  // Print "-" for unvisited cells
            else
                cout << val << " ";
        }
        cout << endl;
    }
}


int main() {
    //input
    vector<int> profit = { 60, 100, 120 };
    vector<int> weight_Vector = { 1, 3, 5 };
    int W = 5;
    int n = weight_Vector.size();
    vector<vector<int>> memo(n, vector<int>(W + 1, -1));

    cout << kSackRec(W, weight_Vector, profit, n - 1, memo) << endl;
    printMemo(memo);
    return 0;
}


//------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RodCutting {
public:
    // solving Rod cutting using Bottom-Up (Tabulatuion)
    int rodCutting(vector<int>& prices, int rodLength) {

        //create vector to store the profit called C
        vector<int> C(rodLength + 1, 0);

        // Fill the C table
        for (int i = 1; i <= rodLength; i++) {
            for (int k = 1; k <= i; k++) {

                C[i] = max(C[i], prices[k] + C[i - k]);
            }
        }

        return C[rodLength];
    }


    /*int main() {
        int rod_Length;
        RodCutting rc;

        cout << "Enter the Rod length: ";
        cin >> rod_Length;

        vector<int> prices(rod_Length + 1, 0);
        cout << "Enter the prices for lengths 1 to " << rod_Length << ": ";
        for (int i = 1; i <= rod_Length; i++) {
            cin >> prices[i];
        }

        int Max_profit = rc.rodCutting(prices, rod_Length);
        cout << "Maximum profit obtainable: " << Max_profit << endl;

        return 0;
    }*/


};