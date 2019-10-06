#include <bits/stdc++.h>
using namespace std;

int main()
{
	int key; // Number of vaccines
	cin >> key;	
	int *vaccines = new (nothrow) int[key];
	int *patients = new (nothrow) int[key];	
	
	for (int i = 0; i < key; i++)
	{
		int element;
		cin >> element;		
		vaccines[i] = element;			
	}

	for (int k = 0; k < key; k++)
	{
		int fill;
		cin >> fill;
		patients[k] = fill;
	}

	sort (vaccines,vaccines+key);
	sort (patients,patients+key);

	// Start the comparaison

	if (vaccines[0] <= patients[0] || vaccines[key-1] <= patients[key-1])
	{
		cout << "No" << endl;
		return EXIT_SUCCESS;
	}
	else
	{
		for (int j = 1; j < key-1; j++) {
			for (int i = 1; i < key-1; i++) {
				if (vaccines[j] <= patients[i])
				{
					cout << "No" << endl;
					return EXIT_SUCCESS;
				}
				else
					continue;
			}
		}
	}
	cout << "Yes" << endl;
	return EXIT_SUCCESS;
}
