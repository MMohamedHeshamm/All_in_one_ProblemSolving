#include <iostream>
#include <vector>
using namespace std;

class FactorialMemoization
{
public:
	long long  factorial(int n, vector<long long>& memo)

	{
		if (n == 0 || n == 1)
			return 1;

		if (memo[n] != -1)  // Check if the value is already computed
			return memo[n];

		memo[n] = n * factorial(n - 1, memo);
		return memo[n];
	}
};


/*int main()
{
	int n = 5;
	FactorialMemoization object;

	vector<long > memo(n + 1, -1);

	cout << "Factorial of " << n << " = "
		<<object.factorial(n, memo) << endl;

	return 0;
}*/

