#include <iostream>
#include <cmath> // For pow()

using namespace std;

void findCircleEquation(double h, double k, double r) {
    cout << "Equation of the circle: (x - " << h << ")^2 + (y - " << k << ")^2 = " << pow(r, 2) << endl;
}

int main() {
    double h, k, r;

    // Input center and radius
    cout << "Enter the center of the circle (h k): ";
    cin >> h >> k;
    cout << "Enter the radius (r): ";
    cin >> r;

    findCircleEquation(h, k, r);

    return 0;
}
