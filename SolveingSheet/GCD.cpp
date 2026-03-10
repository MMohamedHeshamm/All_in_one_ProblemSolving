#include <iostream>
using namespace std;

// Recursive GCD using Euclidean Algorithm
int gcd_recursive(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return gcd_recursive(b, a % b);
}

// Iterative GCD using Euclidean Algorithm
int gcd_iterative(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


//int main() {
//    int a, b;
//
//    cout << "Enter two numbers: ";
//    cin >> a >> b;
//
//    // Ensure a is the greater number
//    if (b > a) {
//        swap(a, b);
//    }
//    // Calling both functions and displaying results
//    cout << "Recursive GCD: " << gcd_recursive(a, b) << endl;
//    cout << "Iterative GCD: " << gcd_iterative(a, b) << endl;
//
//    return 0;
//}