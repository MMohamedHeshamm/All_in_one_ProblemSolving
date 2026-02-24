#pragma region Question 1

#include <iostream>
#include <vector>
using namespace std;

class FibonacciMemoization
{

	long  fib(int n, vector<long >& memo)
	{
		if (n <= 1)
			return n;

		if (memo[n] != -1)   // already computed
			return memo[n];

		memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
		return memo[n];
	}

	/*int main()
	{
		int n = 5;
		vector<long> memo(n + 1, -1);

		cout << "Fibonacci of " << n << " = "
			<< fib(n, memo) << endl;

		return 0;
	}*/
};



#pragma endregion


//=========================================================
//=========================================================
//=========================================================
//=========================================================

#pragma region Question 4

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



#pragma region Main
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
#pragma endregion
    }



};


#pragma endregion

