/* Rabin-Karp algorithm for string matching

O(|s|+|t|) time complexity, where s is a pattern and t is a text */

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<int> rabinKarp(string const& s, string const& t){
		const int p = 31; // we consider english lowercase character only
		const int m = 1e9+9;
		int S = s.size(), T = t.size();
		
		vector<long long> p_pow(max(S,T));
		p_pow[0] = 1;
		for(int i = 1; i < T; ++i){
			 p_pow[i] = (p_pow[i-1] * p) % m;
		}
		
		vector<long long> h(T + 1, 0); 
		for (int i = 0; i < T; i++){
			h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
		}
		long long h_s = 0;
		for(int i = 0; i < S; ++i){
			h_s = (h_s + (s[i] - 'a' + 1)*p_pow[i]) % m;
		}
		
		vector<int> occurences;
		for(int i = 0; i+S-1 < T; ++i){
			long long cur_h = (h[i+S] + m - h[i]) % m;
			if(cur_h == h_s*p_pow[i] % m){
				occurences.push_back(i);
			}
		}
		return occurences; 
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	string t; cin >> t;
	for(auto &x : Solution::rabinKarp(s,t))
		cout << x << " ";
	return 0;
}
