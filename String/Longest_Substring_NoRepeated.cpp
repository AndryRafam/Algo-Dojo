/*
Given a string s, find the length of the longest substring without repeating characters.

Time complexity: O(N³), where N is the length of the string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static int lengthOfLongestSubstring(string &s) {
		int max = 0;
		int l = 1;
		while(l < s.length()) {
			for(int i(0); i <= s.length()-l; ++i) {
				string temp = s.substr(i,l);
				if(isUnique(temp)) {
					max = temp.length();
				}
			}
			l++;
		}
		return max;
	}
	private:
	static bool isUnique(string &a) {
		unordered_map<char,int> hash;
		for(auto &x : a) {
			hash[x]++;
		}
		if(hash.size()==a.length()) {
			return true;
		}
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	string s = "abcabcbb";
	cout << Solution::lengthOfLongestSubstring(s);
	return 0;
}
