/*  SPOJ Pattern finding using Rabin-Karp algorithm - O(|s|+|t|) time complexity

	Index start with 1  */


#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static void rabin_karp(string s, string t){
		const int p = 53;
		const int mod = 1e9 + 7;
		int m = s.size(), n = t.size();
		int count = 0;

		vector<long long> p_pow(max(m,n));
		p_pow[0]=1;
		for(auto i = 1; i < (int)p_pow.size(); i++)
			p_pow[i]=(p_pow[i-1]*p)%mod;

		vector<long long> h(n+1,0);
		for(auto i = 0; i < n; i++)
			h[i+1]=(h[i]+(t[i]-'a'+1)*p_pow[i])%mod;
		long long h_s = 0;
		for(auto i = 0; i < m; i++)
			h_s = (h_s+(s[i]-'a'+1)*p_pow[i])%mod;

		vector<int> occur;
		for(auto i = 0; i+m-1 < n; i++){
			long long cur_h = (h[i+m]+mod-h[i])%mod;
			if(cur_h == h_s*p_pow[i]%mod){
				occur.emplace_back(i+1);
				count++;
			}
		}
		if(!occur.empty()){
			cout << count << endl;
			for(auto &x : occur)
				cout << x << " ";
			cout << endl;
		}
		else
			cout << "Not found" << endl;
		return;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	string t;
	cin >> s; cin >> t;
	if(s.length() <= t.length())
		Solution::rabin_karp(s,t);
	else
		Solution::rabin_karp(t,s);
	return 0;
}
