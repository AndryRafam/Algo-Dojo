/*
You are given an array of strings which consist of only small letters of the alphabet. 
Your task is to find how many palindrome pairs are there in the array. A palindrome pair is a pair of strings 
such that the following condition holds: at least one permutation of the concatenation of the two strings is a palindrome. 
In other words, if you have two strings, let's say "aab" and "abcac", and you concatenate them into "aababcac", 
we have to check if there exists a permutation of this new string such that it is a palindrome 
(in this case there exists the permutation "aabccbaa").

Two pairs are considered different if the strings are located on different indices. The pair of strings with indices (i,j)
is considered the same as the pair (j,i).

Brute force approach: O(N²*k), where N in the size of the input array and k is the length of the longest string in the array.
*/

#include <bits/stdc++.h>
using namespace std;

bool pair_pal(string s) {
	unordered_map<char,int> hash;
	for(auto x : s) {
		hash[x]++;
	}
	int odd_ct = 0;
	for(auto y : hash) {
		if(y.second&1)
			odd_ct++;
	}
	return (odd_ct <= 1) ? true:false; /*if there is more than one extra character in the string
										  the string cannot be a permutation palindrome*/
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	int count = 0;
	int n;
	string s;
	cin >> n;
	vector<string> arr;

	for(auto i(0); i < n; ++i) {
		cin >> s;
		arr.emplace_back(s);
	}
	for(auto i(0); i < arr.size()-1; ++i) {
		for(auto j(i+1); j <= arr.size()-1; ++j) {
			if(pair_pal(arr[i]+arr[j])) {
				count++;
			}
		}
	}
	cout << count << "\n";
	return 0;
}
