#include <iostream>
#include <cmath>

double midpoint(double, double);
double func(double);
double bisection(double, double);

	double const m = 5.5;
    double const l = 0.6;
    double const k = 850;
    double const g = 9.81;
	double const pi = 3.141592653589793;

int main()
{
	double xBottom = 0;
	double xTop = pi/2;
	
	std::cout << bisection(xBottom, xTop);
	
	return 0;
}

double midpoint(double x1, double x2)
{
	return (x1 + x2)/2;
}  

double func(double theta)
{
	return std::tan(theta) - std::sin(theta) - m*g/k/l;
}

double bisection(double x1, double x2)
{
	std::cout << x1 << " " << x2 << "\n";	

	if(x2 - x1 < 0.000001)
	{
		return midpoint(x1, x2);
	}
	double middle = midpoint(x1, x2);
	
	if(func(x2)*func(middle)<0)
	{
		return bisection(middle, x2);
	}
	else
	{
		return bisection(x1, middle);
	}
}
