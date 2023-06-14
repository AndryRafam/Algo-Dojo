/*
Count number of distinct substring in a string; using hashing method.

Time complexity: O(n²), where n is the size of the string.
*/  

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int countSubstring(string const& s){
		int n = s.size();
		const int p = 31; // prime number
		const int m = 1e9 + 9; // modulo number
		vector<long long> p_pow(n);
		p_pow[0] = 1;
		for(int i = 1; i < n; ++i){
			p_pow[i] = (p_pow[i-1]*p)%m;
		}
		vector<long long> h(n+1,0);
		for(int i = 0; i < n; ++i){
			h[i+1] = (h[i] + (s[i]-'a'+1)*p_pow[i])%m;
		}
		int cnt = 0;
		for(int l = 1; l <= n; ++l){
			unordered_set<long long> hs;
			for(int i = 0; i <= n-l; ++i){
				long long cur_h = (h[i+l]+m-h[i])%m;
				cur_h = (cur_h*p_pow[n-i-1])%m;
				hs.insert(cur_h);
			}
			cnt+=hs.size();
		}
		return cnt;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	cout << Solution::countSubstring(s) << "\n";
	return 0;
}
