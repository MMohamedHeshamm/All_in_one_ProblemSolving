#include <complex>  // Include the complex number library
#include <iostream> // Include the input-output stream library

using namespace std; // Use the standard namespace

int main()
{
    // Define the first complex number n1 = 3 + 2i
    complex<double> n1(3.0, 2.0);

    // Define the second complex number n2 = 1 + 5i
    complex<double> n2(1.0, 5.0);

    // Addition of two complex numbers:
    complex<double> add_res = n1 + n2;

    // Subtraction of two complex numbers:
    complex<double> sub_res = n1 - n2;

    // Multiplication of two complex numbers:
    complex<double> multi_res = n1 * n2;

    // Division of two complex numbers:
    // (3 + 2i) / (1 + 5i)
    complex<double> div_res = n1 / n2;

    // Output results
    cout << "Addition: " << add_res << endl;      // Expected: (4,7)
    cout << "Subtraction: " << sub_res << endl;   // Expected: (2,-3)
    cout << "Multiplication: " << multi_res << endl; // Expected: (-7,17)
    cout << "Division: " << div_res << endl;      // Computed below

    return 0; // Indicate successful execution
}