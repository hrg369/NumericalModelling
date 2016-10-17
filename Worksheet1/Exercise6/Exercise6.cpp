#include <iostream>
#include <cmath>

double midpoint(double, double);
double func(double);
double bisection(double, double);
double uncertainty(double x1, double x2);

// Constants used in calculation of theta
double const m = 5.5;
double const l = 0.6;
double const k = 850;
double const g = 9.81;
double const pi = 3.141592653589793;
int count;

int main()
{
	// Problem logically suggests theta between 0 and pi/2
	double xBottom = 0;
	double xTop = pi/2;

	count = 0;
	std::cout << "\n";
	bisection(xBottom, xTop);
	return 0;
}

double midpoint(double x1, double x2)
{
	return (x1 + x2)/2;
}

double uncertainty(double x1, double x2)
{
	return (x2 - x1)/2;
}

// Function rearranged so that func(theta) = 0 for the correct value of theta
double func(double theta)
{
	return std::tan(theta) - std::sin(theta) - m*g/k/l;
}

/*
 * A recusive function for finding a root between two points
 * with the bisection method
 *
 * Parameters: the two values above and below the expected root
 *
 * Returns: the location of the root to an error of less than 0.001
 *
 * Currently the method finds the bisection on the public function func(double)
 * Also requires a global int count to keep track of the number of bisections.
 * The function prints the values of the number of bisections so far, the
 * current estimate of the root, and the uncertainty in the estimate.
 */
double bisection(double x1, double x2)
{
	// Find the midpoint of the two values
	double middle = midpoint(x1, x2);
	// Find the uncertainty of the current midpoint
	double error = uncertainty(x1, x2);
	// Doesn't print until bisection occurs
    if(count > 0)
    {
        std::cout << count << "\t" << middle << "\t" << error << "\n";
    }

    count++;

	// If the answer has been found to a desired accuracy, return the value.
	if(x2 - x1 < 0.001)
	{
		return midpoint(x1, x2);
	}
	// If f(xt)f(xm) < 0, replace xb with xm and bisect, else replace xt with xm and bisect
	return func(x2) * func(middle) < 0 ? bisection(middle, x2) : bisection(x1, middle);
}
