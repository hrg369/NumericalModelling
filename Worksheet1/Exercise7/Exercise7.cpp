#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

double function(double);
double functionGradient(double);
double midpoint(double, double);
double bisection(double, double, ofstream&);
double newton(double, ofstream&);

int main()
{
	// Creation of filestreams
    ofstream foutB1, foutB2, foutN1, foutN2;
    foutB1.open("bisection1.txt");
    foutB2.open("bisection2.txt");
    foutN1.open("newton1.txt");
    foutN2.open("newton2.txt");

	// Nearby Bisection
    cout << "Performing first bisection method.\n";
    bisection(-8, -7.8, foutB1);
	// Wide Range Bisection
    cout << "Performing second bisection method.\n";
    bisection(-10, 30, foutB2);
	// Nearby Newton's
    cout << "Performing first newton method.\n";
    newton(-7.8, foutN1);
	// Wide Range Newton's
    cout << "Performing second newton method.\n";
    newton(10, foutN2);
    cout << "Finished writing to files.\n";
	// Closing of filestreams
    foutB1.close();
    foutB2.close();
    foutN1.close();
    foutN2.close();
    cout << "Files closed.\n";
    return 0;
}

double function(double x)
{
    return x*x*x + 7*x*x - 6*x + 15;
}

//
double functionGradient(double x)
{
    return 3*x*x + 14*x - 6;
}

double midpoint(double x1, double x2)
{
    return (x1 + x2)/2;
}

/*
 * A recusive function for finding a root between two points
 * with the bisection method
 *
 * Parameters: the two values above and below the expected root
 *             a reference to the chosen output filestream
 *
 * Returns: the location of the root to an error of less than 0.001
 *
 * Function prints its estimates of the root each recursion, to the file
 */
double bisection(double x1, double x2, ofstream& fout)
{
    double middle = midpoint(x1, x2);

    fout << middle << "\n";

	// If the answer has been found to a desired accuracy, return the value.
    if(x2 - x1 < 0.001)
    {
        return middle;
    }

	// If f(xt)f(xm) < 0, replace xb with xm and bisect, else replace xt with xm and bisect
    if(function(x2)*function(middle)<0)
    {
        return bisection(middle, x2, fout);
    }
    else
    {
        return bisection(x1, middle, fout);
    }
}

/*
 * A recusive function for finding a root using the Newton-Raphson method
 *
 * Parameters: the initial guess of the root
 *             a reference to the chosen output filestream
 *
 * Returns: the location of the root to an error of less than 0.001
 *
 * Function prints its estimates of the root each recursion, to the file
 */
double newton(double x, ofstream& fout)
{
    fout << x << "\n";
    double funcOfX = function(x);

	// If the answer has been found to a desired accuracy, return the value.
    if(funcOfX < 0.0005 && funcOfX > -0.0005)
    {
        return x;
    }
	// x_n+1 = x_n - f(x)/f'(x)
    return newton(x - funcOfX/functionGradient(x), fout);
}
