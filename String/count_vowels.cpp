/*Program which count the number of vowels in a string using an interpolation search algorithm.*/

#include <bits/stdc++.h>
using namespace std;

// Interpolation search algorithm
template <class T>
bool interpolation_search (const T arr[], int arrSize, const T& key) {
	int lo = 0, mid, hi = arrSize;
	while (lo <= hi) {		
		mid = lo + ((hi-lo) / (arr[hi]-arr[lo])) * (key-arr[lo]);
		if (arr[mid] == key)
			return true;
		else if (key < arr[mid])
			hi = mid-1;
		else if (arr[mid] < key)
			lo = mid+1;
		else return true;
	}
	return false;
}

// Main program
int main (int argc, char **argv) {
	if (argc < 2) {
		cout <<"Usage: " << argv[0] << " <input>" << endl;
		return -1;
	}
	int tab_vowels[] = {65,69,73,79,85,89,97,101,105,111,117,121}; // ASCII values of the vowels. 
	int size = sizeof(tab_vowels) / sizeof(tab_vowels[0]);
	int count = 0;
	
	for (int i = 0; i < strlen(argv[1]); i++) {
		if (interpolation_search(tab_vowels, size, int(argv[1][i])))
			count += 1;
	}
	cout << "The number of vowels are: " << count << endl;
	return 0;
}


