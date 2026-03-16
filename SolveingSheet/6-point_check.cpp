#include <iostream>  
using namespace std; 

// Function to check if a point (x3, y3) lies on the line y = mx + c
void check_point(double m, double c, double x3, double y3) {
    
    
    // Calculate the expected y-value on the line for x3
    double y_result = m * x3 + c;

    // Compare the calculated y-value with the given y3
    if (y_result == y3)
        cout << "The point is on the line";
    else if (y3 > y_result)
        cout << "The point is above the line";
    else
        cout << "The point is below the line";

}

int main() {
    
    // Variables to store the slope and y-intercept of the line
    double m, c;

    // Prompt user to enter slope (m) and y-intercept (c)
    cout << "Enter m and c: ";


    // Read values from user input
    cin >> m >> c; 

    // Variables to store coordinates of the point to check
    double x3, y3;

    // Prompt user to enter the point (x3, y3)
    cout << "Enter the point: ";


    // Read values from user input
    cin >> x3 >> y3; 

    // Call function to check if the point lies on the line
    check_point(m, c, x3, y3);

    // Indicate successful program execution
    return 0; 


}
