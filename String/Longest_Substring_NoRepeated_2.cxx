/*
Given a string s, find the length of the longest substring without repeating characters.

Time complexity: O(2*N) = O(N); where N is the lenght of the string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static int lengthOfLongestSubstring(string &s) {
		unordered_map<char,int> hash;
		int left = 0;
		int right = 0;
		int res = 0;
		
		while(right < s.length()) {
			hash[s[right]]++;
			
			while(hash[s[right]] > 1) {
				hash[s[left]]--;
				left++;
			}
			res = max(res,right-left+1);
			right++;
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	string s = "pwwkew";
	cout << Solution::lengthOfLongestSubstring(s);
	return 0;
}
