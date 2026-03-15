#include <iostream>
using namespace std;

long long extended_gcd(long long a, long long b, long long& x, long long& y) {

    if (b == 0) 
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main() {
    long long a = 30, b = 20;
    long long x, y;

    long long g = extended_gcd(a, b, x, y);

    cout << "gcd = " << g << endl;
    cout << "x = " << x << " y = " << y << endl;
}














#pragma region SecoundWay
#include <iostream>
using namespace std;
//Asma
/*Extended Euclidean algorithm implementation  to find the mod inverse*/
void extendedEuclidean(int A, int B)
{


    int originalA = A, originalB = B;
    int T1 = 1, T2 = 0, T;

    while (B != 0) {
        int Q = A / B; // Quotient

        int R = A % B; // Remainder
        // Update A, B, T1, T2
        A = B;
        B = R;

        // Update T using the formula T = T1 - Q * T2
        T = T1 - Q * T2;

        // Update T1 and T2 for the next iteration
        T1 = T2;
        T2 = T;
    }


    if (A == 1) {
        // Modular inverse exists
        if (T1 < 0)
            T1 += originalB; // Make T1 positive
        cout << "Modular Inverse of " << originalA << " modulo " << originalB << " is: " << T1 << endl;
    }
    else {
        cout << "Modular Inverse does not exist." << endl;
    }
}

int main() {
    int A = 3;
    int B = 7;
    extendedEuclidean(A, B);

    return 0;
}
#pragma endregion
