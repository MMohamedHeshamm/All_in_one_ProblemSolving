#include <iostream>

using namespace std;

// Function to determine the position of point P relative to line AB
int pointLinePosition(double x1, double y1, double x2, double y2, double x0, double y0) {
    // Vector AB
    double ABx = x2 - x1;
    double ABy = y2 - y1;

    // Vector AC
    double ACx = x0 - x1;
    double ACy = y0 - y1;

    // Cross product
    double crossProduct = ABx * ACy - ABy * ACx;

    // Determine position
    if (crossProduct > 0) {
        return 1; // Point is above the line
    }
    else if (crossProduct < 0) {
        return -1; // Point is below the line
    }
    else {
        return 0; // Point is on the line
    }
}



/*or use this func*/
void checkPoint_CrossProduct( double x1, double x2, double x3, double y1, double y2, double y3)
{

    double CrossResult = (x2 - x1) * (y3 - y1) - (x3 - x1)*(y2 - y1);
    if (CrossResult < 0)
        cout << "The point is below the line";
    else if(CrossResult > 0)
        cout << "The point is above the line";
    else
        cout << "The point is on the line";


}

int main() {
    double x1, y1, x2, y2, x0, y0;

    // Input for line points
    cout << "Enter coordinates of the first point of the line (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates of the second point of the line (x2 y2): ";
    cin >> x2 >> y2;

    // Input for the point to check
    cout << "Enter coordinates of the point P (x0 y0): ";
    cin >> x0 >> y0;

    int position = pointLinePosition(x1, y1, x2, y2, x0, y0);

    // Output result
    if (position == 1) {
        cout << "Point P is above the line AB.\n";
    }
    else if (position == -1) {
        cout << "Point P is below the line AB.\n";
    }
    else {
        cout << "Point P is on the line AB.\n";
    }

    return 0;
}

/*
It calculates two vectors:
Vector AB 
Vector AC
it computes their cross product

If crossProduct > 0 → Point P is above the line.
If crossProduct < 0 → Point P is below the line.
If crossProduct == 0 → Point P is on the line
*/



/*
example:
1-Point is Above the Line
Enter coordinates of the first point of the line (x1 y1): 0 0
Enter coordinates of the second point of the line (x2 y2): 4 4
Enter coordinates of the point P (x0 y0): 2 3


2-Point is Below the Line
Enter coordinates of the first point of the line (x1 y1): 1 1
Enter coordinates of the second point of the line (x2 y2): 5 5
Enter coordinates of the point P (x0 y0): 3 2


3-Point is On the Line
Enter coordinates of the first point of the line (x1 y1): 2 2
Enter coordinates of the second point of the line (x2 y2): 6 6
Enter coordinates of the point P (x0 y0): 4 4


*/