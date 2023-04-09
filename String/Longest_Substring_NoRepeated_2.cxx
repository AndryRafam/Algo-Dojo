/*
Given a string s, find the length of the longest substring without repeating characters.

Time complexity: O(2*N) = O(N); where N is the lenght of the string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static int lengthOfLongestSubstring(string &s) {
		int start = 0;
		int end = 0;
		int max_length = 0;
		unordered_set<int> hashSet;
		
		while(end < s.length()){
			if(hashSet.find(s[end])==hashSet.end()){
				hashSet.insert(s[end]);
				max_length = max(max_length, end-start+1);
				end++;
			}
			else{
				hashSet.erase(s[start]);
				start++;
			}
		}
		return max_length;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	cout << Solution::lengthOfLongestSubstring(s) << "\n";
	return 0;
}
