#include <iostream> // Include input-output stream library
using namespace std;

// Function to find the intersection point of two lines y = m1*x + c1 and y = m2*x + c2
void findIntersection(double m1, double c1, double m2, double c2) {
    // Check if the lines are parallel
    if (m1 == m2) { 

        // If intercepts are also the same, the lines coincide
        if (c1 == c2) 
            cout << "The lines are the same (infinite intersections)." << endl;

        // If only slopes match, the lines are parallel and never meet
        else 
            cout << "The lines are parallel and do not intersect." << endl;

        return; // Exit the function
    }

    // Calculate intersection point using the formula x = (c2 - c1) / (m1 - m2)
    double x = (c2 - c1) / (m1 - m2);

    // Compute y-coordinate using the equation of the first line
    double y = m1 * x + c1; 

    // Display the intersection point
    cout << "The lines intersect at (" << x << ", " << y << ")" << endl;
}

int main() {
    double m1, c1, m2, c2;

    cout << "Enter slope and intercept for Line 1 (m1 c1): ";
    cin >> m1 >> c1;

    cout << "Enter slope and intercept for Line 2 (m2 c2): ";
    cin >> m2 >> c2;

    findIntersection(m1, c1, m2, c2);

    return 0; 
}
