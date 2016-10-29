#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

double function(double x)
{
	return exp(-x)*sin(x);
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

double simpson(double intervalBottom, double intervalTop, int numberOfIntervals)
{
	double h = (intervalTop - intervalBottom) / numberOfIntervals;

	double sum = 0;

	for(int i = 0; i < numberOfIntervals; i+=2)
	{
		sum += h/3 * (function(i*h) + 4*function((i+1)*h) + function((i+2)*h));
	}

	return sum;
}

int main()
{
	using namespace std;

	ofstream trapOut;
	ofstream simpsOut;
	trapOut.open("Exercise2Trapezium.csv");
	simpsOut.open("Exercise2Simpson.csv");

	cout.precision(15);
	trapOut.precision(15);
	simpsOut.precision(15);

	cout << "Producing relative error for Trapezium Rule\n";
	for(int i = 0; i < 9; i++)
	{
		double estimate = trapezium(0, 2, pow(10,i));
		double analytical = 0.46662966259317557;
		double error = abs(analytical - estimate)/analytical;
		trapOut << pow(10,i) << "," << error << "\n";
	}

	cout << "Finished, output saved to: Exercise2Trapezium.csv";

	cout << "\n\n";

	cout << "Producing relative error for Simpson's Rule\n";

	for(int i = 0; i < 9; i++)
	{
		double estimate = simpson(0, 2, pow(10,i));
		double analytical = 0.46662966259317557;
		double error = abs(analytical - estimate)/analytical;
		simpsOut << pow(10,i) << "," << error << "\n";
	}

	cout << "Finished, output saved to: Exercise2Simpson.csv";

	cout << "\n\n";

	int i = 0;
	double accuracy = pow(10, -8);
	while(true)
	{
		double estimate1 = simpson(0, 2, pow(10,i/2.0));
		double estimate2 = simpson(0, 2, pow(10,(i+1)/2.0));

		if(estimate2 - estimate1 < accuracy)
		{
			cout << setiosflags(ios::fixed) << setprecision(10) << estimate1;
			break;
		}
		i++;
	}


	trapOut.close();
	simpsOut.close();

	return 0;
}