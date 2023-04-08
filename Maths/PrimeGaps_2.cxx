/* Given an integer g >= 2, an integer m > 2 and an integer n >= m;
 * return the first pair of prime numbers between m and n, that has a gap of size g.
 * If there is no such prime numbers, return null.
 * 
 * Time complexity: O((N-M)log(log(N-M))) + O(K²), where K is the number of prime numbers between m and n.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<pair<int,int>> gap(int g, int m, int n){
		vector<int> primes;
		deque<bool> is_prime(n+1,true);
		is_prime[0] = is_prime[1] = false;
		
		for(auto p(m); p <= n; ++p){
			if(is_prime[p]){
				primes.emplace_back(p);
			}
			for(auto j(p); j <= n; j+=p){
				is_prime[j] = false;
			}
		}
		vector<pair<int,int>> res;
		for(auto i(0); i < primes.size(); ++i){
			for(auto j(i+1); j < primes.size(); ++j){
				if(primes[j]-primes[i]==g){
					res.emplace_back(primes[i],primes[j]);
					return res;
				}
			}
		}
		return {{0,0}};
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	int g,m,n;
	cin >> g >> m >> n;
	for(auto &x : Solution::gap(g,m,n)){
		cout << x.first << " " << x.second << "\n";
	}
	return 0;
}
		
