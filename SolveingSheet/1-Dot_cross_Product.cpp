#include <iostream>
#include <vector>

using namespace std;

// Function to compute dot product of two 2D vectors
double dotProduct( vector<double> a,  vector<double> b) {
    return a[0] * b[0] + a[1] * b[1];
}

// Function to compute cross product of two 2D vectors (returns scalar value)
double crossProduct_2D( vector<double> a,  vector<double> b) {
    return a[0] * b[1] - a[1] * b[0];
}



// Function to compute cross product of two 3D vectors (returns a 3D vector)
vector<double> crossProduct_3D( vector<double> a,  vector<double> b) {
    return {
        a[1] * b[2] - a[2] * b[1],  // x-component
        a[2] * b[0] - a[0] * b[2],  // y-component
        a[0] * b[1] - a[1] * b[0]   // z-component
    };
}

int main() {
    vector<double> v1(2), v2(2);
    
    cout << "Enter the first vector (x y): ";
    cin >> v1[0] >> v1[1];
    
    cout << "Enter the second vector (x y): ";
    cin >> v2[0] >> v2[1];
    
    // Compute dot product
    double dot = dotProduct(v1, v2);
    cout << "Dot product: " << dot << endl;
    
    // Compute cross product (scalar value)
    double cross = crossProduct_2D(v1, v2);
    cout << "Cross product: " << cross << endl;


/******************* FOR  Vectors in 3D ******************/
    vector<double> A(3), B(3);

    // Input vector A
    cout << "Enter vector A (Ax Ay Az): ";
    cin >> A[0] >> A[1] >> A[2];

    // Input vector B
    cout << "Enter vector B (Bx By Bz): ";
    cin >> B[0] >> B[1] >> B[2];

    // Compute cross product
    vector<double> C = crossProduct_3D(A, B);

    // Output result
    cout << "Cross Product (A × B): (" << C[0] << ", " << C[1] << ", " << C[2] << ")" << endl;
    
    return 0;
}
