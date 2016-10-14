#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double function(double);
double functionGradient(double);
double midpoint(double, double);
double bisection(double, double, ofstream&);
double uncertainty(double, double);
double newton(double, ofstream&);

int main()
{
    ofstream foutB, foutN1, foutN2;
    foutB.open("bisection.csv");
    foutN1.open("newton1.csv");
    foutN2.open("newton2.csv");

    cout << "Performing bisection method.\n";
    bisection(-10, 10, foutB);
    cout << "Performing first newton method.\n";
    newton(-20, foutN1);
    cout << "Performing second newton method.\n";
    newton(0, foutN2);
    cout << "Finished writing to files.\n";

    foutB.close();
    foutN1.close();
    foutN2.close();
    cout << "Files closed.\n";
    return 0;
}

double function(double x)
{
    return x*x*x + 7*x*x - 6*x + 15;
}

double functionGradient(double x)
{
    return 3*x*x + 14*x - 6;
}

double midpoint(double x1, double x2)
{
    return (x1 + x2)/2;
}

double uncertainty(double x1, double x2)
{
	return (x1 - x2)/2;
}

double bisection(double x1, double x2, ofstream& fout)
{
    double middle = midpoint(x1, x2);
	double error = uncertainty(x2, x1);

    fout << middle << "," << error << "\n";

    if(x2 - x1 < 0.001)
    {
        return middle;
    }

    if(function(x2)*function(middle)<0)
    {
        return bisection(middle, x2, fout);
    }
    else
    {
        return bisection(x1, middle, fout);
    }
}

double newton(double x, ofstream& fout)
{
    fout << x << "\n";
    double funcOfX = function(x);
    if(funcOfX < 0.001 && funcOfX > -0.001)
    {
        return x;
    }

    return newton(x - funcOfX/functionGradient(x), fout);
}
