/*Program which perform a swapping character. Here how it works:
- Check if the first character (or the second) are vowels using an interpolation search algorithm.
- If the first character is a vowel and the second is not a vowel; or the first character is not a vowel and the second is a vowel, perform a swap. Otherwise, don't do anything.

Examples: Hello will be (after performing the swap) -> eHllo. 
              Elise will be (after performing the swap) -> lEsie.*/

#include <bits/stdc++.h>
using namespace std;

// Interpolation search algorithm implementation.
template <class T>
bool interpolation_search (const T arr[], int arrSize, const T& key) {
	int lo = 0, mid, hi = arrSize;
	while (lo <= hi) {
		mid = lo +((hi-lo) / (arr[hi]-arr[lo])) * (key-arr[lo]);
		if (arr[mid] == key)
			return true;
		else if (arr[mid] < key)
			lo = mid + 1;
		else if (arr[mid] > key)
			hi = mid - 1;
		else return true;
	}
	return false;
}

// Swap one character and his neighbour. 
char *swap_function (char *plaintext) {
	char *result = new char[strlen(plaintext)];
	assert (result != NULL);
	char table_vowels [] = {'A','E','I','O','U','Y','a','e','i','o','u','y'};	
	int size = sizeof(table_vowels) / sizeof(table_vowels[0]);
	
	// We have to distinguish two case. Length of plaintext is either even or odd.
	// First case, plaintext length is even.
	if (strlen(plaintext) % 2 == 0) {
		for (int i = 0; i < strlen(plaintext); i += 2) { 
			if (!(interpolation_search(table_vowels,size,plaintext[i])) && (interpolation_search(table_vowels,size,plaintext[i+1]))) { // If the first character is a vowel and the second is not a vowel, perform a swap.
				swap (plaintext[i],plaintext[i+1]);
				result[i] = plaintext[i];
				result[i+1] = plaintext[i+1];
			}
			else if ((interpolation_search(table_vowels,size,plaintext[i])) && (!(interpolation_search(table_vowels,size,plaintext[i+1])))) { // If the first character is not a vowel and the second is a vowel, perform a swap.
				swap (plaintext[i],plaintext[i+1]);
				result[i] = plaintext[i];
				result[i+1] = plaintext[i+1];
			}
			else { // If the first and the second character are the same (either a vowel, consonant are anything else) do not perform a swap. 
				result[i] = plaintext[i];
				result[i+1] = plaintext[i+1];
			}
		}
	}
	// Second case, plaintext length is odd.
	else {
		for (int i = 0; i < strlen(plaintext) - 1; i += 2) {
			if (!(interpolation_search(table_vowels,size,plaintext[i])) && (interpolation_search(table_vowels,size,plaintext[i+1]))) {
				swap (plaintext[i],plaintext[i+1]);
				result[i] = plaintext[i];
				result[i+1] = plaintext[i+1];
			}
			else if ((interpolation_search(table_vowels,size,plaintext[i])) && (!(interpolation_search(table_vowels,size,plaintext[i+1])))) {
				swap (plaintext[i],plaintext[i+1]);
				result[i] = plaintext[i];
				result[i+1] = plaintext[i+1];
			}
			else {
				result[i] = plaintext[i];
				result[i+1] = plaintext[i+1];
			}
		}
		result[strlen(plaintext)-1] = plaintext[strlen(plaintext)-1];
	}	
	return result;
	delete [ ] result;
}

// Main program
int main (int argc, char *argv[]) {
	if (argc < 2) {
		cout << "Usage: " << argv[0] << " <input>" << endl;
		return -1;
	}
	cout << swap_function(argv[1]) << endl;
	return 0;
}


	
