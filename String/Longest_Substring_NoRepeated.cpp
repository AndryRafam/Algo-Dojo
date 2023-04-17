/*
Given a string s, find the length of the longest substring without repeating characters.

Let N, the length of the input string.

Solution 1: Brute force approach - Time complexity: O(N³).

Solution 2: Sliding window approach - Time complexity: O(N). 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_1{
	public:
	static int lengthOfLongestSubstrNoRepeat(string &s){
		int max = 0;
		int l = 1;
		while(l < s.length()){
			for(int i(0); i <= s.length()-l; ++i){
				string temp = s.substr(i,l);
				if(isUnique(temp)){
					max = temp.length();
				}
			}
			l++;
		}
		return max;
	}
	private:
	static bool isUnique(string &a){
		unordered_set<char> hash;
		for(auto &x : a){
			hash.insert(x);
		}
		if(hash.size()==a.length()){
			return true;
		}
		return false;
	}
};

class Solution_2{
	public:
	static int lengthOfLongestSubstrNoRepeat(string &s){
		unordered_set<char> hashSet;
		int l,r,max_len = 0;
		while(r < s.size()){
			if(hashSet.find(s[r])==hashSet.end()){
				hashSet.insert(s[r]);
				max_len = max(max_len,r-l+1);
				r++;
			}
			else{
				hashSet.erase(s[l]);
				l++;
			}
		}
		return max_len;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	string s = "abcabcbb";
	cout << Solution_2::lengthOfLongestSubstrNoRepeat(s) << endl;
	return 0;
}
