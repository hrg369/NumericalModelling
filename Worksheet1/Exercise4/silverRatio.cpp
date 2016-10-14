#include <iostream>
#include <iomanip>
#include <cmath>

template<typename T>
T phirec(int);

double const phi = (-1.0 + sqrt(5.0)) / 2.0;

int main()
{
	using namespace std;
	cout.precision(20);
	cout << setiosflags(ios::fixed);
	int N = 1;	

	cout << "Please enter an exponent N: ";
	
	cin >> N;

	cout << "\n";

	cout << left << setw(4) << "N" << setw(20) << "phi^(N)";
	
	cout << "\n";

	double phiN;
	
	for(int i = 1; i <= N; i++)
	{
		phiN = phi;
		for(int j = 1; j < i; j++)
		{
			phiN *= phi;
		}

		cout << left << setw(4) << i << setw(20) << phiN;
		cout << "\n";	
	}

	cout << "\n";

	cout << "Reccuring with double\n";

        cout << left << setw(4) << "N" << setw(20) << "phi^(N)";

	cout << "\n";

	phiN = 0;

	for(int i = 1; i <= N; i++)
        {
                phiN = phirec<double>(i);

                cout << left << setw(4) << i << setw(20) << phiN;
                cout << "\n";
        }
	
	cout << "\n";

        cout << "Reccuring with float\n";

        cout << left << setw(4) << "N" << setw(20) << "phi^(N)";

        cout << "\n";

        phiN = 0;

        for(int i = 1; i <= N; i++)
        {
                phiN = phirec<float>(i);

                cout << left << setw(4) << i << setw(20) << phiN;
                cout << "\n";
        }

		
	return 0;
	
}

template<typename T>
T phirec(int N)
{
	T phi0 = 1;
	T phi1 = phi;
	
	if(N == 0)
	{
		return phi0;
	}
	
	if(N == 1)
	{
		return phi1;
	}

	return phirec<T>(N-2) - phirec<T>(N-1);
}
