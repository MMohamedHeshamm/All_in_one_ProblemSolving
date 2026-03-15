#include <iostream>

using namespace std;

void LineEquation(double x1, double y1, double x2, double y2)
{
	// Y = mX + c
	double m = (y2 - y1) / (x2 - x1); //slope
	double c = y1 - m * x1; //constant

	cout << "y = " << m << "x + " << c << endl;
}

int main()
{
	double x1, x2, y1, y2;
	cout << "Enter the first point (x1,y1):";
	cin >> x1 >> y1;
	cout << "Enter the second point (x2,y2):";
	cin >> x2 >> y2;
	if (x1 == x2)
	{
		cout << "This is a vertical line with equation : x= " << x1;
	}
	else if (y1 == y2)
	{
		cout << "This is a horizontal line with equation : y= " << y1;

	}
	else 
	{
		LineEquation(x1, y1, x2, y2);
	}

	
}

