#include <iostream>
#include <iomanip>

double function(double x)
{
	return 1/((1+x)*(1+x));
}

double trapezium(double intervalBottom, double intervalTop, int numberOfIntervals)
{
	double h = (intervalTop - intervalBottom) / numberOfIntervals;

	double sum = 0;

	for(int i = 0; i < numberOfIntervals; i++)
	{
		sum += 0.5 * h * (function(i*h) + function((i+1)*h));
	}



	return sum;
}

int main()
{
	using namespace std;

	cout << left << setw(15) << "No. Intervals" << setw(15) << "Estimate" << "Error\n";

	for(int i = 1; i < 20; i++)
	{
		double estimate = trapezium(0, 1, i);
		double error = estimate - 0.5;
		cout << setw(15) << i << setw(15) << estimate << error << "\n";
	}

	return 0;
}