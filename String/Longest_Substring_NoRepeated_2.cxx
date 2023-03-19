/*Longest palindromic substring.

Given a string s, return the longest palindromic substring in s.

We are gonna solve this problem by expanding around the center of the string.

Time complexity: O(N²), where N is the length of the string.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static string longestPalindrome(string s) {
		if(s.size()==0) {
			return "";
		}
		int start = 0;
		int end = 0;
		for(auto i(0); i < s.length(); ++i) {
			// String can be odd (length) or even (length). Consider both case.
			int len = max(expandAroundCenter(s,i,i), expandAroundCenter(s,i,i+1));
			if(len > end-start) {
				start = i - (len-1)/2;
				end = i+len/2;
			}
		}
		return s.substr(start,end-start+1);
	}
	private:
	static int expandAroundCenter(string s, int left, int right) {
		while(left >= 0 && right < s.length() && s[left]==s[right]) {
			left--;
			right++;
		}
		return right-left-1;
	}
};

int main() {
	string s;
	cin >> s;
	cout << Solution::longestPalindrome(s);
	return 0;
}
