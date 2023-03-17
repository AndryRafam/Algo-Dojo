/*
Codeforces problem 1800F.

Time complexity: O(N²k), where N is the size the number of strings and k in the length of the longest string. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static bool is_nightmare(string a, string b) {
		string t = a + b;
		if(!(t.length()&1)) {
			return false;
		}
		unordered_set<char> occur;
		for(auto x : t) {
			occur.insert(x);
		}
		if(occur.size()!=25) {
			return false;
		}
		unordered_map<char,int> freq;
		for(auto c : t) {
			freq[c]++;
		}
		for(auto x : freq) {
			if(!(x.second&1)) {
				return false;
			}
		}
		return true;
	}
	static int count_pairs(vector<string> words) {
		int count = 0;
		for(auto i(0); i < words.size()-1; ++i) {
			for(auto j(i+1); j < words.size(); ++j) {
				if(is_nightmare(words[i],words[j])) {
					count ++;
				}
			}
		}
		return count;
	}
};

int main(int argc, char **argv) {
	int n;
	cin >> n;
	vector<string> arr;
	string s;

	for(auto i(0); i < n; ++i) {
		cin >> s;
		arr.emplace_back(s);
	}
	cout << "\n" << Solution::count_pairs(arr);
	return 0;
}
		
