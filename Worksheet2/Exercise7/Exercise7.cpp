#include <iostream>
#include <math.h>
#include <gsl/gsl_integration.h> 

double function(double x, void * params)
{
	return x*sin(30*x)*cos(x);
}

int main()
{
	using namespace std;
	gsl_integration_workspace *workspace = gsl_integration_workspace_alloc(1E5);
	
	double a = 0;
	double b = 2;
	double epsabs, epsrel;
	double result, error;
	
	
	gsl_function gslFunction;
	gslFunction.function = &function;
	
	size_t N = 10000;
	
	int key = 6;
	
	double pi = 3.141592653589793;
	
	gsl_integration_qag(&gslFunction, 0, 2*pi, 0, 1E-7, N, key, workspace, &result, &error);
	
	cout << result << endl << error << endl << workspace->size;
	
	gsl_integration_workspace_free(workspace);
	
	return 0;
}