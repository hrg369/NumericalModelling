#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

template<typename T>
T phirec(int);

// Silver Ratio
double const phi = (-1 + sqrt(5)) / 2;

int main()
{
	using namespace std;

    int n = 0;
    int maxSuggestedExponent = 40;
    double phiN;

	ofstream fout;
	fout.open("silverRatio.txt");

    // An acceptable precision for double as investigated in previous exercises
	cout.precision(13);
	cout.flags(ios::scientific);

	cout << "Please enter an exponent N (Suggested Max = 40): ";
	cin >> n;
	cout << "\n";

    // Warns the user of slowdown when running for N>40
    if(n > maxSuggestedExponent)
    {
        char choice;
        cout << n << " is above the suggested maximum. This computation may take some time."
                  << "\nAre you sure you want to continue? (y/n)";
        cin >> choice;

        if(choice == 'y')
        {
            cout << "\nPerforming calculations with n = " << n << ".\n";
        } else
        {
            cout << "Program terminating, please restart with a more appropriate max exponent.";
            return 0;
        }
    }

    cout << "Output for direct multiplication will be saved to \"silverRatio.txt\"\n\n";

	cout << left << setw(5) << "N" << setw(20) << "phi^(N)";
    cout << "\n";

	fout << "N\t" << "Phi^(N)\n";

    // Phi^(N) by direct multiplication
	for(int i = 1; i <= n; i++)
	{
        // loop starts at 1, where phi^(1) = phi
		phiN = phi;
		for(int j = 1; j < i; j++)
		{
			phiN *= phi;
		}

		cout << left << setw(4) << i  << right << setw(20) << phiN;
		fout << i << "\t" << phiN << "\n";
		cout << "\n";	
	}
	
	fout.close();
	
	cout << "\n";
	cout << "Reccuring with double\n";
	cout << left << setw(5) << "N" << setw(20) << "phi^(N)";
	cout << "\n";

    // Phi^(N) by recursion with double variables
	for(int i = 1; i <= n; i++)
    {
            phiN = phirec<double>(i);

            cout << left << setw(4) << i << right << setw(20) << phiN;
            cout << "\n";
    }
	
	cout << "\n";
    cout << "Reccuring with float\n";
    cout << left << setw(5) << "N" << setw(20) << "phi^(N)";
    cout << "\n";

    // Phi^(N) by recursion with float variables
    for(int i = 1; i <= n; i++)
    {
            phiN = phirec<float>(i);

            cout << left << setw(4) << i << right << setw(20) << phiN;
            cout << "\n";
    }

	return 0;
}

/*
 * A recusive function for finding the silver ratio to the Nth power.
 *
 * Parameter: the power of the silver ratio to be found
 *
 * Returns: the silver ratio to the required exponent, either by recursion
 * or refering to a base case
 *
 * The function is a template so it can be used for any numerical primitive
 */
template<typename T>
T phirec(int n)
{
    // The base cases of phi^0 and phi^1 for when the recursion bottoms out
	T phi0 = 1;
	T phi1 = phi;
	if(n == 0)
    {
        return phi0;
    }
	if(n == 1)
	{
		return phi1;
	}

    // The recursive relation itself, phi^(N) = phi^(N-2) - phi^(N-1)
	return phirec<T>(n-2) - phirec<T>(n-1);
}
