#include <iostream>
#include <vector>

using namespace std;

void sieveOfEratosthenes(int n) {
    if (n < 2) {
        cout << "No prime numbers exist in this range." << endl;
        return;
    }

    vector<bool> prime(n + 1, true); // Mark all numbers as prime initially
    prime[0] = prime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]==true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false; // Mark multiples of p as non-prime
            }
        }
    }

    // Print primes
    cout << "Prime numbers up to " << n << ":\n";
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the upper limit to find prime numbers: ";
    cin >> n;
    sieveOfEratosthenes(n);
    return 0;
}




/*another solution*/

/*
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false; // 0 and 1 are not prime
    for (int i = 2; i < num; i++) { // Check divisibility
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

*/