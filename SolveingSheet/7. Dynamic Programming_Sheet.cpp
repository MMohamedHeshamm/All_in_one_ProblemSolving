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



#pragma endregion

