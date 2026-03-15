#include <iostream>  
using namespace std; 

// Function to check if a point (x3, y3) lies on the line y = mx + c
void check_point(double m, double c, double x3, double y3) {
    double y_result = m * x3 + c; // Calculate the expected y-value on the line for x3

    // Compare the calculated y-value with the given y3
    if (y_result == y3) 
        cout << "The point is on the line"; 
    else if(y_result <y3)
        cout << "The point is below the line";
        else
        cout << "The point is above the line";

}

int main() {
    double m, c; // Variables to store the slope and y-intercept of the line

    // Prompt user to enter slope (m) and y-intercept (c)
    cout << "Enter m and c: ";
    cin >> m >> c; // Read values from user input

    double x3, y3; // Variables to store coordinates of the point to check

    // Prompt user to enter the point (x3, y3)
    cout << "Enter the point: ";
    cin >> x3 >> y3; // Read values from user input

    // Call function to check if the point lies on the line
    check_point(m, c, x3, y3);

    return 0; // Indicate successful program execution
}
