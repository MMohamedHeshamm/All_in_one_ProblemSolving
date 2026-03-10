#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void minCoins (vector<int>& coins, int amount) 
{
    sort(coins.rbegin(), coins.rend()); // Sort in descending order

    vector<int> result;

    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            result.push_back(coin);
        }
    }

    cout << "Coins used: ";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;
}

//int main() {
//    vector<int> coins = { 1, 5, 10, 25, 50 }; // Coin denominations
//    int amount = 68; // Target amount
//
//    minCoins(coins, amount);
//
//    return 0;
//};



