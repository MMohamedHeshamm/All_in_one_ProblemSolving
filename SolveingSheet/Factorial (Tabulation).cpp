#include <iostream>
#include <vector>
using namespace std;

class FactorialTabulation
{
public:
    long long factorial(int n)
    {
		// memo[i] will store the factorial of i
        vector<long long> memo(n + 1, 1);

		//iteratively fill the memoization table from 2 to n
		// since factorial of 0 and 1 is 1, we can start filling from 2
        for (int i = 2; i <= n; i++)
        {
            memo[i] = memo[i - 1] * i;
        }

        return memo[n];
    }
};

/*int main()
{
    int n = 5;
    FactorialTabulation object;

    cout << "Factorial of " << n << " = "
         << object.factorial(n) << endl;

    return 0;
}*/