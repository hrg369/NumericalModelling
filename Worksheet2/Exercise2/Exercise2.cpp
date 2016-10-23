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

	ofstream fout;
	fout.open("Exercise2File.txt");

	cout.precision(14);
	fout.precision(14);

	cout << left << setw(15) << "No. Intervals" << setw(20) << "Estimate" << "Error\n";
	fout << left << setw(15) << "No. Intervals" << setw(20) << "Estimate" << "Error\n";


	for(int i = 0; i < 8; i++)
	{
		double estimate = trapezium(0, 2, pow(10,i));
		double error = estimate - 0.46662966259317557;
		cout << setw(15) << pow(10,i) << setw(20) << estimate << error << "\n";
		fout << setw(15) << pow(10,i) << setw(20) << estimate << error << "\n";
	}

	cout << "\n\n";

	cout << left << setw(15) << "No. Intervals" << setw(20) << "Estimate" << "Error\n";
	fout << left << setw(15) << "No. Intervals" << setw(20) << "Estimate" << "Error\n";

	for(int i = 0; i < 8; i++)
	{
		double estimate = simpson(0, 2, pow(10,i));
		double error = estimate - 0.46662966259317557;
		cout << setw(15) << pow(10,i) << setw(20) << estimate << error << "\n";
		fout << setw(15) << pow(10,i) << setw(20) << estimate << error << "\n";
	}



	fout.close();

	return 0;
}