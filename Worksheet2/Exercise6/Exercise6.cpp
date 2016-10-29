#include <iostream>
#include <math.h>
#include <gsl/gsl_integration.h> 

double function(double x, void * params)
{
	return exp(-x)*sin(x);
}

int main()
{
	using namespace std;
	
	double a = 0;
	double b = 2;
	double epsabs, epsrel;
	double result, error;
	
	
	gsl_function gslFunction;
	gslFunction.function = &function;
	
	size_t N = 10000;
	
	gsl_integration_qng(&gslFunction, 0, 2, 0, 1E-7, &result, &error, &N);
	
	cout << "Estimate: " << result << endl
	     << "Error: " << error << endl
	     << "No. times function calls: " << N << endl;
	
	return 0;
}