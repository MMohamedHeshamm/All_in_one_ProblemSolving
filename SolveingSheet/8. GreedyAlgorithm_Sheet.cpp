#pragma region Question 1
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool compare(pair<double, int> a, pair<double, int> b) {
//    return a.first > b.first;   // ترتيب تنازلي
//}
//
//double fractionalKnapsack(int W, vector<int>& weights, vector<int>& profit) {
//
//    double maxProfit = 0;
//
//    vector<pair<double, int>> units(weights.size());
//
//    //Divide
//    for (int i = 0; i < weights.size(); i++) {
//        units[i].first = (double)profit[i] / weights[i];
//        units[i].second = weights[i];
//    }
//
//    // استخدام دالة المقارنة
//    //Sort
//    sort(units.begin(), units.end(), compare);
//
//    //Take
//    for (int i = 0; i < weights.size(); i++) {
//
//        if (W >= units[i].second) {
//            maxProfit += units[i].first * units[i].second;
//            W -= units[i].second;
//        }
//        else {
//            maxProfit += units[i].first * W;
//            break;
//        }
//    }
//
//    return maxProfit;
//}
//
//int main() {
//
//    vector<int> weights = { 10,20,30 };
//    vector<int> profit = { 60,100,120 };
//    int W = 50;
//
//    double result = fractionalKnapsack(W, weights, profit);
//
//    cout << "Maximum Profit = " << result << endl;
//
//    return 0;
//}
#pragma endregion



#pragma region Question 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Q2 {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
		int n = startTime.size(); // number of jobs

        // jobs[i] = {start, end, profit}
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) 
        {
            jobs.push_back({ startTime[i], endTime[i], profit[i] });
        }

        // sort by start time
        sort(jobs.begin(), jobs.end(),0);

        // extract all start times
        vector<int> starts;
        for (int i = 0; i < n; i++) {
			starts.push_back(jobs[i][0]); // start time of job i is stored in starts[i]
            
        }

        // dp[i] = max profit from job i to end
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int nextIndex = lower_bound(starts.begin(), starts.end(), jobs[i][1]) - starts.begin();

            int take = jobs[i][2] + dp[nextIndex];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};

int main() 
{
    vector<int> startTime = { 1, 2, 3, 3 };
    vector<int> endTime = { 3, 4, 5, 6 };
    vector<int> profit = { 50, 10, 40, 70 };

    Q2 obj;
    int ans = obj.jobScheduling( startTime, endTime, profit);

    cout << "Maximum Profit = " << ans << endl;

    return 0;
}
#pragma endregion
