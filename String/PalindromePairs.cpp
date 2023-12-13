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

bool isPalindrome(string s) {
	string rev = s;
	reverse(rev.begin(), rev.end());
	return rev==s;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
	int n = words.size();
	vector<vector<int>> res;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			string str = words[i]+words[j];
			if(isPalindrome(str) && i!=j) {
				res.push_back({i,j});
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	vector<string> words = {"abcd","dcba","lls","s","sssll"};
	for(auto x : palindromePairs(words)) {
		for(auto y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}
