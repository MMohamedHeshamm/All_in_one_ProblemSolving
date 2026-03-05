#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    return a.first > b.first;   // ترتيب تنازلي
}

double fractionalKnapsack(int W, vector<int>& weights, vector<int>& profit) {

    double maxProfit = 0;

    vector<pair<double, int>> units(weights.size());

    //Divide
    for (int i = 0; i < weights.size(); i++) {
        units[i].first = (double)profit[i] / weights[i];
        units[i].second = weights[i];
    }

    // استخدام دالة المقارنة
    //Sort
    sort(units.begin(), units.end(), compare);

    //Take
    for (int i = 0; i < weights.size(); i++) {

        if (W >= units[i].second) {
            maxProfit += units[i].first * units[i].second;
            W -= units[i].second;
        }
        else {
            maxProfit += units[i].first * W;
            break;
        }
    }

    return maxProfit;
}

int main() {

    vector<int> weights = { 10,20,30 };
    vector<int> profit = { 60,100,120 };
    int W = 50;

    double result = fractionalKnapsack(W, weights, profit);

    cout << "Maximum Profit = " << result << endl;
    
    return 0;
}