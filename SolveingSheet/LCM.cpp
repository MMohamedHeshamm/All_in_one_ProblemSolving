/*
LCM(a,b)= ∣a×b∣/GCD(a,b)
​
*/


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


// Function to compute LCM using GCD
int lcm(int a, int b) 
{
    //  return (a / gcd_recursive(a, b)) * b;  // Prevents overflow

    return (a * b) / gcd_recursive(a, b);  // Prevents overflow

}

//int main() {
//    int a, b;
//
//    cout << "Enter two numbers: ";
//    cin >> a >> b;
//
//
//    // Ensure a is the greater number
//    if (b > a) {
//        swap(a, b);
//    }
//
//    // Calling functions and displaying results
//    cout << "Recursive GCD: " << gcd_recursive(a, b) << endl;
//    cout << "LCM: " << lcm(a, b) << endl;
//
//    return 0;
//}