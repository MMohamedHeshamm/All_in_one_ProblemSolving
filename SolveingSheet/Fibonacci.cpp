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

class FibonacciTabulation {
    int fib(int n) {
        if (n <= 1) return n;

        vector<int> FibTabu(n + 1);
        FibTabu[0] = 0;
        FibTabu[1] = 1;

        for (int i = 2; i <= n; i++) {
            FibTabu[i] = FibTabu[i - 1] + FibTabu[i - 2];
        }
        return FibTabu[n];
    }

    /*int main()
    {
        int n = 5;

        cout << "Tabulation Fibonacci of " << n << " = "
            << fib(n) << endl;

        return 0;
    }*/
};