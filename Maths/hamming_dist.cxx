/* Hamming distance with two different approach:
 *
 * 1) Hard coding the algorithm
 * 2) Using bit optimization */

#include <bits/stdc++.h>
using namespace std;

// Hard coding

class Solution{
	public:
	static int hamming(string &s1, string &s2){
		int count = 0;
		for(auto i = 0; s1[i]&&s2[i]; i++){
			if(s1[i]!=s2[i])
				++count;
		}
		return count;
	}
};


// Bit optimization

class Answer{
	public:
	static int hamming(int a, int b){
		return __builtin_popcount(a^b);
	}
};
