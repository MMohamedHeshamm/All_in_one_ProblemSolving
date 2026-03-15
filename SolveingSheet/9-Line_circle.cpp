#include <iostream>
#include <cmath>

using namespace std;

void findCircleLineIntersection(double h, double k, double r, double m, double c) {
    // Quadratic equation coefficients
    double A = 1 + m * m;
    double B = 2 * m * (c - k) - 2 * h;
    double C = h * h + (c - k) * (c - k) - r * r;

    // Compute the discriminant
    double D = B * B - 4 * A * C;

    // Check number of intersection points
    if (D < 0) {
        cout << "No intersection points (the line does not touch the circle)." << endl;
    } else if (D == 0) {
        double x = -B / (2 * A);
        double y = m * x + c;
        cout << "One intersection point: (" << x << ", " << y << ")" << endl;
    } else {
        double sqrtD = sqrt(D);
        double x1 = (-B + sqrtD) / (2 * A);
        double x2 = (-B - sqrtD) / (2 * A);
        double y1 = m * x1 + c;
        double y2 = m * x2 + c;

        cout << "Two intersection points: (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")" << endl;
    }
}

int main() {
    double h, k, r, m, c;

    // Input for the circle
    cout << "Enter the center of the circle (h k): ";
    cin >> h >> k;
    cout << "Enter the radius (r): ";
    cin >> r;

    // Input for the line
    cout << "Enter the slope (m) and y-intercept (c) of the line: ";
    cin >> m >> c;

    // Find intersections
    findCircleLineIntersection(h, k, r, m, c);

    return 0;
}
