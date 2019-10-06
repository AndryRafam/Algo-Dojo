/* Andry Rafam Andrianjafy - Pig Latin game, September 2018 */

#include <bits/stdc++.h>
using namespace std;

// Binary search algorithm use to find if the first letter is a vowel or a consonant
template <class T>
bool binarySearch (const T arr[ ], int arrSize, const T& element) {
	int lo = 0, mid, hi = arrSize-1;
	while (lo <= hi) {
		mid = (lo+hi)/2;
		if (element < arr[mid])
			hi = mid-1;
		else if (arr[mid] < element)
			lo = mid+1;
		else return true;
	}
	return false;
}

// Pig Latin function
string PigLatin (string word) {
	string pig_latin_word = "";
	int len = word.length();
	int begin_word = int(word[0]);
	swap(word[0],word[len]);

	for (int i = 0; i < len; i++)
		pig_latin_word += word[i];
	
	pig_latin_word = pig_latin_word + char(begin_word) + "ay"; 
	
	return pig_latin_word;
}

// Main program
int main (int argc, char **argv) {
	if (argc < 2) {
		cout <<"Usage: " << argv[0] << " <input>" << endl;
		return -1;
	}
	int tab_consonant[ ] = {66,67,68,70,71,72,74,75,76,77,78,80,81,82,83,84,86,87,88,90,98,99,100,102,103,104,106,107,108,109,110,112,113,114,115,116,118,119,120,122}; // ASCII value of the consonant	
	int size = sizeof(tab_consonant) / sizeof(tab_consonant[0]);
	
	if (binarySearch(tab_consonant,size,int(argv[1][0]))) // Use of binary search algorithm to find if the first letter is a consonant 
		cout <<"Pig latin of " << argv[1] << " is >> " << PigLatin(argv[1]) << endl;
	else
		return -1;
	
	return 0;
}

	
